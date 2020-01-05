//
// Created by shiraz and nili on 31.12.2019.
//
#include "ShuntingYard.h"
/*
 * The function returns the value of the expression received.
 */
float ShuntingYard::calculator(string expression, unordered_map<string, float> var_values) {
  Interpreter* interpreter = new Interpreter(var_values);
  //dispose the spaces
  unsigned int i = 0, count_open_brackets = 0, count_close_brackes = 0;
  string newString = "";
  for (; i < expression.size(); i++) {
    if (expression[i] == ' ') {
      continue;
    }
    if (expression[i] == ')') {
      count_close_brackes++;
    }
    if (expression[i] == '(') {
      count_open_brackets++;
    }
    newString += expression[i];
  }
  if (count_close_brackes > count_open_brackets) {
    newString = newString.substr(0, newString.length() - 1);
  }
  if (count_close_brackes < count_open_brackets) {
    newString = newString.substr(1, newString.length() - 1);
  }
  return interpreter->interpret(newString);
}