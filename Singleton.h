//
// Created by shiraz on 16.12.2019.
//

#ifndef EX3__SINGLETON_H_
#define EX3__SINGLETON_H_

#include <string>
#include "Command.h"
#include "Var.cpp"
class Singleton {
 private:
  static Singleton* singleton;
  //private constractor
  Singleton(){
  };
 public:
  static void reset(unordered_map<string, Command*>& map);
  static unordered_map<string, Command*> commands;
  static unordered_map<string, Command*> symbol_table_program;
  static unordered_map<string, Command*> symbol_table_simulator;
  static Singleton* getSingleton();
};

Singleton*::Singleton::singleton = 0;
unordered_map<string, Command*> Singleton::commands;
unordered_map<string, Command*> Singleton::symbol_table_program;
unordered_map<string, Command*> Singleton::symbol_table_simulator;
Singleton *Singleton::getSingleton() {
  if (singleton == 0) {
    singleton = new Singleton();
  }
  return singleton;
}
void Singleton:: reset(unordered_map<string, Command*>& map){
  symbol_table_simulator = map;
}
#endif //EX3__SINGLETON_H_
