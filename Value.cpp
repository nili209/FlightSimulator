//
// Created by shiraz and nili on 31.12.2019.
//
#include "Value.h"
/*
 * Constructor.
 */
Value::Value(double value) : m_value(value) {}
/*
 * The function returns the value.
 */
double Value::calculate() {
  return this->m_value;
}
/*
 * Destructor.
 */
Value:: ~Value() {}

