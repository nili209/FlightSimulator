//
// Created by shiraz on 12.12.2019.
//
#ifndef ex3__COMMAND_H_
#define ex3__COMMAND_H_

#include <unordered_map>
#include "Command.h"
#include <list>
#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include "iostream"
#define SPACE " "
#define OPEN_BRACKETS '('
#define COMMA ','
#define OPEN_DATA_SERVER "openDataServer"
#define CONNECT_CONTROL_CLIENT "connectControlClient"
#define VAR "var"
#define PRINT "Print"
#define SLEEP "Sleep"

using namespace std;

class Command {
 public:
  virtual void execute(queue<string> &token, unordered_map<string, Command*> &commands) = 0;
};
#endif //ex3_COMMAND_H_
