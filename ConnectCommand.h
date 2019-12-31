//
// Created by shiraz and nili on 31.12.2019.
//

#ifndef EX3__CONNECTCOMMAND_H_
#define EX3__CONNECTCOMMAND_H_
#include <cstring>
#include "Var.h"
class ConnectCommand : public Command {
 private:
  static int client_socket;
 public:
  ConnectCommand() {};
  virtual void execute(queue<string> &token);
  static int writeMessages();
  static void Connect(const char *ip, int port);
  virtual ~ConnectCommand();
};
#endif //EX3__CONNECTCOMMAND_H_
