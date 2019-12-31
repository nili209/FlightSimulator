//
// Created by shiraz and nili on 12.12.2019.
//
#include "SleepCommand.h"
/*
* The function makes the current thread to sleep.
*/
void SleepCommand::execute(queue<string> &token) {
  //the word "Sleep"
  token.pop();
  Singleton *singleton = Singleton::getSingleton();
  int time_to_sleep = ex1::cal(token.front().c_str(), *singleton->getVarValues());
  this_thread::sleep_for(chrono::milliseconds(time_to_sleep));
  //time to sleep
  token.pop();
}
/*
* Destructor.
*/
SleepCommand::~SleepCommand() {}

