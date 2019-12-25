//
// Created by shiraz on 16.12.2019.
//

#ifndef EX3__SINGLETON_H_
#define EX3__SINGLETON_H_
#include <string>
#include "Command.h"

class Singleton {
 private:
  static Singleton *instance;
  static unordered_map<string, Command *> commands;
  static unordered_map<string, float> var_values;
  static queue<string> messages;
  static unordered_map<string, Command *> symbol_table_program;
  static unordered_map<string, Command *> symbol_table_simulator;
  static unordered_map<int, string> index;
  Singleton(){};
 public:
  static mutex mutex_lock;
  void reset(unordered_map<string, Command *> &map, unordered_map<int, string> &index_map,
                    unordered_map<string, float> &var_value1);
  static Singleton *getSingleton();
  string getMessage();
  void setMessages(string str);
  bool isMessagesEmpty();
  unordered_map<string, Command *> *getCommands();
  unordered_map<string, float> *getVarValues();
  unordered_map<string, Command *> *getSymbolTableProgram();
  unordered_map<string, Command *> *getSymbolTableSimulator();
  unordered_map<int, string> *getIndex();
  void updateSymbolTableProgram(string name, Command *command);
  void updateVarValues(string var_name, float value);
  void insertToCommands(string name_of_command, Command *command);
  virtual ~Singleton();
};
//Singleton *::Singleton::instance = 0;
//queue<string> Singleton::messages;
//unordered_map<string, Command *> Singleton::commands;
//unordered_map<string, Command *> Singleton::symbol_table_program;
//unordered_map<string, Command *> Singleton::symbol_table_simulator;
//unordered_map<string, float> Singleton::var_values;
//unordered_map<int, string> Singleton::index;
#endif //EX3__SINGLETON_H_
