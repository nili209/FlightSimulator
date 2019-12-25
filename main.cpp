#include <string>
#include <queue>
#include "FlightSimulator.cpp"
int main(int argc, char *argv[]) {
  if(argc > 1) {
    char *file_name = argv[1];
    FlightSimulator f = FlightSimulator();
    queue<string> token;
    token = f.lexer(file_name);
    f.parser(token);
  } else {
    cerr<<"missing file_name"<<endl;
  }
  return 0;
}
