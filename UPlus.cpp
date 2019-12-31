//
// Created by shiraz and nili on 31.12.2019.
//
#include "UnaryOperator.h"
#include "UPlus.h"
/*
 * Constructor.
 */
UPlus::UPlus(Expression *expression) : UnaryOperator(expression) {}
/*
 * Destructor.
 */
UPlus::~UPlus() {
  delete m_expression;
}