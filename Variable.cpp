//
// Created by shiraz and nili on 31.12.2019.
//
#include "Variable.h"
/*
 * Constructor.
 */
Variable::Variable(const string &name, unordered_map<string, float> var_values_var1) : m_name(name), var_values_var(var_values_var1) {
  checkValidity(name);
}
/*
 * The function checks the validity of the variable name.
 */
void Variable::checkValidity(string c) {
  int length = c.length();
  for (int i = 0; i < length; i++) {
    //is not a letter
    if (isLetter(c[i]) == false) {
      //is not _
      if (c[i] != '_') {
        // is not a number
        if (isDigit(c[i]) == false) {
          throw "bad input - invalid variable m_name";
          //if the variable m_name starts with a number it is invalid
        } else if (i == 0) {
          throw "bad input - invalid variable m_name";
        }
      }
    }
  }
}
/*
 * The function returns true if c is a digit and false otherise.
 */
bool Variable::isDigit(char c) {
  string digits = "0123456789";
  int length = digits.length();
  for (int i = 0; i < length; i++) {
    if (c == digits[i]) {
      return true;
    }
  }
  return false;
}
/*
 * The function returns true if c is a letter and false otherise.
 */
bool Variable::isLetter(char c) {
  string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int length = letters.length();
  for (int i = 0; i < length; i++) {
    if (c == letters[i]) {
      return true;
    }
  }
  return false;
}
/*
 * The function returns the value of the variable.
 */
double Variable::calculate() {
  return var_values_var.at(m_name);
}
/*
 * The function updates the variable with a value increase by the number received.
 */
void Variable::increase(int number) {
  var_values_var.at(m_name) += number;
}
/*
 * The function updates the variable with a value decrease by the number received.
 */
void Variable::decrease(int number) {
  var_values_var.at(m_name) -= number;
}
/*
 * The function returns the variable with a value increase by 1.
 */
Variable &Variable::operator++() {
  this->increase(1);
  return *this;
}
/*
 * The function returns the variable with a value increase by 1.
 */
Variable &Variable::operator++(int) {
  this->operator++();
  return *this;
}
/*
 * The function returns the variable with a value decrease by 1.
 */
Variable &Variable::operator--() {
  this->decrease(1);
  return *this;
}
/*
 * The function returns the variable with a value decrease by 1.
 */
Variable &Variable::operator--(int) {
  this->operator--();
  return *this;
}
/*
 * The function returns the variable with a value increase by the number received.
 */
Variable &Variable::operator+=(double number) {
  this->increase(number);
  return *this;
}
/*
 * The function returns the variable with a value decrease by the number received.
 */
Variable &Variable::operator-=(double number) {
  this->decrease(number);
  return *this;
}
/*
 * Destructor.
 */
Variable::~Variable() {}