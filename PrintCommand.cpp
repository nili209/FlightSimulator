//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__PRINTCOMMAND_CPP
#define ex3__PRINTCOMMAND_CPP
#include "Command.h"
class PrintCommand : public Command {
  virtual void execute(queue<string> &token, unordered_map<string, Command*> &commands) {
    string printer;
    cout<<"I am executing in Print Command"<<endl;
    //the word "print"
    token.pop();
    //if the message is a string - need to dispose the " "
    if (token.front()[0] == '"') {
      printer = token.front().substr(1, token.front().size() - 2);
      //is not a string with " "
    } else {
      printer = token.front();
    }
    cout<<printer<<endl;
    //the message
    token.pop();
  }
};
#endif
