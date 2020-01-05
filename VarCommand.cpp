//
// Created by shiraz and nili on 12.12.2019.
//
#include "VarCommand.h"
/*
* The function updates the symbol table of the program.
*/
 void VarCommand::updateSymbolTableProg(string sim, float value) {
  string otherSim = "";
  Singleton *singelton1 = Singleton::getSingleton();
  singelton1->mutex_lock.lock();
  for (auto &it: *singelton1->getSymbolTableProgram()) {
    VarCommand *v = (VarCommand *) it.second;
    otherSim = v->getSim();
    if (sim.compare(otherSim) == 0) {
      string name = it.first;
      singelton1->updateVarValues(name, value);
      break;
    }
  }
  singelton1->mutex_lock.unlock();
}
/*
* The function sets the direction.
*/
void VarCommand::setDirection(string direct) {
  this->direction = direct;
}
/*
* The function returns the direction.
*/
string VarCommand::getDirection() {
  return direction;
}
/*
* The function returns the sim.
*/
string VarCommand::getSim() {
  return this->sim;
}
/*
* The function sets the sim.
*/
void VarCommand::setSim(string sim1) {
  this->sim = sim1;
}
/*
* The function returns the value.
*/
float VarCommand::getValue() {
  return this->value;
}
/*
* The function sets the name.
*/
void VarCommand::setName(string name1) {
  this->name = name1;
}
/*
* The function sets the value.
*/
void VarCommand::setValue(float num) {
  singleton->mutex_lock.lock();
  this->value = num;
  singleton->updateVarValues(name, num);
  singleton->mutex_lock.unlock();
  updateSymbolTableProg(sim, num);
}
/*
* The function updates the value of the var and adds a message if needed.
*/
void VarCommand::execute(queue<string> &token) {
  //name of var
  string var_name = token.front();
  token.pop();
  //"="
  token.pop();
  string expression = token.front();
  float value1 = ShuntingYard::calculator(expression, *singleton->getVarValues());
  setValue(value1);
  //simulator needed to be changed
  string tempSim = sim;
  singleton->mutex_lock.lock();
  if (direction.compare("->") == 0) {
    if (sim[0] == '"') {
      tempSim = sim.substr(1, sim.length() - 2);
      if (tempSim[0] == '/') {
        tempSim = tempSim.substr(1, tempSim.length() - 1);
      }
    } else if (tempSim[0] == '/') {
      tempSim = tempSim.substr(1, tempSim.length() - 1);
    }
    string message = "set " + tempSim + " " + to_string(value) + "\r\n";
    singleton->setMessages(message);
    singleton->mutex_lock.unlock();
  }
  token.pop();
}
/*
* Destructor.
*/
VarCommand::~VarCommand() {}


