//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__IFCOMMAND_H_
#define EX3__IFCOMMAND_H_
#include "ConditionParser.h"
class IfCommand : public ConditionParser {
 public:
  IfCommand(){};
  virtual void execute(queue<string> &token);
  virtual ~IfCommand();
};
#endif //EX3__IFCOMMAND_H_
