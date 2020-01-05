//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__FLIGHTSIMULATOR_H_
#define EX3__FLIGHTSIMULATOR_H_
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "IfCommand.h"
#include "LoopCommand.h"
#include "Singleton.h"
#include "VarCommand.h"
class FlightSimulator {
 private:
  bool is_in_brackets = false;
  Singleton *singleton = Singleton::getSingleton();
 public:
  FlightSimulator();
  void resetSimulatorMap();
  void resetCommands();
  queue<string> lexer(string file_name);
  int isOperator(string line, int index);
  void searchForOperator(queue<string> &token, string line);
  void createQueue(queue<string> &token, string line);
  void dealWithArrow(queue<string> &token, const string &line, string &current, int &i, string direction);
  void dealWithBrackets(queue<string> &token, string &line, string &current, int &i);
  int countBrackets(string &line);
  void dealWithOperator(queue<string> &token, const string &line, string &current, int &i);
  void parser(queue<string> &token);
  virtual ~FlightSimulator();
};
#endif //EX3__FLIGHTSIMULATOR_H_
