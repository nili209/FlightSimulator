//
// Created by shiraz and nili on 31.12.2019.
//

#include "UMinus.h"
/*
 * Constructor.
 */
UMinus::UMinus(Expression *expression) : UnaryOperator(expression) {}
/*
 * The function returns the minus of the value of the expression.
 */
double UMinus::calculate() {
  return -1 * UnaryOperator::calculate();
}
/*
 * Destructor.
 */
UMinus:: ~UMinus() {
  delete m_expression;
}