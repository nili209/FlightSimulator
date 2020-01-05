//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__OPENDATASERVER_H_
#define ex3__OPENDATASERVER_H_
#include "Command.h"
#include "VarCommand.h"
#include "ShuntingYard.h"

class OpenServerCommand : public Command {
 private:
  static int client_socket_in;
  Singleton *singleton = Singleton::getSingleton();
 public:
  OpenServerCommand(){};
  virtual void execute(queue<string> &token);
  static void openSocketOut(float port);
  static void updateValuesInMaps(int i,string &current_value,string &current_var_name);
  static void separateByComma(string buffer);
  static int readFromSim(int client_socket_in1);
  virtual ~OpenServerCommand();
};
#endif //EX3__OPENSERVERCOMMAND_H_
