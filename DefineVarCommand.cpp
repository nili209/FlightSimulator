//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__DEFINEVARCOMMAND_CPP_
#define ex3__DEFINEVARCOMMAND_CPP_
#include "Command.h"
#include "Var.cpp"
#include "Singleton.h"
class DefineVarCommand : public Command {
 private:
  Singleton *singleton = Singleton::getSingleton();
 public:
  virtual void execute(queue<string> &token) {
    cout << "I am executing in Define Var Command" << endl;
    float num;
    //the word var
    token.pop();
    string var_name = token.front();
    //the name of the var
    token.pop();
    string action = token.front();
    //the action is =
    if (action.compare("=") == 0) {
      //pop =
      token.pop();
      //pop the var or value after the =
      string other_var_name = token.front();
      token.pop();
      num = ex1::cal(other_var_name, *singleton->getVarValues());
      Var *v = new Var("", "", var_name);
      mutex_lock.lock();
      //v->setName(var_name);
      singleton->updateVarValues(var_name, num);
      mutex_lock.unlock();
      v->setValue(num);
      mutex_lock.lock();
      singleton->updateSymbolTableProgram(var_name, v);
      mutex_lock.unlock();
    } else {
      //direction
      token.pop();
      //the word sim
      token.pop();
      string sim = token.front();
      //the name of the var of the simulator
      token.pop();
      //we didnot found the var in the map
      if (!insert_to_map(sim, var_name, action)) {
        string tempSim = sim.substr(1, sim.length() -2);
        Var *var = new Var(tempSim, action, var_name);
        mutex_lock.lock();
        //var->setName(var_name);
        singleton->updateSymbolTableProgram(var_name, var);
        singleton->updateVarValues(var_name, var->getValue());
        singleton->insertToCommands(var_name, var);
        mutex_lock.unlock();
      }
    }
  }
  bool insert_to_map(string sim, string var_name, string action) {
  string copySim = "";
    unordered_map<string, Command *> map = *singleton->getSymbolTableSimulator();
    for (auto it = map.begin(); it != map.end(); ++it) {
      Var *v = (Var*) it->second;
      string other_sim = v->getSim();
      copySim = sim.substr(1, sim.length() -2);
      //we found the var
      if (copySim.compare(other_sim) == 0) {
        mutex_lock.lock();
        v->setDirection(action);
        v->setSim(other_sim);
        v->setName(var_name);
        singleton->updateSymbolTableProgram(var_name, v);
        singleton->updateVarValues(var_name, v->getValue());
        singleton->insertToCommands(var_name, v);
        mutex_lock.unlock();
        return true;
      }
    }
    return false;
  }
  virtual ~DefineVarCommand(){};
};
#endif
