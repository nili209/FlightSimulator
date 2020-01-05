//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__PLUS_H_
#define EX3__PLUS_H_
#include "BinaryOperator.h"
class Plus : public BinaryOperator {
 public:
  Plus(Expression *left, Expression *right);
  double calculate();
  virtual ~Plus();
};
#endif //EX3__PLUS_H_
