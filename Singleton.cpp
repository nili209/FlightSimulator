//
// Created by shiraz on 25.12.2019.
//
#include "Singleton.h"
mutex Singleton::mutex_lock;
Singleton* Singleton::instance = 0;
queue<string> Singleton::messages;
unordered_map<string, Command *> Singleton::commands;
unordered_map<string, Command *> Singleton::symbol_table_program;
unordered_map<string, Command *> Singleton::symbol_table_simulator;
unordered_map<string, float> Singleton::var_values;
unordered_map<int, string> Singleton::index;
void Singleton::reset(unordered_map<string, Command *> &map, unordered_map<int, string> &index_map,
                  unordered_map<string, float> &var_value1) {
  symbol_table_simulator = map;
  index = index_map;
  var_values = var_value1;
}
Singleton* Singleton::getSingleton() {
  if (instance == 0) {
    instance = new Singleton();
  }
  return instance;
}
string Singleton::getMessage() {
  string message = Singleton::messages.front();
  Singleton::messages.pop();
  return message;
}
void Singleton::setMessages(string str) {
  Singleton::messages.push(str);
}
bool Singleton::isMessagesEmpty() {
  if (messages.empty()) {
    return true;
  }
  return false;
}
unordered_map<string, Command *> *Singleton::getCommands() {
  return &commands;
}
unordered_map<string, float> *Singleton::getVarValues() {
  return &var_values;
}
unordered_map<string, Command *> *Singleton::getSymbolTableProgram() {
  return &symbol_table_program;
}
unordered_map<string, Command *> *Singleton::getSymbolTableSimulator() {
  return &symbol_table_simulator;
}
unordered_map<int, string> *Singleton::getIndex() {
  return &index;
}
void Singleton::updateSymbolTableProgram(string name, Command *command) {
  symbol_table_program[name] = command;
}
void Singleton::updateVarValues(string var_name, float value) {
  var_values[var_name] = value;
}
void Singleton::insertToCommands(string name_of_command, Command *command) {
  commands.insert({name_of_command, command});
}
Singleton::~Singleton() {
  unordered_map<string, Command *>::iterator it;
  for (auto &iter: symbol_table_simulator) {
    delete iter.second;
  }
  for (auto &iter: symbol_table_program) {
    delete iter.second;
  }
}
