//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__UPLUS_H_
#define EX3__UPLUS_H_
#include "UnaryOperator.h"
class UPlus : public UnaryOperator {
 public:
  UPlus(Expression *expression);
  virtual ~UPlus();
};
#endif //EX3__UPLUS_H_
