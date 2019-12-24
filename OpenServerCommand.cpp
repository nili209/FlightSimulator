//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__OPENDATASERVER_CPP_
#define ex3__OPENDATASERVER_CPP_
#include <bits/basic_string.tcc>
#include <future>
#include "Command.h"
#include "Var.cpp"
#include "ex1.h"
static int client_socket_in;
void openSocketOut(float port) {
  int socketfd;
  sockaddr_in address;
  socketfd = socket(AF_INET, SOCK_STREAM, 0);//create socket
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
  } else {
    cout << "Server is now listening ..." << endl;
  }
  client_socket_in = accept(socketfd, (struct sockaddr *) &address,
                            (socklen_t *) &address);
  if (client_socket_in == -1) {
    cerr << "Error accepting client" << endl;
    exit(1);
  }
  close(socketfd);
}
void updateValuesInMaps(const string &str,int i,int index_comma,string &current_value,string &current_var_name) {
  Singleton* singleton = Singleton::getSingleton();
  //update the value in symbol-table-simulator
  current_var_name = singleton->getIndex()->at(i);
  Var *v = (Var *) singleton->getSymbolTableSimulator()->at(current_var_name);
  if (v->getDirection().compare("<-") == 0) {
    v->setValue(atof(current_value.c_str()));
    Var::updateSymbolTableProg(v->getSim(), atof(current_value.c_str()));
  }
}
void separateByComma(string buffer) {
  string current_value, current_var_name, str = string(buffer);
  int i = 0, index_comma = 0, npos = (int) std::string::npos;
  while ((index_comma = str.find(COMMA)) != npos) {
    current_value = str.substr(0, index_comma);
    updateValuesInMaps(str, i, index_comma, current_value, current_var_name);
    i++;
    if (index_comma != 0) {
      str.erase(0, index_comma + 1);
    }
  }
  current_value = str;
  updateValuesInMaps(str, i, index_comma, current_value, current_var_name);
}

int readFromSim(int client_socket_in) {//reading from client
  int index_of_n = 0;
  string buffer_temp = "";
  while (true) {
    char buffer[LINE_SIZE] = {0};
    int valread = read(client_socket_in, buffer, LINE_SIZE);
    int i = 0;
    while (i < valread) {
      if (buffer[i] == '\n') {
        cout << buffer_temp << endl;
        separateByComma(buffer_temp);
        buffer_temp = "";
        i++;
        continue;
      }
      buffer_temp += buffer[i];
      i++;
    }
  }
  return client_socket_in;
}
class OpenServerCommand : public Command {
 private:
  Singleton *singleton = Singleton::getSingleton();
 public:
  virtual void execute(queue<string> &token) {
    cout << "I am executing in Open Data Server" << endl;
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
  virtual ~OpenServerCommand(){};
};
#endif