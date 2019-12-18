//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__CONDITIONPARSER_CPP_
#define ex3__CONDITIONPARSER_CPP_
#include "Command.h"
#include "Var.cpp"
#include "Singleton.h"

class ConditionParser : public Command {
 public:
  string first_var;
  string second_var;
  string con;
  queue<string> condition_commands;
  bool condition = false;
  Singleton* singleton = Singleton::getSingleton();
  virtual void execute(queue<string> &token) {
    if (token.front().compare(LOOP) == 0 || token.front().compare(IF) == 0) {
      //initialize the queue of commands
      //pop if/while
      token.pop();
      first_var = token.front();
      cout<<first_var<<endl;
      token.pop();
      con = token.front();
      cout<<con<<endl;
      token.pop();
      second_var = token.front();
      cout<<second_var<<endl;
      token.pop();
      //pop {
      token.pop();
      string com = token.front();
      //initialize the commands conditions
      queue<string> temp;
      condition_commands = temp;
      while(com.compare("}") != 0) {
        condition_commands.push(com);
        token.pop();
        com = token.front();
      }
      //'}'
      token.pop();
    }

    cout<<"I am executing in Condition Parser"<<endl;
    float value1 = ex1::cal(first_var, singleton->var_values), value2 = ex1::cal(second_var, singleton->var_values);
//    try{
//        value1 = ((Var*)singleton->symbol_table_program.at(first_var))->getValue();
//    } catch (exception e) {
//      value1 = atof(first_var.c_str());
//    }
//    try{
//      value2 = ((Var*)singleton->symbol_table_program.at(second_var))->getValue();
//    } catch (exception e) {
//      value2 = atof(second_var.c_str());
//    }
    if(con.compare("==") == 0) {
      condition = (value1 == value2);
    }
    if(con.compare("!=") == 0) {
      condition = (value1 != value2);
    }
    if(con.compare(">=") == 0) {
      condition = (value1 >= value2);
    }
    if(con.compare("<=") == 0) {
      condition = (value1 <= value2);
    }
    if(con.compare(">") == 0) {
      condition = (value1 > value2);
    }
    if(con.compare("<") == 0) {
      condition = (value1 < value2);
    }

  }
};
#endif