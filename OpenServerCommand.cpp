//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__OPENDATASERVER_CPP_
#define ex3__OPENDATASERVER_CPP_
#include <bits/basic_string.tcc>
#include "Command.h"
#include "Var.cpp"
#include "ex1.h"

void switchCase(int i, float value) {
  Singleton* singleton = Singleton::getSingleton();
  switch(i) {
    case 0: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("airspeed-indicator_indicated-speed-kt");
      v->setValue(value);
      break;
    }
    case 1: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("heading-indicator_offset-deg");
      v->setValue(value);
      break;
    }
    case 2: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("altimeter_indicated-altitude-ft");
      v->setValue(value);
      break;
    }
    case 3: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("altimeter_pressure-alt-ft");
      v->setValue(value);
      break;
    }
    case 4: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("attitude-indicator_indicated-pitch-deg");
      v->setValue(value);
      break;
    }
    case 5: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("attitude-indicator_indicated-roll-deg");
      v->setValue(value);
      break;
    }
    case 6: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("attitude-indicator_internal-pitch-deg");
      v->setValue(value);
      break;
    }
    case 7: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("attitude-indicator_internal-roll-deg");
      v->setValue(value);
      break;
    }
    case 8: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("encoder_indicated-altitude-ft");
      v->setValue(value);
      break;
    }
    case 9: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("encoder_pressure-alt-ft");
      v->setValue(value);
      break;
    }
    case 10: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("gps_indicated-altitude-ft");
      v->setValue(value);
      break;
    }
    case 11: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("gps_indicated-ground-speed-kt");
      v->setValue(value);
      break;
    }
    case 12: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("gps_indicated-vertical-speed");
      v->setValue(value);
      break;
    }
    case 13: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("indicated-heading-deg");
      v->setValue(value);
      break;
    }
    case 14: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("magnetic-compass_indicated-heading-deg");
      v->setValue(value);
      break;
    }
    case 15: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("slip-skid-ball_indicated-slip-skid");
      v->setValue(value);
      break;
    }
    case 16: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("turn-indicator_indicated-turn-rate");
      v->setValue(value);
      break;
    }
    case 17: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("vertical-speed-indicator_indicated-speed-fpm");
      v->setValue(value);
      break;
    }
    case 18: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("flight_aileron");
      v->setValue(value);
      break;
    }
    case 19: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("flight_elevator");
      v->setValue(value);
      break;
    }
    case 20: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("flight_rudder");
      v->setValue(value);
      break;
    }
    case 21: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("flight_flaps");
      v->setValue(value);
      break;
    }
    case 22: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("engine_throttle");
      v->setValue(value);
      break;
    }
    case 23: {
      Var* v = (Var*)singleton->symbol_table_simulator.at("engine_rpm");
      v->setValue(value);
      break;
    }
    default:
      break;
  }
}
void separateByComma(char *buffer) {

  Singleton* singleton = Singleton::getSingleton();
  string pusher, current_var_name;
  int i = 0, index_comma = 0, npos = (int) std::string::npos;
  string str = string(buffer);
  while ((index_comma = str.find(COMMA)) != npos) {
    pusher = str.substr(0, index_comma);
    //update the value in symbol-table-simulator
    current_var_name = singleton->index.at(i);
    Var* v = (Var*)singleton->symbol_table_simulator.at(current_var_name);
    //singleton->var_values.at(current_var_name) = atof(pusher.c_str());
    v->setValue(atof(pusher.c_str()));
    //switchCase(i, atof(pusher.c_str()));
    i++;
    str.erase(0, index_comma + 1);
  }
}
int readFromSim(int client_socket) {//reading from client
    while (true) {
      char buffer[LINE_SIZE] = {0};
      int valread = read(client_socket, buffer, LINE_SIZE);
      cout << buffer << endl;
      separateByComma(buffer);
    }
    return client_socket;
  }

  class OpenServerCommand : public Command {
   public:
    virtual void execute(queue<string> &token) {
      //Interpreter* interpreter = new Interpreter();
      Singleton* singleton = Singleton::getSingleton();
      cout << "I am executing in Open Data Server" << endl;
      //name of command
      token.pop();
      //parameter of command
      string expression = token.front();
      float port = ex1::cal(expression, singleton->var_values);
      //int port = atof(token.front().c_str());
      token.pop();
      int socketfd;
      sockaddr_in address;
      createAndBindSocket(port, socketfd, address);
      //making socket listen to the port
      if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
        exit(1);
      } else {
        std::cout << "Server is now listening ..." << std::endl;
      }
      int client_socket = acceptAndRead(socketfd, address);

    }

    int acceptAndRead(int socketfd, sockaddr_in &address) const {// accepting a client
      int client_socket = accept(socketfd, (struct sockaddr *) &address,
                                 (socklen_t *) &address);
      if (client_socket == -1) {
        cerr << "Error accepting client" << endl;
        exit(1);
      }
      close(socketfd); //closing the listening socket
      thread thread_in(readFromSim, client_socket);
      thread_in.join();
      return readFromSim(client_socket);

    }

    void createAndBindSocket(int port, int &socketfd, sockaddr_in &address) const {
      socketfd = socket(AF_INET, SOCK_STREAM, 0);//create socket
      if (socketfd == -1) {
        //error
        cerr << "Could not create a socket" << endl;
        exit(1);
      }
      //bind socket to IP address
      // we first need to create the sockaddr obj.
      //in means IP4
      address.sin_family = AF_INET;
      address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
      address.sin_port = htons(port);
      //we need to convert our number
      // to a number that the network understands.
      //the actual bind command
      if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        cerr << "Could not bind the socket to an IP" << endl;
        exit(1);
      }
    }
  };
#endif