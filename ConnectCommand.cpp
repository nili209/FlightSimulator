//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__CONNECTCOMANND_CPP_
#define ex3__CONNECTCOMANND_CPP_
#include <cstring>
#include "Command.h"
#include "Var.cpp"
static int client_socket = 0;
class ConnectCommand : public Command {
 public:
  virtual void execute(queue<string> &token) {
    Singleton *singleton = Singleton::getSingleton();
    cout << "I am executing in Connect Control Command" << endl;
  }
  int writeMessages() {//if here we made a connection
    Singleton* singleton = Singleton::getSingleton();
    while(true) {
      if (!singleton->isMessagesEmpty()) {
        string m = singleton->getMessage();
        const char* message = m.c_str();
        int is_sent = send(client_socket , message , strlen(message) , 0 );

        if (is_sent == -1) {
          cout << "Error sending message" << endl;
        } else {
          cout << "Hello message sent to server" << endl;
          cout << "message = "<< message << endl;
        }
      } else {
        this_thread::sleep_for(chrono::milliseconds(10));
      }
    }
    return client_socket;
  }
  void Connect(const char *ip, int port) {
    Singleton* singleton = Singleton::getSingleton();
    client_socket= socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
      //error
      cerr << "Could not create a socket" << endl;
    }

    //We need to create a sockaddr obj to hold address of server
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;//IP4
    address.sin_addr.s_addr = inet_addr(ip);  //the localhost address
    address.sin_port = htons(port);
    //we need to convert our number (both port & localhost)
    // to a number that the network understands.

    // Requesting a connection with the server on local host with port 8081
    int is_connect = connect(client_socket, (struct sockaddr *)&address, sizeof(address));
    if (is_connect == -1) {
      cerr << "Could not connect to host server" << endl;
    } else {
      cout << "Client is now connected to server" << endl;
    }
    //close(client_socket);
  }
};
#endif