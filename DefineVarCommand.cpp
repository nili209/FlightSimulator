//
// Created by shiraz on 12.12.2019.
//
#ifndef ex3__DEFINEVARCOMMAND_CPP_
#define ex3__DEFINEVARCOMMAND_CPP_
#include "Command.h"
#include "Var.cpp"
class DefineVarCommand : public Command {
  virtual void execute(queue<string> &token, unordered_map<string, Command*> &commands) {
    token.pop();
    string var_name = token.front();
    token.pop();
    string direction = token.front();
    token.pop();
    token.pop();
    string sim = token.front();
    token.pop();
    Var *var = new Var(sim, direction);
    commands.insert({var_name, var});
   cout<<"I am executing in Define Var Command"<<endl;
  }
};
#endif
