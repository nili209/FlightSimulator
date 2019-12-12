//
// Created by shiraz on 12.12.2019.
//
#ifndef ex3__LOOPCOMMAND_CPP_
#define ex3__LOOPCOMMAND_CPP_
#include "ConditionParser.cpp"
class LoopCommand : public ConditionParser {
  virtual void execute(queue<string> &token, unordered_map<string, Command*> &commands) {
    cout<<"I am executing in Loop Command"<<endl;
    //initialize the queue of commands and check condition
    ConditionParser::execute(token, commands);
    while (condition) {
      int i = 0;
      queue<string> copy_queue = condition_commands;
      while(!copy_queue.empty()) {
        i++;
        string current = copy_queue.front();
        Command *c = commands.at(current);
        if(c != NULL) {
          c->execute(copy_queue, commands);
        }
      }
      ConditionParser::execute(token, commands);
    }
  }

};
#endif
