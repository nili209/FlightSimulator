//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__BINARYOPERATOR_H_
#define EX3__BINARYOPERATOR_H_
#include "Expression.h"
class BinaryOperator : public Expression {
 protected:
  Expression *m_left;
  Expression *m_right;
 public:
  BinaryOperator(Expression *left, Expression *right);
  Expression *getLeft();
  Expression *getRight();
  virtual ~BinaryOperator();
};
#endif //EX3__BINARYOPERATOR_H_
