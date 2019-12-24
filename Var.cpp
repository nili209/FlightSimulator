//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__VAR_CPP_
#define ex3__VAR_CPP_
#include "Command.h"
#include "Singleton.h"
#include "ex1.h"

class Var : public Command {
 private:
  Singleton* singleton = Singleton::getSingleton();
  string sim, direction, name;
  float value;
 public:
  static void updateSymbolTableProg( string sim, float value) {
    string otherSim = "";
    mutex_lock.lock();
    Singleton* singelton1 = Singleton::getSingleton();
    for (auto& it: *singelton1->getSymbolTableProgram()) {
      Var *v = (Var*)it.second;
      otherSim = v->getSim();
      if (sim.compare(otherSim) == 0) {
        string name = it.first;
        singelton1->updateVarValues(name, value);
        break;
      }
    }
    mutex_lock.unlock();
  }
  void setDirection(string direct) {
    this->direction = direct;
  }
  string getDirection() {
    return direction;
  }
  string getSim() {
    return this->sim;
  }
  void setSim(string sim1) {
    this->sim = sim1;
  }
  float getValue() {
    return this->value;
  }
  void setName(string name1) {
    this->name = name;
  }
  void setValue(float num) {
    mutex_lock.lock();
    this->value = num;
    singleton->updateVarValues(name, num);
    mutex_lock.unlock();
    updateSymbolTableProg(sim, num);
  }
  Var(string sim1, string direction1, string name1) : sim(sim1), direction(direction1), name(name1){};
  virtual void execute(queue<string> &token) {
    cout<<"I am executing in Var"<<endl;
    //name of var
    string var_name = token.front();
    token.pop();
    //"="
    token.pop();
    string expression = token.front();
    Command* other_var = NULL;
    float value1 = ex1::cal(expression, *singleton->getVarValues());
    setValue(value1);
    //simulator needed to be changed
    string tempSim = sim;
    mutex_lock.lock();
  if (direction.compare("->") == 0 ) {
    if(sim[0] == '"') {
      tempSim = sim.substr(1, sim.length() - 2);
      if (tempSim[0] == '/') {
        tempSim = tempSim.substr(1, tempSim.length() - 1);
      }
    } else if (tempSim[0] == '/') {
      tempSim = tempSim.substr(1, tempSim.length() - 1);
    }
    mutex_lock.unlock();
    string message = "set " + tempSim+ " " + to_string(value) + "\r\n";
    singleton->setMessages(message);
 }
    token.pop();
  }
  virtual ~Var(){};
};
#endif