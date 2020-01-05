#include "Mul.h"
//
// Created by shiraz and nili on 31.12.2019.
//
/*
 * Constructor.
 */
Mul::Mul(Expression *left, Expression *right) : BinaryOperator(left, right) {}
/*
 * The function returns the multiply of both expression's values.
 */
double Mul::calculate() {
  return getLeft()->calculate() * getRight()->calculate();
}
/*
 * Destructor.
 */
Mul:: ~Mul() {
  delete m_right;
  delete m_left;
}

