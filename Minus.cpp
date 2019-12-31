#include "Minus.h"
//
// Created by shiraz and nili on 31.12.2019.
//
/*
 * Constructor.
 */
Minus::Minus(Expression *left, Expression *right) : BinaryOperator(left, right) {}
/*
 * The function returns the value of the first expression less the second.
 */
double Minus::calculate() {
  return getLeft()->calculate() - getRight()->calculate();
}
/*
 * Destructor.
 */
Minus:: ~Minus() {
  delete m_right;
  delete m_left;
}

