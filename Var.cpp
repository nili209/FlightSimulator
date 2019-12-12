//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__VAR_CPP_
#define ex3__VAR_CPP_
#include "Command.h"
class Var : public Command {
 private:
  string sim, direction;
  float value = 0;
 public:
  Var(string sim1, string direction1) : sim(sim1), direction(direction1){};
  virtual void execute(queue<string> &token, unordered_map<string, Command*> &commands) {
    cout<<"I am executing in Var"<<endl;
    //name of var
    token.pop();
    //"="
    token.pop();
    //shunting yard return value of expression = value
    //simulator needed to be changed
    if (direction.compare("->") == 0 ) {
      //go to the symbol table of simulator and change the value;
    }
    //value
    //it was a specific case that in the lexer it inserted a space with no reason
    if (token.front().compare("") == 0) {
      token.pop();
    }
    token.pop();
  }
};
#endif