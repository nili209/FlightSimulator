//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__CONNECTCOMANND_CPP_
#define ex3__CONNECTCOMANND_CPP_
#include "Command.h"

class ConnectCommand : public Command {
  virtual void execute(queue<string> &token, unordered_map<string, Command*> &commands) {
    cout<<"I am executing in Connect Control Command"<<endl;
    //name of command
    token.pop();
    //ip
    token.pop();
    //port
    token.pop();
  }
};

#endif