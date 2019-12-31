//
// Created by shiraz and nili on 4.11.2019.
//
#ifndef EX3__SHUNTINGYARD_H_
#define EX3__SHUNTINGYARD_H_
#include "Interpreter.h"
using namespace std;
class ShuntingYard {
 public :
  static float calculator(string expression, unordered_map<string, float> var_values);
};
#endif //EX3__SHUNTINGYARD_H_
