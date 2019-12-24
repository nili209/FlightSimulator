//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__PRINTCOMMAND_CPP
#define ex3__PRINTCOMMAND_CPP
#include "Command.h"
#include "Var.cpp"
#include "Singleton.h"
class PrintCommand : public Command {
 public:
  Singleton* singleton = Singleton::getSingleton();
  virtual void execute(queue<string> &token) {
    string printer;
    float value;
    cout<<"I am executing in Print Command"<<endl;
    //the word "print"
    token.pop();
    //if the message is a string - need to dispose the " "
    if (token.front()[0] == '"') {
      printer = token.front().substr(1, token.front().size() - 2);
      cout<<printer<<endl;
      //is not a string with " "
    } else {
      value = ex1::cal(token.front(), *singleton->getVarValues());
      cout<<value<<endl;
    }
    //the message
    token.pop();
  }
  virtual ~PrintCommand(){};
};
#endif
