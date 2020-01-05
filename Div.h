//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__DIV_H_
#define EX3__DIV_H_
#include "BinaryOperator.h"
class Div : public BinaryOperator {
 public:
  Div(Expression *left, Expression *right);
  double calculate();
  virtual ~Div();
};

#endif //EX3__DIV_H_
