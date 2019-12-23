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

class OpenServerCommand : public Command {
 private:
  Singleton *singleton = Singleton::getSingleton();
 public:
  virtual void execute(queue<string> &token) {
    cout << "I am executing in Open Data Server" << endl;
    return;
  }
  void openSocketOut(float port) {
    int socketfd;
    sockaddr_in address;
    socketfd = socket(AF_INET, SOCK_STREAM, 0);//create socket
    if (socketfd == -1) {
      //error
      cerr << "Could not create a socket" << endl;
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
    }
    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
      cerr << "Error during listening command" << endl;
    } else {
      cout << "Server is now listening ..." << endl;
    }
    client_socket_in = accept(socketfd, (struct sockaddr *) &address,
                              (socklen_t *) &address);
    if (client_socket_in == -1) {
      cerr << "Error accepting client" << endl;
    }
    close(socketfd);
  }
  void updateSymbolTableProg( string sim, float value) {
    string otherSim = "";
    mutex_lock.lock();
    for (auto& it: singleton->symbol_table_program) {
      Var *v = (Var*)it.second;
      otherSim = v->getSim();
      if (sim.compare(otherSim) == 0) {
        string name = it.first;
        singleton->var_values.at(name) = value;
        break;
      }
    }
    mutex_lock.unlock();
  }
  void separateByComma(string buffer) {
    //Singleton *singleton = Singleton::getSingleton();
    string current_value, current_var_name, str = string(buffer);
    int i = 0, index_comma = 0, npos = (int) std::string::npos;
    while ((index_comma = str.find(COMMA)) != npos) {
     // mutex_lock.lock();
      current_value = str.substr(0, index_comma);
      //update the value in symbol-table-simulator
      current_var_name = singleton->index.at(i);
      Var *v = (Var *) singleton->symbol_table_simulator.at(current_var_name);
      if (v->getDirection().compare("<-") == 0) {
        v->setValue(atof(current_value.c_str()));
        updateSymbolTableProg(v->getSim(), atof(current_value.c_str()));
      }
      i++;
      if (index_comma != 0) {
        str.erase(0, index_comma + 1);
      }
     // mutex_lock.unlock();
    }
    current_value = str;
    //update the value in symbol-table-simulator
    current_var_name = singleton->index.at(i);
    Var *v = (Var *) singleton->symbol_table_simulator.at(current_var_name);
    if (v->getDirection().compare("<-") == 0) {
      v->setValue(atof(current_value.c_str()));
      updateSymbolTableProg(v->getSim(), atof(current_value.c_str()));
      }
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
};
#endif