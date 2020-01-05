//
// Created by shiraz and nili on 12.12.2019.
//

#ifndef EX3__VARCOMMAND_H_
#define EX3__VARCOMMAND_H_
#include "Singleton.h"
#include "ShuntingYard.h"
class VarCommand : public Command {
 private:
  Singleton *singleton = Singleton::getSingleton();
  string sim, direction, name;
  float value;
 public:
  VarCommand(string sim1, string direction1, string name1) : sim(sim1), direction(direction1), name(name1) {};
  static void updateSymbolTableProg(string sim, float value);
  void setDirection(string direct);
  string getDirection();
  string getSim();
  void setSim(string sim1);
  float getValue();
  void setName(string name1);
  void setValue(float num);
  virtual void execute(queue<string> &token);
  virtual ~VarCommand();
};
#endif //EX3__VARCOMMAND_H_
