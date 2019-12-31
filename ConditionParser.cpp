//
// Created by shiraz and nili on 12.12.2019.
//
#include "ConditionParser.h"
/*
* The function initializes the fields first_var, condition and second_var if needed and checks the condition.
*/
void ConditionParser::execute(queue<string> &token) {
  if (token.front().compare(LOOP) == 0 || token.front().compare(IF) == 0) {
    //initialize the queue of commands
    //pop if/while
    token.pop();
    first_var = token.front();
    token.pop();
    condition = token.front();
    token.pop();
    second_var = token.front();
    token.pop();
    //pop {
    token.pop();
    string command = token.front();
    //initialize the commands conditions
    queue<string> temp_condition_commands;
    condition_commands = temp_condition_commands;
    while (command.compare("}") != 0) {
      condition_commands.push(command);
      token.pop();
      command = token.front();
    }
    //'}'
    token.pop();
  }
  checkAndUpdateIsCondition();
}
/*
* The function checks the condition and updates is_condition.
*/
void ConditionParser::checkAndUpdateIsCondition() {
  float value1 = ex1::cal(first_var, *singleton->getVarValues()),
      value2 = ex1::cal(second_var, *singleton->getVarValues());
  if (condition.compare("==") == 0) {
    is_condition = (value1 == value2);
  }
  if (condition.compare("!=") == 0) {
    is_condition = (value1 != value2);
  }
  if (condition.compare(">=") == 0) {
    is_condition = (value1 >= value2);
  }
  if (condition.compare("<=") == 0) {
    is_condition = (value1 <= value2);
  }
  if (condition.compare(">") == 0) {
    is_condition = (value1 > value2);
  }
  if (condition.compare("<") == 0) {
    is_condition = (value1 < value2);
  }
}
/*
* Destructor.
*/
ConditionParser:: ~ConditionParser() {}