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
  static Singleton *singleton;
  static unordered_map<string, Command *> commands;
  static unordered_map<string, float> var_values;
  static queue<string> messages;
  static unordered_map<string, Command *> symbol_table_program;
  static unordered_map<string, Command *> symbol_table_simulator;
  static unordered_map<int, string> index;
  Singleton() {};
 public:
  static void reset(unordered_map<string, Command *> &map, unordered_map<int, string> &index_map,
                    unordered_map<string, float> &var_value1) {
    symbol_table_simulator = map;
    index = index_map;
    var_values = var_value1;
  }
  static Singleton *getSingleton() {
    if (singleton == 0) {
      singleton = new Singleton();
    }
    return singleton;
  }
  static string getMessage() {
    string message = Singleton::messages.front();
    Singleton::messages.pop();
    return message;
  }
  static void setMessages(string str) {
    Singleton::messages.push(str);
  }
  static bool isMessagesEmpty() {
    if (messages.empty()) {
      return true;
    }
    return false;
  }
  static unordered_map<string, Command *> *getCommands() {
    return &commands;
  }
  static unordered_map<string, float> *getVarValues() {
    return &var_values;
  }
  static unordered_map<string, Command *> *getSymbolTableProgram() {
    return &symbol_table_program;
  }
  static unordered_map<string, Command *> *getSymbolTableSimulator() {
    return &symbol_table_simulator;
  }
  static unordered_map<int, string> *getIndex() {
    return &index;
  }
  static void updateSymbolTableProgram(string name, Command *command) {
    symbol_table_program[name] = command;
  }
  static void updateVarValues(string var_name, float value) {
    var_values[var_name] = value;
  }
  static void insertToCommands(string name_of_command, Command *command) {
    commands.insert({name_of_command, command});
  }
};
Singleton *::Singleton::singleton = 0;
queue<string> Singleton::messages;
unordered_map<string, Command *> Singleton::commands;
unordered_map<string, Command *> Singleton::symbol_table_program;
unordered_map<string, Command *> Singleton::symbol_table_simulator;
unordered_map<string, float> Singleton::var_values;
unordered_map<int, string> Singleton::index;
#endif //EX3__SINGLETON_H_
