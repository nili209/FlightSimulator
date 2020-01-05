#include "Div.h"
//
// Created by shiraz and nili on 31.12.2019.
//
/*
 * Constructor.
 */
Div::Div(Expression *left, Expression *right) : BinaryOperator(left, right) {}
/*
 * The function returns the division of the first expression by the other.
 */
double Div::calculate() {
  if (getRight()->calculate() == 0) {
    throw "bad input - divide by zero";
  }
  double div = getLeft()->calculate() / getRight()->calculate();
  return div;
}
/*
 * Destructor.
 */
Div:: ~Div() {
  delete m_right;
  delete m_left;
}

