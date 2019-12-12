//
// Created by shiraz on 12.12.2019.
//
#ifndef ex3__CONDITIONPARSER_CPP_
#define ex3__CONDITIONPARSER_CPP_
#include "Command.h"
class ConditionParser : public Command {
 public:
  string first_var;
  string second_var;
  string con;
  queue<string> condition_commands;
  bool condition = false;
  ConditionParser() {
  }
  virtual void execute(queue<string> &token, unordered_map<string, Command*> &commands) {
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
      while(com.compare("}") != 0) {
        condition_commands.push(com);
        token.pop();
        com = token.front();
      }
    }
    //'}'
    token.pop();
    cout<<"I am executing in Condition Parser"<<endl;
    if(con.compare("==") == 0) {

    }
    if(con.compare("!=") == 0) {

    }
    if(con.compare(">=") == 0) {

    }
    if(con.compare("<=") == 0) {

    }
    if(con.compare(">") == 0) {

    }
    if(con.compare("<") == 0) {

    }

  }
};
#endif