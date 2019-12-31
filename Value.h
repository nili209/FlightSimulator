//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__VALUE_H_
#define EX3__VALUE_H_
#include "Expression.h"
class Value : public Expression {
 private:
  double const m_value;
 public:
  Value(double value);
  double calculate();
  virtual ~Value();
};
#endif //EX3__VALUE_H_
