//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__CONDITIONPARSER_H_
#define EX3__CONDITIONPARSER_H_
#include "Var.h"
class ConditionParser : public Command {
 private:
  string first_var;
  string second_var;
  string condition;
 protected:
  queue<string> condition_commands;
  bool is_condition = false;
  Singleton *singleton = Singleton::getSingleton();
 public:
  ConditionParser(){};
  virtual void execute(queue<string> &token);
  void checkAndUpdateIsCondition();
  virtual ~ConditionParser();
};
#endif //EX3__CONDITIONPARSER_H_
