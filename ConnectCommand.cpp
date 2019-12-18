//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__CONNECTCOMANND_CPP_
#define ex3__CONNECTCOMANND_CPP_
#include "Command.h"
#include "Var.cpp"

class ConnectCommand : public Command {
 public:
  virtual void execute(queue<string> &token) {
    cout << "I am executing in Connect Control Command" << endl;
    //name of command
    token.pop();
    //ip and port
    string arguments = token.front();
    string ipTemp = "", portTemp = "";
    int i = 0;
    for (; arguments[i] != '"'; i++) {
    }
    while(arguments[i]!=',') {
      ipTemp+= arguments[i++];
    }
    const char *ip = ipTemp.c_str();
    while(i < arguments.length() - 1) {
      portTemp += arguments[++i];
    }
    //port
    int port = ex1::cal(portTemp);
    //int port = atof(token.front().c_str());
    token.pop();
//    int client_socket = createAndConnect(ip, port);
//
//    //if here we made a connection
//      char hello[] = "set controls/flight/rudder -1";
//      int is_sent = send(client_socket , hello , strlen(hello) , 0 );
//      if (is_sent == -1) {
//        std::cout<<"Error sending message"<<std::endl;
//      } else {
//        std::cout<<"Hello message sent to server" <<std::endl;
//      }
//      char buffer[LINE_SIZE] = {0};
//      int valread = read( client_socket , buffer, LINE_SIZE);
//      std::cout<<buffer<<std::endl;
//      close(client_socket);
//    }
//  int createAndConnect(const char *ip, int port) const {//create socket
//    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
//    if (client_socket == -1) {
//      //error
//      cerr << "Could not create a socket" << endl;
//      exit(1);
//    }
//
//    //We need to create a sockaddr obj to hold address of server
//    sockaddr_in address; //in means IP4
//    address.sin_family = AF_INET;//IP4
//    address.sin_addr.s_addr = inet_addr(ip);  //the localhost address
//    address.sin_port = htons(port);
//    //we need to convert our number (both port & localhost)
//// to a number that the network understands.
//
//    // Requesting a connection with the server on local host with port 8081
//    int is_connect = connect(client_socket, (struct sockaddr *)&address, sizeof(address));
//    if (is_connect == -1) {
//      cerr << "Could not connect to host server" << endl;
//      exit(1);
//    } else {
//      cout << "Client is now connected to server" << endl;
//    }
//    return client_socket;
//  }
  }
};
#endif