//
// Created by shiraz on 12.12.2019.
//
#ifndef ex3__PRINTCOMMAND_CPP
#define ex3__PRINTCOMMAND_CPP
#include "Command.h"
class PrintCommand : public Command {
  virtual void execute(queue<string> &token, unordered_map<string, Command*> &commands) {
    cout<<"I am executing in Print Command"<<endl;
    //the word "print"
    token.pop();
    string printer;
    if (token.front()[0] == '"') {
      printer = token.front().substr(1, token.front().size() - 2);
    } else {
      printer = token.front();
    }
    cout<<printer<<endl;
    //the message
    token.pop();
  }
};
#endif
