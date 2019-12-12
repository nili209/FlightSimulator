#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include "FlightSimulator.cpp"

int main(int argc, char *argv[]) {
  char *file_name = argv[1];
  FlightSimulator f = FlightSimulator();
  queue<string> token;
  token = f.lexer(file_name);
  //f.parser(token);
  return 0;

}

