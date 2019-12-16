//
// Created by shiraz on 16.12.2019.
//

#ifndef EX3__SINGLETON_H_
#define EX3__SINGLETON_H_
#include <string>
#include "Command.h"
class Singleton {
 private:
  static Singleton* singleton;
  //private constractor
  Singleton(){};
 public:
  static unordered_map<string, Command*> commands;
  static unordered_map<string, Command*> symbol_table_program;
  static Singleton* getSingleton();
};
Singleton*::Singleton::singleton = 0;
unordered_map<string, Command*> Singleton::commands;
unordered_map<string, Command*> Singleton::symbol_table_program;
Singleton *Singleton::getSingleton() {
  if (singleton == 0) {
    singleton = new Singleton();
  }
  return singleton;
}
#endif //EX3__SINGLETON_H_
