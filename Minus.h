//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__MINUS_H_
#define EX3__MINUS_H_
#include "BinaryOperator.h"
class Minus : public BinaryOperator {
 public:
  Minus(Expression *left, Expression *right);
  double calculate();
  virtual ~Minus();
};
#endif //EX3__MINUS_H_
