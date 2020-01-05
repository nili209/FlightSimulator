//
// Created by shiraz and nili on 31.12.2019.
//
#include "UnaryOperator.h"
/*
 * Constructor.
 */
UnaryOperator::UnaryOperator(Expression *expression) : m_expression(expression) {}
/*
 * The function returns the value of m_expression.
 */
double UnaryOperator::calculate() {
  return this->m_expression->calculate();
}
/*
 * Destructor.
 */
UnaryOperator:: ~UnaryOperator() {
}
