//
// Created by shiraz on 12.12.2019.
//
#ifndef ex3__IFCOMMAND_CPP_
#define ex3__IFCOMMAND_CPP_
#include "ConditionParser.cpp"
class IfCommand : public ConditionParser {
  virtual void execute(queue<string> &token, unordered_map<string, Command*> &commands) {
    cout<<"I am executing in If Command"<<endl;
    //initialize the queue of commands and check condition
    ConditionParser::execute(token, commands);
    if (condition) {
      int i = 0;
      while(!condition_commands.empty()) {
        i++;
        string current = condition_commands.front();
        Command *c = commands.at(current);
        if(c != NULL) {
          c->execute(condition_commands, commands);
        }
      }
    }
  }
};
#endif
