//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__VAR_CPP_
#define ex3__VAR_CPP_
#include "Command.h"
#include "Singleton.h"
#include "ex1.h"

class Var : public Command {
 private:
  Singleton* singleton = Singleton::getSingleton();
  string sim, direction, name;
  float value;
 public:
  void setDirection(string direct) {
    this->direction = direct;
  }
  string getDirection() {
    return direction;
  }
  string getName() {
    return this->name;
  }
  string getSim() {
    return this->sim;
  }
  float getValue() {
    return this->value;
  }
  void printSimulatorVar() {
    for (auto& it: singleton->symbol_table_simulator) {
      Var *v = (Var*)it.second;
      cout << it.first<< "=" << v->getValue()<<endl;
    }
  }
  void setName(string name1) {
    this->name = name;
  }
  void setValue(float num) {
    mutex_lock.lock();
    this->value = num;
    singleton->var_values.at(name) = num;
    mutex_lock.unlock();
  }
  void setSim(string sim1) {
    this->sim = sim1;
  }
  Var(string sim1, string direction1, string name1) : sim(sim1), direction(direction1), name(name1){};
  virtual void execute(queue<string> &token) {
    cout<<"I am executing in Var"<<endl;
    //name of var
    string var_name = token.front();
    token.pop();
    //"="
    token.pop();
    string expression = token.front();
    Command* other_var = NULL;
    float value1 = ex1::cal(expression, singleton->var_values);
    setValue(value1);

    //shunting yard return value of expression = value
    //simulator needed to be changed
    string tempSim = sim;
    mutex_lock.lock();
  if (direction.compare("->") == 0 ) {
    if(sim[0] == '"') {
      tempSim = sim.substr(1, sim.length() - 2);
      if (tempSim[0] == '/') {
        tempSim = tempSim.substr(1, tempSim.length() - 1);
      }
    } else if (tempSim[0] == '/') {
      tempSim = tempSim.substr(1, tempSim.length() - 1);
    }
    mutex_lock.unlock();
    string message = "set " + tempSim+ " " + to_string(value) + "\r\n";
    singleton->setMessages(message);
 }
    token.pop();
  }
};
#endif