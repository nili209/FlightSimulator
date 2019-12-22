//
// Created by shiraz on 16.12.2019.
//

#ifndef EX3__SINGLETON_H_
#define EX3__SINGLETON_H_
#include <string>
std::mutex mutex_lock;
#include "Command.h"

class Singleton {
 private:
  static Singleton* singleton;
  //private constractor
  Singleton(){};
 public:
  static queue<string> messages;
  static void reset(unordered_map<string, Command*>& map, unordered_map<int, string>&index_map, unordered_map<string, float>&var_value1);
  static unordered_map<string, Command*> commands;
  static unordered_map<string, Command*> symbol_table_program;
  static unordered_map<string, Command*> symbol_table_simulator;
  static unordered_map<string, float > var_values;
  static unordered_map<int, string> index;
  static Singleton* getSingleton();
  static unordered_map<string, Command*> getCommands();
  static unordered_map<string, Command*> getSymbolTableProgram();
  static unordered_map<string, Command*> getSymbolTableSimulator();
  static unordered_map<string, float > getVarValues();
  static unordered_map<int, string> getIndex();
  static string getMessage();
  static void setCommands(string str, Command* c);
  static void setSymbolTableProgram(string str, Command* c);
  static void setSymbolTableSimulator(string str, Command* c);
  static void setVarValues(string str, float i);
  static void setIndex(int i, string str);
  static void setMessages(string str);
  static bool isMessagesEmpty();
  static void insertCommands(string str, Command* c);
  static void insertSymbolTableProgram(string str, Command* c);
  static void insertSymbolTableSimulator(string str, Command* c);
  static void insertVarValues(string str, float i);
  static void insertIndex(int i, string str);

};

void Singleton::insertCommands(string str, Command* c) {
  Singleton::commands.insert({str, c});
}
void Singleton::insertSymbolTableProgram(string str, Command* c) {
  Singleton::symbol_table_program.insert({str, c});
}
void Singleton::insertSymbolTableSimulator(string str, Command* c) {
  Singleton::symbol_table_simulator.insert({str, c});
}
void Singleton::insertVarValues(string str, float i) {
  Singleton::var_values.insert({str, i});
}
void Singleton::insertIndex(int i, string str) {
  Singleton::index.insert({i, str});
}


bool Singleton::isMessagesEmpty() {
  if (messages.empty()){
    return true;
  }
  return false;
}

void Singleton:: setVarValues(string str, float i) {
  Singleton::var_values.at(str) = i;
}
void Singleton::setIndex(int i, string str) {
  Singleton::index.at(i) = str;
}
void Singleton:: setMessages(string str) {
  Singleton::messages.push(str);
}
void Singleton:: setCommands(string str, Command* c) {
  Singleton::commands.at(str) = c;
}
void Singleton :: setSymbolTableProgram(string str, Command* c) {
  Singleton::symbol_table_program.at(str) = c;
}
void Singleton:: setSymbolTableSimulator(string str, Command* c) {
  Singleton::symbol_table_simulator.at(str) = c;
}


Singleton*::Singleton::singleton = 0;
queue<string> Singleton::messages;
unordered_map<string, Command*> Singleton::commands;
unordered_map<string, Command*> Singleton::symbol_table_program;
unordered_map<string, Command*> Singleton::symbol_table_simulator;
unordered_map<string, float> Singleton::var_values;
unordered_map<int, string> Singleton::index;

string Singleton::getMessage() {
  string message = Singleton::messages.front();
  Singleton::messages.pop();
  return message;
}
unordered_map<string, Command*> Singleton::getCommands() {
  return Singleton::commands;
}
unordered_map<string, Command*> Singleton::getSymbolTableSimulator() {
  return Singleton::symbol_table_simulator;
};
unordered_map<string, Command*> Singleton::getSymbolTableProgram() {
  return Singleton::symbol_table_program;
}
unordered_map<string, float > Singleton :: getVarValues() {
  return Singleton::var_values;
}
unordered_map<int, string> Singleton::getIndex() {
  return Singleton::index;
}
Singleton *Singleton::getSingleton() {
  if (singleton == 0) {
    singleton = new Singleton();
  }
  return singleton;
}
void Singleton:: reset(unordered_map<string, Command*>& map, unordered_map<int, string>& index_map, unordered_map<string, float>&var_value1){
  symbol_table_simulator = map;
  index = index_map;
  var_values = var_value1;
}
#endif //EX3__SINGLETON_H_
