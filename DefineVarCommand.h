//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__DEFINEVARCOMMAND_H_
#define EX3__DEFINEVARCOMMAND_H_
#include "Command.h"
#include "Var.h"
class DefineVarCommand : public Command {
 private:
  Singleton *singleton = Singleton::getSingleton();
 public:
  DefineVarCommand(){};
  virtual void execute(queue<string> &token);
  bool insert_to_map(string sim, string var_name, string action);
  virtual ~DefineVarCommand();
};
#endif //EX3__DEFINEVARCOMMAND_H_
