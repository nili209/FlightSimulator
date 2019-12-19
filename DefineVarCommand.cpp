//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__DEFINEVARCOMMAND_CPP_
#define ex3__DEFINEVARCOMMAND_CPP_
#include "Command.h"
#include "Var.cpp"
#include "Singleton.h"
class DefineVarCommand : public Command {
 public:
  Singleton *singleton = Singleton::getSingleton();
  virtual void execute(queue<string> &token) {
    bool is_digit = false;
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
      float num;
      is_digit = false;
      try {
        singleton->symbol_table_program.at(other_var_name);
        //this is a number or expression
      } catch (exception e){
        num = atof(other_var_name.c_str());
        is_digit = true;
      }
      //if after the = is a number or expression
      if (is_digit) {
        Var *v = new Var("", "", var_name);
        singleton->var_values.insert({var_name, num});
        v->setValue(num);
        singleton->symbol_table_program.insert({var_name, v});
      } else {
        //if after the = is a var:
        //update the value to be the value of other var
        Var *v1 = new Var("", "", var_name);
        Var *other = (Var*)singleton->symbol_table_program.at(other_var_name);
        singleton->var_values.insert({var_name, other->getValue()});
        v1->setValue(other->getValue());
        singleton->symbol_table_program.insert({var_name, v1});
      }
      //the action is direction
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
        Var *var = new Var(sim, action, var_name);
        singleton->symbol_table_program.insert({var_name, var});
        singleton->var_values.insert({var_name, var->getValue()});
        singleton->commands.insert({var_name, var});
      }
    }
    cout << "I am executing in Define Var Command" << endl;
  }
  bool insert_to_map(string sim, string var_name, string action) {
    unordered_map<string, Command *> map = singleton->symbol_table_simulator;
    for (auto it = map.begin(); it != map.end(); ++it) {
      Var *v = (Var*) it->second;
      string other_sim = v->getSim();
      //we found the var
      if (sim.compare(other_sim) == 0) {
        v->setDirection(action);
        singleton->symbol_table_program.insert({var_name, v});
        singleton->var_values.insert({var_name, v->getValue()});
        return true;
      }
    }
    return false;
  }
};
#endif
