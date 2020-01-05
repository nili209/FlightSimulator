//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__LOOPCOMMAND_H_
#define EX3__LOOPCOMMAND_H_
#include "ConditionParser.h"
class LoopCommand : public ConditionParser {
 public:
  LoopCommand(){};
  virtual void execute(queue<string> &token);
  virtual ~LoopCommand();
};
#endif //EX3__LOOPCOMMAND_H_
