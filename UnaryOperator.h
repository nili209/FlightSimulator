//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__UNARYOPERATOR_H_
#define EX3__UNARYOPERATOR_H_
#include "Expression.h"
class UnaryOperator : public Expression {
 protected:
  Expression *m_expression;
 public:
  UnaryOperator(Expression *expression);
  double calculate();
  virtual ~UnaryOperator();
};
#endif //EX3__UNARYOPERATOR_H_
