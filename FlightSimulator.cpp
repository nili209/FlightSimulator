//
// Created by shiraz and nili on 12.12.2019.
//
#include "FlightSimulator.h"

FlightSimulator::FlightSimulator() {
  resetCommands();
  resetSimulatorMap();
}
/*
* The function resets the symbol table of the simulator.
*/
void FlightSimulator::resetSimulatorMap() {
  unordered_map<string, Command *> map;
  unordered_map<int, string> index_map;
  unordered_map<string, float> var_values;
  string name_of_var = "";
  string sim_of_var = "";
  /***/
  name_of_var = "airspeed-indicator_indicated-speed-kt";
  sim_of_var = "/instrumentation/airspeed-indicator/indicated-speed-kt";
  Var *v1 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v1});
  index_map.insert({0, name_of_var});
  var_values.insert({name_of_var, 1});
  /***/
  name_of_var = "time_warp";
  sim_of_var = "/sim/time/warp";
  Var *v2 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v2});
  index_map.insert({1, name_of_var});
  var_values.insert({name_of_var, 1});
  /***/
  name_of_var = "switches_magnetos";
  sim_of_var = "/controls/switches/magnetos";
  Var *v3 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v3});
  index_map.insert({2, name_of_var});
  var_values.insert({name_of_var, 1});
  /***/
  name_of_var = "heading-indicator_offset-deg";
  sim_of_var = "/instrumentation/heading-indicator/offset-deg";
  Var *v4 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v4});
  index_map.insert({3, name_of_var});
  var_values.insert({name_of_var, 1});
  /***/
  name_of_var = "altimeter_indicated-altitude-ft";
  sim_of_var = "/instrumentation/altimeter/indicated-altitude-ft";
  Var *v5 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v5});
  index_map.insert({4, name_of_var});
  var_values.insert({name_of_var, 1});
  /***/
  name_of_var = "altimeter_pressure-alt-ft";
  sim_of_var = "/instrumentation/altimeter/pressure-alt-ft";
  Var *v6 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v6});
  index_map.insert({5, name_of_var});
  var_values.insert({name_of_var, 1});
  /***/
  name_of_var = "attitude-indicator_indicated-pitch-deg";
  sim_of_var = "/instrumentation/attitude-indicator/indicated-pitch-deg";
  Var *v7 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v7});
  index_map.insert({6, name_of_var});
  var_values.insert({name_of_var, 1});
  /***/
  name_of_var = "attitude-indicator_indicated-roll-deg";
  sim_of_var = "/instrumentation/attitude-indicator/indicated-roll-deg";
  Var *v8 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v8});
  index_map.insert({7, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "attitude-indicator_internal-pitch-deg";
  sim_of_var = "/instrumentation/attitude-indicator/internal-pitch-deg";
  Var *v9 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v9});
  index_map.insert({8, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "attitude-indicator_internal-roll-deg";
  sim_of_var = "/instrumentation/attitude-indicator/internal-roll-deg";
  Var *v10 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v10});
  index_map.insert({9, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "encoder_indicated-altitude-ft";
  sim_of_var = "/instrumentation/encoder/indicated-altitude-ft";
  Var *v11 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v11});
  index_map.insert({10, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "encoder_pressure-alt-ft";
  sim_of_var = "/instrumentation/encoder/pressure-alt-ft";
  Var *v12 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v12});
  index_map.insert({11, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "gps_indicated-altitude-ft";
  sim_of_var = "/instrumentation/gps/indicated-altitude-ft";
  Var *v13 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v13});
  index_map.insert({12, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "gps_indicated-ground-speed-kt";
  sim_of_var = "/instrumentation/gps/indicated-ground-speed-kt";
  Var *v14 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v14});
  index_map.insert({13, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "gps_indicated-vertical-speed";
  sim_of_var = "/instrumentation/gps/indicated-vertical-speed";
  Var *v15 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v15});
  index_map.insert({14, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "indicated-heading-deg";
  sim_of_var = "/instrumentation/heading-indicator/indicated-heading-deg";
  Var *v16 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v16});
  index_map.insert({15, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "magnetic-compass_indicated-heading-deg";
  sim_of_var = "/instrumentation/magnetic-compass/indicated-heading-deg";
  Var *v17 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v17});
  index_map.insert({16, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "slip-skid-ball_indicated-slip-skid";
  sim_of_var = "/instrumentation/slip-skid-ball/indicated-slip-skid";
  Var *v18 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v18});
  index_map.insert({17, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "turn-indicator_indicated-turn-rate";
  sim_of_var = "/instrumentation/turn-indicator/indicated-turn-rate";
  Var *v19 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v19});
  index_map.insert({18, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "vertical-speed-indicator_indicated-speed-fpm";
  sim_of_var = "/instrumentation/vertical-speed-indicator/indicated-speed-fpm";
  Var *v20 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v20});
  index_map.insert({19, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "flight_aileron";
  sim_of_var = "/controls/flight/aileron";
  Var *v21 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v21});
  index_map.insert({20, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "flight_elevator";
  sim_of_var = "/controls/flight/elevator";
  Var *v22 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v22});
  index_map.insert({21, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "flight_rudder";
  sim_of_var = "/controls/flight/rudder";
  Var *v23 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v23});
  index_map.insert({22, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "flight_flaps";
  sim_of_var = "/controls/flight/flaps";
  Var *v24 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v24});
  index_map.insert({23, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "engine_throttle";
  sim_of_var = "/controls/engines/engine/throttle";
  Var *v25 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v25});
  index_map.insert({24, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "current-engine_throttle";
  sim_of_var = "/controls/engines/current-engine/throttle";
  Var *v26 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v26});
  index_map.insert({25, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "switches_master-avionics";
  sim_of_var = "/controls/switches/master-avionics";
  Var *v27 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v27});
  index_map.insert({26, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "switches_starter";
  sim_of_var = "/controls/switches/starter";
  Var *v28 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v28});
  index_map.insert({27, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "active-engine_auto-start";
  sim_of_var = "/engines/active-engine/auto-start";
  Var *v29 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v29});
  index_map.insert({28, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "flight_speedbrake";
  sim_of_var = "/controls/flight/speedbrake";
  Var *v30 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v30});
  index_map.insert({29, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "c172p_brake-parking";
  sim_of_var = "/sim/model/c172p/brake-parking";
  Var *v31 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v31});
  index_map.insert({30, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "engine_primer";
  sim_of_var = "/controls/engines/engine/primer";
  Var *v32 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v32});
  index_map.insert({31, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "current-engine_mixture";
  sim_of_var = "/controls/engines/current-engine/mixture";
  Var *v33 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v33});
  index_map.insert({32, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "switches_master-bat";
  sim_of_var = "/controls/switches/master-bat";
  Var *v34 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v34});
  index_map.insert({33, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "switches_master-alt";
  sim_of_var = "/controls/switches/master-alt";
  Var *v35 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v35});
  index_map.insert({34, name_of_var});
  var_values.insert({name_of_var, 0});
  /***/
  name_of_var = "engine_rpm";
  sim_of_var = "/engines/engine/rpm";
  Var *v36 = new Var(sim_of_var, "<-", name_of_var);
  map.insert({name_of_var, v36});
  index_map.insert({35, name_of_var});
  var_values.insert({name_of_var, 0});
  singleton->reset(map, index_map, var_values);
}
/*
* The function resets the commands map.
*/
void FlightSimulator::resetCommands() {
  singleton->insertToCommands(OPEN_DATA_SERVER, new OpenServerCommand());
  singleton->insertToCommands(CONNECT_CONTROL_CLIENT, new ConnectCommand());
  singleton->insertToCommands(VAR, new DefineVarCommand());
  singleton->insertToCommands(PRINT, new PrintCommand());
  singleton->insertToCommands(SLEEP, new SleepCommand());
  singleton->insertToCommands(LOOP, new LoopCommand());
  singleton->insertToCommands(IF, new IfCommand());
}
/*
* The function reads a txt file and returns a queue of words and characters from the file.
*/
queue<string> FlightSimulator::lexer(string file_name) {
  queue<string> token;
  string line;
  ifstream f;
  f.open(file_name, ios::in);
  int i = 0;
  while (getline(f, line)) {
    i++;
    //dispose tabs
    size_t first = line.find_first_not_of('\t');
    if (string::npos != first) {
      line = line.substr(first, line.size() - first + 1);
    }
    //dispose spaces until the first char
    first = line.find_first_not_of(' ');
    if (string::npos != first) {
      line = line.substr(first, line.size() - first + 1);
    }
    //dispose spaces until the last char
    while (line[line.length() - 1] == ' ') {
      line = line.substr(0, line.length() - 1);
    }
    createQueue(token, line);
  }
  f.close();
  return token;
}
/*
* The function returns the number of chars that are an operator starting from line[index] to line[index+1].
* if there is no operator at line[index] returns 0.
*/
int FlightSimulator::isOperator(string line, int index) {
  char current = line[index];
  char next = line[index + 1];
  int returnValue = 0;
  if (current == '=' || current == '!' || current == '>' || current == '<') {
    returnValue++;
    if (next == '=') {
      returnValue++;
    }
  }
  return returnValue;
}
/*
* The function separates the line according to the operator that
 * appears in the line and updates the token accordingly.
*/
void FlightSimulator::searchForOperator(queue<string> &token, string line) {
  string tempLine = line, firstPart, secondPart, operate;
  int condition_index, size = tempLine.length();
  bool is_operator_found = false;
  for (int i = 0; i < size; i++) {
    //if isOperator == 0 this means that the char is not an operator
    if (isOperator(tempLine, i) > 0 && !is_operator_found) {
      is_operator_found = true;
      firstPart = tempLine.substr(0, i);
      condition_index = i;
    }
    if (tempLine[i] == '{') {
      int num_of_operator = isOperator(tempLine, condition_index);
      if (num_of_operator == 1) {
        operate = tempLine[condition_index];
        secondPart = tempLine.substr(condition_index + 1, i - firstPart.length() - 1);
      } else if (num_of_operator == 2) {
        operate = tempLine[condition_index];
        operate += tempLine[condition_index + 1];
        secondPart = tempLine.substr(condition_index + 2, i - firstPart.length() - 2);
      }
    }
  }
  token.push(firstPart);
  token.push(operate);
  token.push(secondPart);
  token.push("{");
}
/*
* The function creates a queue of words and characters and returns it.
*/
void FlightSimulator::createQueue(queue<string> &token, string line) {
  string current = "", pusher;
  int size = line.length(), i;
  for (i = 0; i < size; i++) {
    if (!token.empty()) {
      string in = token.back();
      if (token.back().compare(LOOP) == 0 || token.back().compare(IF) == 0) {
        line.erase(0, token.back().length() + 1);
        searchForOperator(token, line);
        break;
      }
    }
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
          current = "";
        }
        //if this = does not mean to assign somthing
        if (line[i + 1] == '=') {
          current += line[i];
          current += line[i + 1];
          i++;
          pusher = current;
          token.push(pusher);
          current = "";
          break;
        }
        //push the '='
        pusher = line[i];
        token.push(pusher);
        //after the '='
        pusher = line.substr(i + 1, line.length() - i);
        if (pusher[0] == ' ') {
          pusher = pusher.substr(1, pusher.length() - 1);
        }
        token.push(pusher);
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
          current = "";
        }
        break;
      }
      case ' ': {
        if (is_in_brackets) {
          break;
        }
        if (current.compare("") != 0) {
          pusher = current;
          token.push(pusher);
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
  }
}
/*
* The function gets a string and the index that the arrow is there and updates the tokes queue.
*/
void FlightSimulator::dealWithArrow(queue<string> &token, const string &line, string &current, int &i, string direction) {
  string pusher;
  //there was no space between the var name and the -> : the name var should be pushed into token
  if (current.compare(direction) != 0 && current.compare("") != 0) {
    pusher = current;
    token.push(pusher);
    current = "";
  }
  //current = ->
  current += line[i];
  current += line[i + 1];
  i++;
  //push ->
  pusher = current;
  token.push(pusher);
  current = "";
}
/*
* The function gets a string and the index that the open bracket is there and updates the tokes queue.
*/
void FlightSimulator::dealWithBrackets(queue<string> &token, string &line, string &current, int &i) {
  string pusher;
  bool is_first_valid_char = false;
  if (current.compare("") != 0) {
    //until the '('
    pusher = current;
    token.push(pusher);
  }
  current = "";
  int lastBracket = countBrackets(line);
  while (i < lastBracket - 1) {
    if (line[++i] == ' ') {
      if (!is_first_valid_char) {
        continue;
      } else {
        is_first_valid_char = true;
        current += line[i];
      }
    } else {
      is_first_valid_char = true;
      current += line[i];
    }
  }
  while (current[current.length() - 1] == ' ') {
    current = current.substr(0, current.length() - 1);
  }
  if (lastBracket == i) {
    token.push(current);
    current = "";
  }
}
/*
* The function returns the location of the last closing bracket.
*/
int FlightSimulator::countBrackets(string &line) {
  for (int i = line.length(); i > 0; i--) {
    if (line[i] == ')') {
      return i;
    }
  }
  return -1;
}
/*
 * The function gets a string and the index that the operator is there and updates the tokes queue.
 */
void FlightSimulator::dealWithOperator(queue<string> &token, const string &line, string &current, int &i) {
  string pusher;
  if (current.compare("") != 0) {
    pusher = current;
    token.push(pusher);
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
  current = "";
}
/*
* The function executes all the commands in the commands map.
*/
void FlightSimulator::parser(queue<string> &token) {
  while (!token.empty()) {
    string current = token.front();
    Command *c = singleton->getCommands()->at(current);
    if (c != NULL) {
      c->execute(token);
    }
  }
  singleton->setIsDone(true);
}
/*
* Destructor.
*/
FlightSimulator::~FlightSimulator() {
  delete singleton;
}
