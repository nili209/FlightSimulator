//
// Created by shiraz and nili on 12.12.2019.
//
#include "PrintCommand.h"
/*
* The function prints a message.
*/
void PrintCommand::execute(queue<string> &token) {
  string printer;
  float value;
  //the word "print"
  token.pop();
  //if the message is a string - need to dispose the " "
  if (token.front()[0] == '"') {
    printer = token.front().substr(1, token.front().size() - 2);
    cout << printer << endl;
    //is not a string with " "
  } else {
    value = ShuntingYard::calculator(token.front(), *singleton->getVarValues());
    cout << value << endl;
  }
  //the message
  token.pop();
}
/*
* Destructor.
*/
PrintCommand::~PrintCommand() {}


