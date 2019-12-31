//
// Created by shiraz and nili on 31.12.2019.
//
#include "BinaryOperator.h"
/*
 * Constructor.
 */
BinaryOperator::BinaryOperator(Expression *left, Expression *right) : m_left(left), m_right(right) {}
/*
 * The function returns the left expression.
 */
Expression *BinaryOperator::getLeft() {
  return this->m_left;
}
/*
 * The function returns the right expression.
 */
Expression *BinaryOperator::getRight() {
  return this->m_right;
}
/*
 * Destructor.
 */
BinaryOperator:: ~BinaryOperator() {}