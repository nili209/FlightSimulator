//
// Created by shiraz on 12.12.2019.
//
#ifndef ex3__DEFINEVARCOMMAND_CPP_
#define ex3__DEFINEVARCOMMAND_CPP_
#include "Command.h"
#include "Var.cpp"
class DefineVarCommand : public Command {
  virtual void execute(queue<string> &token, unordered_map<string, Command*> &commands) {
    //the word var
    token.pop();
    string var_name = token.front();
    //the name of the var
    token.pop();
    string action = token.front();
    //the actinon is =
    if (action.compare("=") == 0) {
      //pop =
      token.pop();
      //pop the var or value after the =
      token.pop();
      //if after the = is a var:
      //insert var_name and the var that comes after the = to commands
      //else - if after the = is a value:
      //just update the value of the curren var

      //the action is direction
    } else {
      //direction or =
      token.pop();
      //the word sim
      token.pop();
      string sim = token.front();
      token.pop();
      Var *var = new Var(sim, action);
      commands.insert({var_name, var});
    }
   cout<<"I am executing in Define Var Command"<<endl;
  }
};
#endif
