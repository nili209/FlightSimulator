//
// Created by shiraz and nili on 25.12.2019.
//
#include "Singleton.h"
mutex Singleton::mutex_lock;
Singleton* Singleton::instance = 0;
//queue<string> Singleton::messages;
//unordered_map<string, Command *> Singleton::commands;
//unordered_map<string, Command *> Singleton::symbol_table_program;
//unordered_map<string, Command *> Singleton::symbol_table_simulator;
//unordered_map<string, float> Singleton::var_values;
//unordered_map<int, string> Singleton::index;
//bool Singleton::is_done = false;

/*
 * The function resets the singleton fields of symbol table of the simulator, index and values of the variables.
 */
void Singleton::reset(unordered_map<string, Command *> &map, unordered_map<int, string> &index_map,
                  unordered_map<string, float> &var_value1) {
  symbol_table_simulator = map;
  index = index_map;
  var_values = var_value1;
}
/*
 * The function returns an instance of singleton.
 */
Singleton* Singleton::getSingleton() {
  if (instance == 0) {
    instance = new Singleton();
  }
  return instance;
}
/*
 * The function returns the next message that needs to be sent.
 */
string Singleton::getMessage() {
  string message = Singleton::messages.front();
  Singleton::messages.pop();
  return message;
}
/*
 * The function adds a message to the messages queue.
 */
void Singleton::setMessages(string str) {
  Singleton::messages.push(str);
}
/*
 * The function returns true if there are no more messages and false otherwise.
 */
bool Singleton::isMessagesEmpty() {
  if (messages.empty()) {
    return true;
  }
  return false;
}
/*
 * The function returns the command map.
 */
unordered_map<string, Command *> *Singleton::getCommands() {
  return &commands;
}
/*
 * The function returns the var values map.
 */
unordered_map<string, float> *Singleton::getVarValues() {
  return &var_values;
}
/*
 * The function returns the symbol table of the program.
 */
unordered_map<string, Command *> *Singleton::getSymbolTableProgram() {
  return &symbol_table_program;
}
/*
 * The function returns the symbol table of the simulator.
 */
unordered_map<string, Command *> *Singleton::getSymbolTableSimulator() {
  return &symbol_table_simulator;
}
/*
 * The function returns the index map.
 */
unordered_map<int, string> *Singleton::getIndex() {
  return &index;
}
/*
 * The function updates the symbol table of the program.
 */
void Singleton::updateSymbolTableProgram(string name, Command *command) {
  symbol_table_program[name] = command;
}
/*
 * The function updates the var values map.
 */
void Singleton::updateVarValues(string var_name, float value) {
  var_values[var_name] = value;
}
/*
 * The function inserts a command to the commands map.
 */
void Singleton::insertToCommands(string name_of_command, Command *command) {
  commands.insert({name_of_command, command});
}
/*
 * The function sets the is_done state.
 */
void Singleton::setIsDone(bool state) {
  is_done = state;
}
/*
 * The function returns is_done.
 */
bool Singleton::getIsDone() {
  return is_done;
}

/*
 * Destructor.
 */
Singleton::~Singleton() {
  mutex_lock.lock();
  for (auto &iter: commands) {
    delete iter.second;
  }
  mutex_lock.unlock();
}
