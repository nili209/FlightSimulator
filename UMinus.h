//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__UMINUS_H_
#define EX3__UMINUS_H_
#include "UnaryOperator.h"
class UMinus : public UnaryOperator {
 public:
  UMinus(Expression *expression);
  double calculate();
  virtual ~UMinus();
};
#endif //EX3__UMINUS_H_
