//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__COMMAND_H_
#define ex3__COMMAND_H_

#include <unordered_map>
#include "Command.h"
#include <list>
#include <string>
#include <fstream>
#include <queue>
#include "iostream"
#include <sys/socket.h>
#include <thread>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <mutex>
#define LINE_SIZE 791
#define COMMA ','
#define OPEN_DATA_SERVER "openDataServer"
#define CONNECT_CONTROL_CLIENT "connectControlClient"
#define VAR "var"
#define PRINT "Print"
#define SLEEP "Sleep"
#define IF "if"
#define LOOP "while"

using namespace std;

class Command {
 public:
  virtual void execute(queue<string> &token) = 0;

};
#endif
//Todo
//אחרי כל אופרטור ולא רק שווה -  להכניס הכל לתור אבל לא להכניס את הסולסול הסוגר אם יש בתנאים.
//לעשות רשימה של משתנים של הסימולטור ולשים את הטרד שישלח את הפונקציה שפותחת את הסוקט