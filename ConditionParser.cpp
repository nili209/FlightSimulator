//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__CONDITIONPARSER_CPP_
#define ex3__CONDITIONPARSER_CPP_
#include "Command.h"
#include "Var.cpp"
#include "Singleton.h"

class ConditionParser : public Command {
 private:
  string first_var;
  string second_var;
  string condition;
 protected:
  queue<string> condition_commands;
  bool is_condition = false;
  Singleton* singleton = Singleton::getSingleton();
 public:
  virtual void execute(queue<string> &token) {
    if (token.front().compare(LOOP) == 0 || token.front().compare(IF) == 0) {
      //initialize the queue of commands
      //pop if/while
      token.pop();
      first_var = token.front();
      cout<<first_var<<endl;
      token.pop();
      condition = token.front();
      cout<<condition<<endl;
      token.pop();
      second_var = token.front();
      cout<<second_var<<endl;
      token.pop();
      //pop {
      token.pop();
      string command = token.front();
      //initialize the commands conditions
      queue<string> temp_condition_commands;
      condition_commands = temp_condition_commands;
      while(command.compare("}") != 0) {
        condition_commands.push(command);
        token.pop();
        command = token.front();
      }
      //'}'
      token.pop();
    }
    cout<<"I am executing in Condition Parser"<<endl;
    checkAndUpdateIsCondition();
  }
  void checkAndUpdateIsCondition() {
    float value1 = ex1::cal(first_var, singleton->var_values),
    value2 = ex1::cal(second_var, singleton->var_values);
    if(condition.compare("==") == 0) {
      is_condition = (value1 == value2);
    }
    if(condition.compare("!=") == 0) {
      is_condition = (value1 != value2);
    }
    if(condition.compare(">=") == 0) {
      is_condition = (value1 >= value2);
    }
    if(condition.compare("<=") == 0) {
      is_condition = (value1 <= value2);
    }
    if(condition.compare(">") == 0) {
      is_condition = (value1 > value2);
    }
    if(condition.compare("<") == 0) {
      is_condition = (value1 < value2);
    }
  }
};
#endif