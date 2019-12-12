//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__FLIGHTSIMULATOR_CPP_
#define ex3__FLIGHTSIMULATOR_CPP_
#include "Command.h"
#include "OpenServerCommand.cpp"
#include "ConnectCommand.cpp"
#include "DefineVarCommand.cpp"
#include "PrintCommand.cpp"
#include "SleepCommand.cpp"
#include "ConditionParser.cpp"
#include "IfCommand.cpp"
#include "LoopCommand.cpp"
class FlightSimulator {
 public:
  unordered_map<string, Command*> commands;
  FlightSimulator(){
    resetCommands();
  };
  void resetCommands() {
    commands.insert({OPEN_DATA_SERVER, new OpenServerCommand()});
    commands.insert({CONNECT_CONTROL_CLIENT, new ConnectCommand()});
    commands.insert({VAR, new DefineVarCommand()});
    commands.insert({PRINT, new PrintCommand()});
    commands.insert({SLEEP, new SleepCommand()});
    commands.insert({LOOP, new LoopCommand()});
    commands.insert({IF, new IfCommand()});
  }
  queue<string> lexer(string file_name) {
    queue<string> token;
    string line;
    ifstream f;
    f.open(file_name, ios::in);
    //reading line by line
    while (getline(f, line)) {
      //dispose tabs
      size_t first = line.find_first_not_of('\t');
      if (string::npos != first){
        size_t last = line.size();
        line =  line.substr(first, line.size() - first+1);
      }
      createQueue(token, line);
    }
    f.close();
    return token;
  }
  void createQueue(queue<string> &token, string line) {
    string pusher;
    string even = "";
    int index_comma = 0, index_bracket = 0, index_space = 0, npos = (int) std::string::npos;
    //separate by brackets
    if ((index_bracket = line.find(OPEN_BRACKETS)) != npos) {
      //until the (
      string part_by_brackets = line.substr(0, index_bracket);
      even = part_by_brackets[index_bracket - 2];
      //separated by space
      separateBySpaces(token, index_space, npos, part_by_brackets);
      //in the ()
      if (even.compare("=") == 0) {
        string inside_brackets = line.substr(index_bracket, line.size() - part_by_brackets.size());
        pusher = inside_brackets;
        token.push(pusher);
        cout << pusher << endl;
      } else {
        string inside_brackets = line.substr(index_bracket + 1, line.size() - part_by_brackets.size() - 2);
        //separate by ','
        separateByComma(token, index_comma, npos, inside_brackets);
      }
      line.erase(0, index_space + 1);
    }
    //there is no bracket
    if ((index_bracket = line.find(OPEN_BRACKETS)) == npos) {
      separateBySpaces(token, index_space, npos, line);
      line.erase(0, index_bracket + 1);
    }
  }
  void separateBySpaces(queue<string> &token, int index_space, int npos, string part_by_brackets) {
    string pusher = "";
    //separate by space
    while ((index_space = part_by_brackets.find(SPACE)) != npos) {
      if (pusher.compare("=") == 0) {
        pusher = part_by_brackets;
        token.push(pusher);
        cout << pusher << endl;
        part_by_brackets.erase(0, index_space + 1);
        return;
      }
      string part_by_space = part_by_brackets.substr(0, index_space);
      pusher = part_by_space;
      token.push(pusher);
      cout << pusher << endl;
      part_by_brackets.erase(0, index_space + 1);
    }
    //there is no space
    if ((index_space = part_by_brackets.find(SPACE)) == npos) {
      pusher = part_by_brackets;
      token.push(pusher);
      cout << pusher << endl;
      part_by_brackets.erase(0, index_space + 1);
    }
  }
  void separateByComma(queue<string> &token, int index_comma, int npos, string part_by_brackets) {
    string pusher;
    while ((index_comma = part_by_brackets.find(COMMA)) != npos) {
      pusher = part_by_brackets.substr(0, index_comma);
      token.push(pusher);
      cout << pusher << endl;
      part_by_brackets.erase(0, index_comma + 1);
    }
    // there is no ','
    if ((index_comma = part_by_brackets.find(COMMA)) == npos) {
      pusher = part_by_brackets;
      token.push(pusher);
      cout << pusher << endl;
      part_by_brackets.erase(0, index_comma + 1);
    }
  }
  void parser(queue<string> &token){
    int i = 0;
    while(!token.empty()) {
      i++;
      string current = token.front();
      Command *c = commands.at(current);
      if(c != NULL) {
        c->execute(token, commands);
      }
    }

  }

};
#endif
