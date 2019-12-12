#include <string>
#include <queue>
#include "FlightSimulator.cpp"
int main(int argc, char *argv[]) {
  char *file_name = argv[1];
  FlightSimulator f = FlightSimulator();
  queue<string> token;
  token = f.lexer(file_name);
  string arr[2] = {"a","b"};
  f.parser(token);
  return 0;

}

