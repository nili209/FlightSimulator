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
#include "Singleton.h"

class FlightSimulator {
 public:
  Singleton* singleton;
  FlightSimulator() {
    singleton = Singleton::getSingleton();
    resetCommands();
    resetSimulatorMap();
  };
  void resetSimulatorMap() {
    unordered_map<string, Command*> map;
    Var *v1 = new Var("/instrumentation/airspeed-indicator/indicated-speed-kt", "<-" );
    map.insert({"airspeed-indicator_indicated-speed-kt", v1});
    Var *v2 = new Var("//instrumentation/heading-indicator/offset-deg", "<-" );
    map.insert({"heading-indicator_offset-deg", v2});
    Var *v3 = new Var("/instrumentation/altimeter/indicated-altitude-ft", "<-" );
    map.insert({"altimeter_indicated-altitude-ft", v3});
    Var *v4 = new Var("/instrumentation/altimeter/pressure-alt-ft", "<-" );
    map.insert({"altimeter_pressure-alt-ft", v4});
    Var *v5 = new Var("/instrumentation/attitude-indicator/indicated-pitch-deg", "<-" );
    map.insert({"attitude-indicator_indicated-pitch-deg", v5});
    Var *v6 = new Var("/instrumentation/attitude-indicator/indicated-roll-deg", "<-" );
    map.insert({"attitude-indicator_indicated-roll-deg", v6});
    Var *v7 = new Var("/instrumentation/attitude-indicator/internal-pitch-deg", "<-" );
    map.insert({"attitude-indicator_internal-pitch-deg", v7});
    Var *v8 = new Var("/instrumentation/attitude-indicator/internal-roll-deg", "<-" );
    map.insert({"attitude-indicator_internal-roll-deg", v8});
    Var *v9 = new Var("/instrumentation/encoder/indicated-altitude-ft", "<-" );
    map.insert({"encoder_indicated-altitude-ft", v9});
    Var *v10 = new Var("/instrumentation/encoder/pressure-alt-ft", "<-" );
    map.insert({"encoder_pressure-alt-ft", v10});
    Var *v11 = new Var("/instrumentation/gps/indicated-altitude-ft", "<-" );
    map.insert({"gps_indicated-altitude-ft", v11});
    Var *v12 = new Var("/instrumentation/gps/indicated-ground-speed-kt", "<-" );
    map.insert({"gps_indicated-ground-speed-kt", v12});
    Var *v13 = new Var("/instrumentation/gps/indicated-vertical-speed", "<-" );
    map.insert({"gps_indicated-vertical-speed", v13});
    Var *v14 = new Var("/instrumentation/heading-indicator/indicated-heading-deg", "<-" );
    map.insert({"indicated-heading-deg", v14});
    Var *v15 = new Var("/instrumentation/magnetic-compass/indicated-heading-deg", "<-" );
    map.insert({"magnetic-compass_indicated-heading-deg", v15});
    Var *v16 = new Var("/instrumentation/slip-skid-ball/indicated-slip-skid", "<-" );
    map.insert({"slip-skid-ball_indicated-slip-skid", v16});
    Var *v17 = new Var("/instrumentation/turn-indicator/indicated-turn-rate", "<-" );
    map.insert({"turn-indicator_indicated-turn-rate", v17});
    Var *v18 = new Var("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", "<-" );
    map.insert({"vertical-speed-indicator_indicated-speed-fpm", v18});
    Var *v19 = new Var("/controls/flight/aileron", "<-" );
    map.insert({"flight_aileron", v19});
    Var *v20 = new Var("/controls/flight/elevator", "<-" );
    map.insert({"flight_elevator", v20});
    Var *v21 = new Var("/controls/flight/rudder", "<-" );
    map.insert({"flight_rudder", v21});
    Var *v22 = new Var("/controls/flight/flaps", "<-" );
    map.insert({"flight_flaps", v22});
    Var *v23 = new Var("/controls/engines/engine/throttle", "<-" );
    map.insert({"engine_throttle", v23});
    Var *v24 = new Var("/engines/engine/rpm", "<-" );
    map.insert({"engine_rpm", v24});
    singleton->reset(map);
  }
  void resetCommands() {
    singleton->commands.insert({OPEN_DATA_SERVER, new OpenServerCommand()});
    singleton->commands.insert({CONNECT_CONTROL_CLIENT, new ConnectCommand()});
    singleton->commands.insert({VAR, new DefineVarCommand()});
    singleton->commands.insert({PRINT, new PrintCommand()});
    singleton->commands.insert({SLEEP, new SleepCommand()});
    singleton->commands.insert({LOOP, new LoopCommand()});
    singleton->commands.insert({IF, new IfCommand()});
  }
  queue<string> lexer(string file_name) {
    queue<string> token;
    string line;
    ifstream f;
    f.open(file_name, ios::in);
    //reading line by line
    int i;
    while (getline(f, line)) {
      i++;
      //dispose tabs
      size_t first = line.find_first_not_of('\t');
      if (string::npos != first) {
        size_t last = line.size();
        line = line.substr(first, line.size() - first + 1);
      }
      createQueue(token, line);
      // createQueue(token, line);
    }
    f.close();
    return token;
  }
  void createQueue(queue<string> &token, string line) {
    string current = "", pusher;
    int index = 0;
    for (int i = 0; i < line.length(); i++) {
      switch (line[i]) {
        //this is ->
        case '-' : {
          //it can be just a minus sign
          if (line[i + 1] != '>') {
            dealWithOperator(token, line, current, i);
          } else {
            dealWithArrow(token, line, current, i, "-");
          }
          break;
        }//this is <-
        case '<' : {
          //it can be just a bigger sign
          if (line[i + 1] != '-') {
            dealWithOperator(token, line, current, i);
          } else {
            dealWithArrow(token, line, current, i, "<");
          }
          break;
        }
        case '>': {
          dealWithOperator(token, line, current, i);
          break;
        }
        case '!': {
          dealWithOperator(token, line, current, i);
          break;
        }
        case '=' : {
          if (current.compare("") != 0) {
            //until the '='
            pusher = current;
            token.push(pusher);
            cout << pusher << endl;
            current = "";
          }
          //if this = does not mean to assign somthing
          if (line[i + 1] == '=') {
            current += line[i];
            current += line[i + 1];
            i++;
            pusher = current;
            token.push(pusher);
            cout << pusher << endl;
            current = "";
            break;
          }
          //push the '='
          pusher = line[i];
          token.push(pusher);
          cout << pusher << endl;
          //after the '='
          pusher = line.substr(i + 1, line.length() - i);
          if (pusher[0] == ' ') {
            pusher = pusher.substr(1, pusher.length() - 1);
          }
          token.push(pusher);
          cout << pusher << endl;
          i = line.length();
          current = "";
          break;
        }
        case '(' : {
          dealWithBrackets(token, line, current, i);
          break;
        }
        case ',' : {
          if (current.compare("") != 0) {
            //until the ','
            pusher = current;
            token.push(pusher);
            cout << pusher << endl;
            current = "";
          }
          break;
        }
        case ' ': {
          if (current.compare("") != 0) {
            pusher = current;
            token.push(pusher);
            cout << pusher << endl;
            current = "";
          }
          break;
        }
        default: {
          if (line[i] != ')') {
            current += line[i];
          }
          break;
        }
      }
    }
    if (current.compare("") != 0) {
      pusher = current;
      token.push(pusher);
      cout << pusher << endl;
    }

  }
  void dealWithArrow(queue<string> &token,const string &line,string &current,int &i, string direction) const {
    string pusher;
    //there was no space between the var name and the -> : the name var should be pushed into token
    if (current.compare(direction) != 0 && current.compare("") != 0) {
      pusher = current;
      token.push(pusher);
      cout << pusher << endl;
      current = "";
    }
    //current = ->
    current += line[i];
    current += line[i + 1];
    i++;
    //push ->
    pusher = current;
    token.push(pusher);
    cout << pusher << endl;
    current = "";
  }
  void dealWithBrackets(queue<string> &token, string &line, string &current, int &i) const {
    string pusher;
    if (current.compare("") != 0) {
      //until the '('
      pusher = current;
      token.push(pusher);
      cout << pusher << endl;
      if (line[i + 1] == '"') {
        current = "";
        while (line[i + 2] != '"') {
          current += line[i + 1];
          i++;
        }
        current += line[i + 1];
        current += line[i + 2];
        if (line[i + 3] == ',') {
          line = line.substr(i + 3, line.length() - i - 4);
          i = 0;
        } else {
          i += 2;
        }
        pusher = current;
        token.push(pusher);
        cout << pusher << endl;
      } else {
        //reset the line to be the phrase inside the ()
        line = line.substr(i + 1, line.length() - i - 2);
        i = -1;
      }
      current = "";
    }
  }
  void dealWithOperator(queue<string> &token, const string &line, string &current, int &i) const {
    string pusher;
    if (current.compare("") != 0) {
      pusher = current;
      token.push(pusher);
      cout << pusher << endl;
      current = "";
    }
    current += line[i];
    //this is not -=, just -
    if (line[i + 1] != '=') {
      pusher = current;
      //this is -=
    } else {
      current += line[i + 1];
      i++;
      pusher = current;
    }
    token.push(pusher);
    cout << pusher << endl;
    current = "";
  }
  void parser(queue<string> &token) {
    int i = 0;
    while (!token.empty()) {
      i++;
      string current = token.front();
      Command *c = singleton->commands.at(current);
      if (c != NULL) {
        c->execute(token);
      }
    }
  }
};
//  void createQueue(queue<string> &token, string line) {
//    string pusher;
//    string even = "";
//    int index_comma = 0, index_bracket = 0, index_space = 0, npos = (int) std::string::npos;
//    //separate by brackets
//    if ((index_bracket = line.find(OPEN_BRACKETS)) != npos) {
//      //until the (
//      string part_by_brackets = line.substr(0, index_bracket);
//      even = part_by_brackets[index_bracket - 2];
//      //separated by space
//      separateBySpaces(token, index_space, npos, part_by_brackets);
//      //in the ()
//      if (even.compare("=") == 0) {
//        string inside_brackets = line.substr(index_bracket, line.size() - part_by_brackets.size());
//        pusher = inside_brackets;
//        token.push(pusher);
//        cout << pusher << endl;
//      } else {
//        string inside_brackets = line.substr(index_bracket + 1, line.size() - part_by_brackets.size() - 2);
//        //separate by ','
//        separateByComma(token, index_comma, npos, inside_brackets);
//      }
//      line.erase(0, index_space + 1);
//    }
//    //there is no bracket
//    if ((index_bracket = line.find(OPEN_BRACKETS)) == npos) {
//      separateBySpaces(token, index_space, npos, line);
//      line.erase(0, index_bracket + 1);
//    }
//  }
//  void separateBySpaces(queue<string> &token, int index_space, int npos, string part_by_brackets) {
//    string pusher = "";
//    //separate by space
//    while ((index_space = part_by_brackets.find(SPACE)) != npos) {
//      if (pusher.compare("=") == 0) {
//        pusher = part_by_brackets;
//        token.push(pusher);
//        cout << pusher << endl;
//        part_by_brackets.erase(0, index_space + 1);
//        return;
//      }
//      string part_by_space = part_by_brackets.substr(0, index_space);
//      pusher = part_by_space;
//      token.push(pusher);
//      cout << pusher << endl;
//      part_by_brackets.erase(0, index_space + 1);
//    }
//    //there is no space
//    if ((index_space = part_by_brackets.find(SPACE)) == npos) {
//      pusher = part_by_brackets;
//      token.push(pusher);
//      cout << pusher << endl;
//      part_by_brackets.erase(0, index_space + 1);
//    }
//  }
//  void separateByComma(queue<string> &token, int index_comma, int npos, string part_by_brackets) {
//    string pusher;
//    while ((index_comma = part_by_brackets.find(COMMA)) != npos) {
//      pusher = part_by_brackets.substr(0, index_comma);
//      token.push(pusher);
//      cout << pusher << endl;
//      part_by_brackets.erase(0, index_comma + 1);
//    }
//    // there is no ','
//    if ((index_comma = part_by_brackets.find(COMMA)) == npos) {
//      pusher = part_by_brackets;
//      token.push(pusher);
//      cout << pusher << endl;
//      part_by_brackets.erase(0, index_comma + 1);
//    }
//  }
//  bool checkIfAssign(string &line, int i) {
//    char next = line[i + 1];
//    char last = line[i - 1];
//    //>=, <= , !=, ==
//    if (last == '>' || last == '<' || last == '!' || last == '=') {
//      return false;
//    }
//    //==
//    if (next == '=') {
//      return false;
//    }
//    return true;
//  }

#endif
