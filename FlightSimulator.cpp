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
 private:
  bool is_in_brackets = false;
 public:
  Singleton* singleton;
  FlightSimulator() {
    singleton = Singleton::getSingleton();
    resetCommands();
    resetSimulatorMap();
  };
  void resetSimulatorMap() {
    unordered_map<string, Command*> map;
    unordered_map<int, string> index_map;
    unordered_map<string, float> var_values;
    string name_of_var = "";
    string sim_of_var = "";
    /***/
    Var *v1 = new Var("/instrumentation/airspeed-indicator/indicated-speed-kt", "<-",
                      "airspeed-indicator_indicated-speed-kt");
    map.insert({"airspeed-indicator_indicated-speed-kt", v1});
    index_map.insert({0, "airspeed-indicator_indicated-speed-kt"});
    var_values.insert({"airspeed-indicator_indicated-speed-kt", 0});
    /***/
    Var *v2 = new Var("/sim/time/warp", "<-", "time_warp");
    map.insert({"time_warp", v2});
    index_map.insert({1, "time_warp"});
    var_values.insert({"time_warp", 0});
    /***/
    Var *v3 = new Var("/controls/switches/magnetos", "<-", "switches_magnetos");
    map.insert({"switches_magnetos", v3});
    index_map.insert({2, "switches_magnetos"});
    var_values.insert({"switches_magnetos", 0});
    /***/
    Var *v4 = new Var("/instrumentation/heading-indicator/offset-deg", "<-", "heading-indicator_offset-deg");
    map.insert({"heading-indicator_offset-deg", v4});
    index_map.insert({3, "heading-indicator_offset-deg"});
    var_values.insert({"heading-indicator_offset-deg", 0});
    /***/
    Var *v5 = new Var("/instrumentation/altimeter/indicated-altitude-ft", "<-", "altimeter_indicated-altitude-ft");
    map.insert({"altimeter_indicated-altitude-ft", v5});
    index_map.insert({4, "altimeter_indicated-altitude-ft"});
    var_values.insert({"altimeter_indicated-altitude-ft", 0});
    /***/
    Var *v6 = new Var("/instrumentation/altimeter/pressure-alt-ft", "<-", "altimeter_pressure-alt-ft");
    map.insert({"altimeter_pressure-alt-ft", v6});
    index_map.insert({5, "altimeter_pressure-alt-ft"});
    var_values.insert({"altimeter_pressure-alt-ft", 0});
    /***/
    Var *v7 = new Var("/instrumentation/attitude-indicator/indicated-pitch-deg", "<-",
                      "attitude-indicator_indicated-pitch-deg");
    map.insert({"attitude-indicator_indicated-pitch-deg", v7});
    index_map.insert({6, "attitude-indicator_indicated-pitch-deg"});
    var_values.insert({"attitude-indicator_indicated-pitch-deg", 0});
    /***/
    Var *v8 = new Var("/instrumentation/attitude-indicator/indicated-roll-deg", "<-",
                      "attitude-indicator_indicated-roll-deg");
    map.insert({"attitude-indicator_indicated-roll-deg", v8});
    index_map.insert({7, "attitude-indicator_indicated-roll-deg"});
    var_values.insert({"attitude-indicator_indicated-roll-deg", 0});
    /***/
    Var *v9 = new Var("/instrumentation/attitude-indicator/internal-pitch-deg", "<-",
                      "attitude-indicator_internal-pitch-deg");
    map.insert({"attitude-indicator_internal-pitch-deg", v9});
    index_map.insert({8, "attitude-indicator_internal-pitch-deg"});
    var_values.insert({"attitude-indicator_internal-pitch-deg", 0});
    /***/
    Var *v10 = new Var("/instrumentation/attitude-indicator/internal-roll-deg", "<-",
                       "attitude-indicator_internal-roll-deg");
    map.insert({"attitude-indicator_internal-roll-deg", v10});
    index_map.insert({9, "attitude-indicator_internal-roll-deg"});
    var_values.insert({"attitude-indicator_internal-roll-deg", 0});
    /***/
    Var *v11 = new Var("/instrumentation/encoder/indicated-altitude-ft", "<-", "encoder_indicated-altitude-ft");
    map.insert({"encoder_indicated-altitude-ft", v11});
    index_map.insert({10, "encoder_indicated-altitude-ft"});
    var_values.insert({"encoder_indicated-altitude-ft", 0});
    /***/
    Var *v12 = new Var("/instrumentation/encoder/pressure-alt-ft", "<-", "encoder_pressure-alt-ft");
    map.insert({"encoder_pressure-alt-ft", v12});
    index_map.insert({11, "encoder_pressure-alt-ft"});
    var_values.insert({"encoder_pressure-alt-ft", 0});
    /***/
    Var *v13 = new Var("/instrumentation/gps/indicated-altitude-ft", "<-", "gps_indicated-altitude-ft");
    map.insert({"gps_indicated-altitude-ft", v13});
    index_map.insert({12, "gps_indicated-altitude-ft"});
    var_values.insert({"gps_indicated-altitude-ft", 0});
    /***/
    Var *v14 = new Var("/instrumentation/gps/indicated-ground-speed-kt", "<-",
                       "gps_indicated-ground-speed-kt");
    map.insert({"gps_indicated-ground-speed-kt", v14});
    index_map.insert({13, "gps_indicated-ground-speed-kt"});
    var_values.insert({"gps_indicated-ground-speed-kt", 0});
    /***/
    Var *v15 = new Var("/instrumentation/gps/indicated-vertical-speed", "<-",
                       "gps_indicated-vertical-speed");
    map.insert({"gps_indicated-vertical-speed", v15});
    index_map.insert({14, "gps_indicated-vertical-speed"});
    var_values.insert({"gps_indicated-vertical-speed", 0});
    /***/
    Var *v16 = new Var("/instrumentation/heading-indicator/indicated-heading-deg", "<-",
                       "indicated-heading-deg");
    map.insert({"indicated-heading-deg", v16});
    index_map.insert({15, "indicated-heading-deg"});
    var_values.insert({"indicated-heading-deg", 0});
    /***/
    Var *v17 = new Var("/instrumentation/magnetic-compass/indicated-heading-deg", "<-",
                       "magnetic-compass_indicated-heading-deg");
    map.insert({"magnetic-compass_indicated-heading-deg", v17});
    index_map.insert({16, "magnetic-compass_indicated-heading-deg"});
    var_values.insert({"magnetic-compass_indicated-heading-deg", 0});
    /***/
    Var *v18 = new Var("/instrumentation/slip-skid-ball/indicated-slip-skid", "<-",
                       "slip-skid-ball_indicated-slip-skid");
    map.insert({"slip-skid-ball_indicated-slip-skid", v18});
    index_map.insert({17, "slip-skid-ball_indicated-slip-skid"});
    var_values.insert({"slip-skid-ball_indicated-slip-skid", 0});
    /***/
    Var *v19 = new Var("/instrumentation/turn-indicator/indicated-turn-rate", "<-", "turn-indicator_indicated-turn-rate");
    map.insert({"turn-indicator_indicated-turn-rate", v19});
    index_map.insert({18, "turn-indicator_indicated-turn-rate"});
    var_values.insert({"turn-indicator_indicated-turn-rate", 0});
    /***/
    Var *v20 = new Var("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", "<-", "vertical-speed-indicator_indicated-speed-fpm");
    map.insert({"vertical-speed-indicator_indicated-speed-fpm", v20});
    index_map.insert({19, "vertical-speed-indicator_indicated-speed-fpm"});
    var_values.insert({"vertical-speed-indicator_indicated-speed-fpm", 0});
    /***/
    Var *v21 = new Var("/controls/flight/aileron", "<-", "flight_aileron");
    map.insert({"flight_aileron", v21});
    index_map.insert({20, "flight_aileron"});
    var_values.insert({"flight_aileron", 0});
    /***/
    Var *v22 = new Var("/controls/flight/elevator", "<-", "flight_elevator");
    map.insert({"flight_elevator", v22});
    index_map.insert({21, "flight_elevator"});
    var_values.insert({"flight_elevator", 0});
    /***/
    Var *v23 = new Var("/controls/flight/rudder", "<-", "flight_rudder");
    map.insert({"flight_rudder", v23});
    index_map.insert({22, "flight_rudder"});
    var_values.insert({"flight_rudder", 0});
    /***/
    Var *v24 = new Var("/controls/flight/flaps", "<-", "flight_flaps");
    map.insert({"flight_flaps", v24});
    index_map.insert({23, "flight_flaps"});
    var_values.insert({"flight_flaps", 0});
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
    int i = 0;
    while (getline(f, line)) {
      i++;
      //dispose tabs
      size_t first = line.find_first_not_of('\t');
      if (string::npos != first) {
        size_t last = line.size();
        line = line.substr(first, line.size() - first + 1);
      }
      createQueue(token, line);
    }
    f.close();
    return token;
  }
  int isOperator(string line, int index) {
    char current = line[index];
    char next = line[index+1];
    int returnValue = 0;
    if (current == '=' || current == '!' || current == '>' || current == '<') {
      returnValue++;
      if (next == '=') {
        returnValue++;
      }
    }
    return returnValue;
  }
  void searchForOperator(queue<string> &token, string line) {
    string tempLine = line;
    string firstPart;
    string secondPart, operate;
    int condition_index;
    bool is_found = false;
    for (int i = 0; i < tempLine.length(); i++) {
      //if isOperator == 0 this means that the char is not an operator
      if (isOperator(tempLine, i) > 0 && !is_found) {
        is_found = true;
        firstPart = tempLine.substr(0, i);
        condition_index = i;
      }
      if(tempLine[i] == '{') {
        if(isOperator(tempLine, condition_index) == 1) {
          operate = tempLine[condition_index];
          secondPart = tempLine.substr(condition_index+1, i-firstPart.length()-1);
        } else if (isOperator(tempLine, condition_index) == 2) {
          operate = tempLine[condition_index];
          operate += tempLine[condition_index+1];
          secondPart = tempLine.substr(condition_index+2, i-firstPart.length()-2);
        }
      }
    }
    token.push(firstPart);
    cout<<firstPart<<endl;
    token.push(operate);
    cout<<operate<<endl;
    token.push(secondPart);
    cout<<secondPart<<endl;
    token.push("{");
    cout<<"{"<<endl;
  }
  void createQueue(queue<string> &token, string line) {
    string current = "", pusher;
    int index = 0;
    for (int i = 0; i < line.length(); i++) {
      if (!token.empty()) {
        string in = token.back();
        if (token.back().compare(LOOP) == 0 || token.back().compare(IF) == 0) {
          line.erase(0, token.back().length() +1);
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
          if (is_in_brackets) {
            break;
          }
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
    }
    current = "";
    while(line[++i] != ')') {
      current += line[i];
    }
    token.push(current);
      current = "";
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
    //push the expression after the operator
    //keep reading until the {
  }
  void printSimulatorVar() {
    for (auto& it: Singleton::symbol_table_simulator) {
      // Do stuff
      Var *v = (Var*)it.second;
      cout << it.first<< "=" << v->getValue()<<endl;
    }
  }
  void parser(queue<string> &token) {
    int i = 0;
    thread thread_in_1;
    thread thread_in_2;
    thread thread_out_2;
    thread thread_out_1;
    while (!token.empty()) {
      i++;
      string current = token.front();
      if(current.compare(OPEN_DATA_SERVER) == 0) {
        Command *c = singleton->commands.at(current);
        OpenServerCommand c1 = *((OpenServerCommand*)c);
        //name of command
        token.pop();
        //parameter of command
        string expression = token.front();
        float port = ex1::cal(expression, singleton->var_values);
        token.pop();
        thread thread_in_1(&OpenServerCommand::openSocketOut, ref(c1),  port);
        thread_in_1.join();
        thread thread_in_2(&OpenServerCommand::readFromSim, ref(c1),client_socket_in);
        thread_in_2.detach();
        printSimulatorVar();
      }
      if(current.compare(CONNECT_CONTROL_CLIENT) == 0) {
        Command *com = singleton->commands.at(current);
        ConnectCommand c2 = *((ConnectCommand*)com);
        //name of command
        token.pop();
        mutex_lock.lock();
        //ip and port
        string arguments = token.front();
        string ipTemp = "", portTemp = "";
        int i = 0;
        for (; arguments[i] != '"'; i++) {
        }
        while (arguments[i] != ',') {
          ipTemp += arguments[i++];
        }
        //remoove the ""
        ipTemp = ipTemp.substr(1, ipTemp.length() -2);
        const char *ip = ipTemp.c_str();
        while (i < arguments.length()-1) {
          i++;
          portTemp += arguments[i];

        }
        //port
        int port = ex1::cal(portTemp, singleton->var_values);
        mutex_lock.unlock();
        token.pop();
        thread thread_out_1(&ConnectCommand::Connect, ref(c2), ip, port);
        thread_out_1.join();
        thread thread_out_2(&ConnectCommand::writeMessages, ref(c2));
        thread_out_2.detach();
      }
      Command *c = singleton->commands.at(current);
      int i = 0;
      if (c != NULL) {
        i++;
        c->execute(token);
      }
    }
  }
};
#endif
