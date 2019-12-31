//
// Created by shiraz and nili on 12.12.2019.
//
#include "OpenServerCommand.h"
int OpenServerCommand::client_socket_in = 0;
/*
* The function opens threads.
*/
void OpenServerCommand::execute(queue<string> &token) {
  token.pop();
  //parameter of command
  string expression = token.front();
  float port = ex1::cal(expression, *singleton->getVarValues());
  token.pop();
  thread thread_in_1(openSocketOut, port);
  thread_in_1.join();
  thread thread_in_2(readFromSim, client_socket_in);
  thread_in_2.detach();
  return;
}
/*
* The function opens a socket, bind, listen and accept.
*/
void OpenServerCommand::openSocketOut(float port) {
  int socketfd;
  sockaddr_in address;
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd == -1) {
    cerr << "Could not create a socket" << endl;
    exit(1);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);
  if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
    cerr << "Could not bind the socket to an IP" << endl;
    exit(1);
  }
  if (listen(socketfd, 5) == -1) {
    cerr << "Error during listening command" << endl;
    exit(1);
  }
  client_socket_in = accept(socketfd, (struct sockaddr *) &address,
                            (socklen_t *) &address);
  if (client_socket_in == -1) {
    cerr << "Error accepting client" << endl;
    exit(1);
  }
  close(socketfd);
}
/*
* The function updates the values of the symbol table of the simulator if needed.
*/
void OpenServerCommand::updateValuesInMaps(int i, string &current_value, string &current_var_name) {
  Singleton *singleton = Singleton::getSingleton();
  //update the value in symbol-table-simulator
  current_var_name = singleton->getIndex()->at(i);
  Var *v = (Var *) singleton->getSymbolTableSimulator()->at(current_var_name);
  if (v->getDirection().compare("<-") == 0) {
    v->setValue(atof(current_value.c_str()));
    Var::updateSymbolTableProg(v->getSim(), atof(current_value.c_str()));
  }
}
/*
* The function separate a string by commas and call the function that update the
 * values of the symbol table simulator with the matching value.
*/
void OpenServerCommand::separateByComma(string buffer) {
  string current_value, current_var_name, str = string(buffer);
  int i = 0, index_comma = 0, npos = (int) std::string::npos;
  while ((index_comma = str.find(COMMA)) != npos) {
    current_value = str.substr(0, index_comma);
    updateValuesInMaps(i, current_value, current_var_name);
    i++;
    if (index_comma != 0) {
      str.erase(0, index_comma + 1);
    }
  }
  current_value = str;
  updateValuesInMaps(i, current_value, current_var_name);
}
/*
* The function reads values separated by comma from a simulator(client) and updates them accordingly.
*/
int OpenServerCommand::readFromSim(int client_socket_in1) {
  string buffer_temp = "";
  Singleton *singleton = Singleton::getSingleton();
  while (!singleton->getIsDone()) {
    char buffer[LINE_SIZE] = {0};
    int valread = read(client_socket_in1, buffer, LINE_SIZE);
    int i = 0;
    while (i < valread) {
      if (buffer[i] == '\n') {
        separateByComma(buffer_temp);
        buffer_temp = "";
        i++;
        continue;
      }
      buffer_temp += buffer[i];
      i++;
    }
  }
  return 1;
}
/*
* Destructor.
*/
OpenServerCommand:: ~OpenServerCommand() {}
