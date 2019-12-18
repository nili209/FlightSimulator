//
// Created by shiraz on 16.12.2019.
//

#ifndef EX3__SINGLETON_H_
#define EX3__SINGLETON_H_
//#pragma once
#include <string>
#include "Command.h"

class Singleton {
 private:
  static Singleton* singleton;
  //private constractor
  Singleton(){
  };
 public:
  static void reset(unordered_map<string, Command*>& map, unordered_map<int, string>&index_map);
  static unordered_map<string, Command*> commands;
  static unordered_map<string, Command*> symbol_table_program;
  static unordered_map<string, Command*> symbol_table_simulator;
  static unordered_map<string, float > var_values;
  static unordered_map<int, string> index;
  static Singleton* getSingleton();
};

Singleton*::Singleton::singleton = 0;
unordered_map<string, Command*> Singleton::commands;
unordered_map<string, Command*> Singleton::symbol_table_program;
unordered_map<string, Command*> Singleton::symbol_table_simulator;
unordered_map<string, float> Singleton::var_values;
unordered_map<int, string> Singleton::index;
Singleton *Singleton::getSingleton() {
  if (singleton == 0) {
    singleton = new Singleton();
  }
  return singleton;
}
void Singleton:: reset(unordered_map<string, Command*>& map, unordered_map<int, string>& index_map){
  symbol_table_simulator = map;
  index = index_map;
}
#endif //EX3__SINGLETON_H_
