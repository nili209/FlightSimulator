//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__PRINTCOMMAND_H_
#define EX3__PRINTCOMMAND_H_
#include "Command.h"
#include "Singleton.h"
#include "ShuntingYard.h"
class PrintCommand : public Command {
 private:
  Singleton* singleton = Singleton::getSingleton();
 public:
  PrintCommand(){};
  virtual void execute(queue<string> &token);
  virtual ~PrintCommand();
};
#endif //EX3__PRINTCOMMAND_H_
