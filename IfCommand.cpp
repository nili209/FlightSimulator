//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__IFCOMMAND_CPP_
#define ex3__IFCOMMAND_CPP_
#include "ConditionParser.cpp"

class IfCommand : public ConditionParser {
 public:
  virtual void execute(queue<string> &token) {
    //initialize the queue of commands and check condition
    ConditionParser::execute(token);
    if (is_condition) {
      int i = 0;
      while(!condition_commands.empty()) {
        i++;
        //the name of the command or var
        string current = condition_commands.front();
        Command *c = singleton->getCommands()->at(current);
        if(c != NULL) {
          c->execute(condition_commands);
        }
      }
    }
  }
  virtual ~IfCommand(){};
};
#endif
