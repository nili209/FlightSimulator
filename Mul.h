//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__MUL_H_
#define EX3__MUL_H_
#include "BinaryOperator.h"
class Mul : public BinaryOperator {
 public:
  Mul(Expression *left, Expression *right);
  double calculate();
  virtual ~Mul();
};
#endif //EX3__MUL_H_
