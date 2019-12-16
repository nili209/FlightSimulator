//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__VAR_CPP_
#define ex3__VAR_CPP_
#include "Command.h"
#include "Singleton.h"
class Var : public Command {
 private:
  string sim, direction;
  float value = 0;
 public:
  Singleton* singleton = Singleton::getSingleton();
  unordered_map<string, Var *> symbol_table_program;
  float getValue() {
    return this->value;
  }
  Var(string sim1, string direction1) : sim(sim1), direction(direction1){};
  virtual void execute(queue<string> &token, unordered_map<string, Command*> &commands, unordered_map<string, Command *> &symbol_table_program) {
    cout<<"I am executing in Var"<<endl;
    //name of var
    string var_name = token.front();
    token.pop();
    //"="
    token.pop();
    string expression = token.front();
    Command* other_var = NULL;
    float value1;
    //for now, the expression will be only a var name or a number
    try{
      other_var = singleton->symbol_table_program.at(expression);
    } catch (exception e) {
      value1 = atof(expression.c_str());
    }
    //this is a value
    if (other_var == NULL) {
      if (direction.compare("->") == 0 ) {
        this->value = value1;
        //go to the symbol table of simulator and change the value;
        //"set /controls/engines/current-engine/throttle 1”
      }
      //this is a var
    } else {
      symbol_table_program.at(var_name) = other_var;
      singleton->symbol_table_program.at(var_name) = other_var;
    }
    //shunting yard return value of expression = value
    //simulator needed to be changed

    //value
//    //it was a specific case that in the lexer it inserted a space with no reason
//    if (token.front().compare("") == 0) {
//      token.pop();
//    }
    token.pop();
  }
};
#endif