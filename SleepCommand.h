//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__SLEEPCOMMAND_H_
#define EX3__SLEEPCOMMAND_H_
#include "Command.h"
#include <thread>
#include <chrono>
#include "Var.h"
class SleepCommand : public Command {
 public:
  SleepCommand(){};
  virtual void execute(queue<string> &token);
  virtual ~SleepCommand();
};
#endif //EX3__SLEEPCOMMAND_H_
