//
// Created by shiraz and nili on 12.12.2019.
//
#include "LoopCommand.h"
/*
* The function execute the condition commands while the condition is valid.
*/
void LoopCommand::execute(queue<string> &token) {
  //initialize the queue of commands and check condition
  ConditionParser::execute(token);
  int j = 0;
  while (is_condition) {
    j++;
    int i = 0;
    queue<string> copy_queue = condition_commands;
    while (!copy_queue.empty()) {
      i++;
      //the name of command or var
      string current = copy_queue.front();
      Command *c = singleton->getCommands()->at(current);
      if (c != NULL) {
        c->execute(copy_queue);
      }
    }
    //check the condition state
    ConditionParser::execute(token);
  }
}
/*
* Destructor.
*/
LoopCommand::~LoopCommand() {}
