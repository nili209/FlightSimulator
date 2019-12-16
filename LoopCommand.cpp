//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__LOOPCOMMAND_CPP_
#define ex3__LOOPCOMMAND_CPP_
#include "ConditionParser.cpp"
class LoopCommand : public ConditionParser {
 public:
  Singleton* singleton = Singleton::getSingleton();
  virtual void execute(queue<string> &token, unordered_map<string, Command*> &commands, unordered_map<string, Command *> &symbol_table_program) {
    cout<<"I am executing in Loop Command"<<endl;
    //initialize the queue of commands and check condition
    ConditionParser::execute(token, commands, symbol_table_program);
    int j = 0;
    while (condition) {
      j++;
      int i = 0;
      queue<string> copy_queue = condition_commands;
      while(!copy_queue.empty()) {
        i++;
        //the name of command or var
        string current = copy_queue.front();
        Command *c = singleton->commands.at(current);
        if(c != NULL) {
          c->execute(copy_queue, commands, symbol_table_program);
        }
      }
      //check the condition state
      ConditionParser::execute(token, commands, symbol_table_program);
    }
  }

};
#endif
