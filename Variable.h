//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__VARIABLE_H_
#define EX3__VARIABLE_H_
#include <unordered_map>
#include "Expression.h"
using namespace std;
class Variable : public Expression {
 private:
  string m_name;
  unordered_map<string, float> var_values_var;
 public:
  Variable(const string &name, unordered_map<string, float> var_values_var1);
  void checkValidity(string c);
  bool isDigit(char c);
  bool isLetter(char c);
  double calculate();
  void increase(int number);
  void decrease(int number);
  Variable &operator++();
  Variable &operator++(int);
  Variable &operator--();
  Variable &operator--(int);
  Variable &operator+=(double number);
  Variable &operator-=(double number);
  virtual ~Variable();
};
#endif //EX3__VARIABLE_H_
