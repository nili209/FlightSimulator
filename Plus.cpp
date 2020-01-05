//
// Created by shiraz and nili on 31.12.2019.
//
#include "Plus.h"
/*
 * Constructor.
 */
Plus::Plus(Expression *left, Expression *right) : BinaryOperator(left, right) {}
/*
 * The function returns the sum of both expression's values.
 */
double Plus::calculate() {
  return getLeft()->calculate() + getRight()->calculate();
}
/*
 * Destructor.
 */
Plus:: ~Plus() {
  delete m_right;
  delete m_left;
}