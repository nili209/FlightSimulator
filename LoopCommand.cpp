//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__LOOPCOMMAND_CPP_
#define ex3__LOOPCOMMAND_CPP_
#include "ConditionParser.cpp"
class LoopCommand : public ConditionParser {
 public:
  virtual void execute(queue<string> &token) {
    cout<<"I am executing in Loop Command"<<endl;
    //initialize the queue of commands and check condition
    ConditionParser::execute(token);
    int j = 0;
    while (is_condition) {
      j++;
      int i = 0;
      queue<string> copy_queue = condition_commands;
      while(!copy_queue.empty()) {
        i++;
        //the name of command or var
        string current = copy_queue.front();
        Command *c = singleton->commands.at(current);
        if(c != NULL) {
          c->execute(copy_queue);
        }
      }
      //check the condition state
      ConditionParser::execute(token);
    }
  }

};
#endif
