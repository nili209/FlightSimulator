//
// Created by shiraz and nili on 12.12.2019.
//

#include "IfCommand.h"
/*
* The function execute the condition commands if the condition is valid.
*/
void IfCommand::execute(queue<string> &token) {
  //initialize the queue of commands and check condition
  ConditionParser::execute(token);
  if (is_condition) {
    int i = 0;
    while (!condition_commands.empty()) {
      i++;
      //the name of the command or var
      string current = condition_commands.front();
      Command *c = singleton->getCommands()->at(current);
      if (c != NULL) {
        c->execute(condition_commands);
      }
    }
  }
}
/*
* Destructor.
*/
IfCommand::~IfCommand(){}
