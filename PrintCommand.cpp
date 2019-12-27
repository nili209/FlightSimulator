//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef EX3__PRINTCOMMAND_H_
#define EX3__PRINTCOMMAND_H_
#include "Command.h"
#include "Singleton.h"
#include "ex1.h"
class PrintCommand : public Command {
 public:
  PrintCommand(){};
  Singleton *singleton = Singleton::getSingleton();
  virtual void execute(queue<string> &token) {
    string printer;
    float value;
    //the word "print"
    token.pop();
    //if the message is a string - need to dispose the " "
    if (token.front()[0] == '"') {
      printer = token.front().substr(1, token.front().size() - 2);
      cout << printer << endl;
      //is not a string with " "
    } else {
      value = ex1::cal(token.front(), *singleton->getVarValues());
      cout << value << endl;
    }
    //the message
    token.pop();
  }
  virtual ~PrintCommand(){};
};
#endif //EX3__PRINTCOMMAND_H_PrintCommand::PrintCommand() {}

