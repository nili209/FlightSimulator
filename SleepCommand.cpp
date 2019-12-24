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
  virtual void execute(queue<string> &token) {
    cout<<"I am executing in Sleep Command"<<endl;
    //the word "Sleep"
    token.pop();
    Singleton* singleton = Singleton::getSingleton();
    int time_to_sleep = ex1::cal(token.front().c_str(), *singleton->getVarValues());
    this_thread::sleep_for(chrono::milliseconds(time_to_sleep));
    //time to sleep
    token.pop();
  }
  virtual ~SleepCommand(){};
};
#endif
