//
// Created by shiraz on 12.12.2019.
//
#ifndef ex3__OPENDATASERVER_CPP_
#define ex3__OPENDATASERVER_CPP_
#include "Command.h"
class OpenServerCommand : public Command{
  virtual void execute(queue<string> &token, unordered_map<string, Command*> &commands) {
    cout<<"I am executing in Open Data Server"<<endl;
    //name of command
    token.pop();
    //parameter of command
    token.pop();
  }
};
#endif