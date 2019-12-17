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
      try {
        singleton->symbol_table_program.at(other_var_name);
        //this is a number or expression
      } catch (exception e){
        num = atof(other_var_name.c_str());
        is_digit = true;
      }
      //if after the = is a number or expression
      if (is_digit) {
        Var *v = new Var("", "");
        v->setValue(num);
        singleton->symbol_table_program.insert({var_name, v});

      } else {
        //if after the = is a var:
        //insert var_name and the var that comes after the = to commands
        singleton->symbol_table_program.insert({var_name, singleton->symbol_table_program.at(other_var_name)});
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
      Var *var = new Var(sim, action);
      singleton->symbol_table_program.insert({var_name, var});
      singleton->commands.insert({var_name, var});
    }
    cout << "I am executing in Define Var Command" << endl;
  }
};
#endif
