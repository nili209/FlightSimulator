//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__SLEEPCOMMAND_CPP_
#define ex3__SLEEPCOMMAND_CPP_
#include "Command.h"
#include <thread>
#include <chrono>
#include "Var.cpp"
class SleepCommand : public Command {
  virtual void execute(queue<string> &token, unordered_map<string, Command*> &commands, unordered_map<string, Command *> &symbol_table_program) {
    cout<<"I am executing in Sleep Command"<<endl;
    //the word "Sleep"
    token.pop();
    //time to sleep
    int time_to_sleep = atof(token.front().c_str());
    //sleep
    this_thread::sleep_for(chrono::milliseconds(time_to_sleep));
    //time to sleep
    token.pop();
  }
};
#endif
