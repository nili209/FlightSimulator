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
  string getSim() {
    return this->sim;
  }
  Singleton* singleton = Singleton::getSingleton();
  float getValue() {
    return this->value;
  }
  void setValue(float num) {
    this->value = num;
  }
  Var(string sim1, string direction1) : sim(sim1), direction(direction1){};
  virtual void execute(queue<string> &token) {
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
        this->value = value1;
    }
      //this is a var
    else {
      Var *var = (Var*)other_var;
      float value = var->getValue();
      Var *current_var = (Var*)singleton->symbol_table_program.at(var_name);
      current_var->value = value;
    }
    //shunting yard return value of expression = value
    //simulator needed to be changed
//  if (direction.compare("->") == 0 ) {
//    string message = "set " + path+ " " + to_string(value) + "\r\n";
//    ssize_t return_val;
//    // Send message to the server
//    returl_val = write(sockfd, message.c_str(), message.length());
//
//    //go to the symbol table of simulator and change the value;
//    //"set /controls/engines/current-engine/throttle 1”
// }
    token.pop();
  }
};
#endif