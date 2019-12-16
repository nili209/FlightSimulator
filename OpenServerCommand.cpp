//
// Created by shiraz and nili on 12.12.2019.
//
#ifndef ex3__OPENDATASERVER_CPP_
#define ex3__OPENDATASERVER_CPP_
#include <cstring>
#include "Command.h"
#include "Var.cpp"
int readFromSim(int client_socket)  {//reading from client
  while(true) {
    char buffer[LINE_SIZE] = {0};
    int valread = read(client_socket, buffer, LINE_SIZE);
    cout << buffer << endl;
  }
  return client_socket;
}
class OpenServerCommand : public Command {
 public:
  virtual void execute(queue<string> &token, unordered_map<string, Command *> &commands, unordered_map<string, Command *> &symbol_table_program) {
    cout << "I am executing in Open Data Server" << endl;
    //name of command
    token.pop();
    //parameter of command
    int port = atof(token.front().c_str());
    token.pop();
//    int socketfd;
//    sockaddr_in address;
//    createAndBindSocket(port, socketfd, address);
//    //making socket listen to the port
//    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
//      std::cerr << "Error during listening command" << std::endl;
//      exit(1);
//    } else {
//      std::cout << "Server is now listening ..." << std::endl;
//    }
//    int client_socket = acceptAndRead(socketfd, address);
//    write(client_socket);
//
//  }
//  void write(int client_socket) const {//writing back to client
//    char *hello = "Hello, I can hear you! \n";
//    send(client_socket, hello, strlen(hello), 0);
//    cout << "Hello message sent\n" << endl;
//  }
//  int acceptAndRead(int socketfd, sockaddr_in &address) const {// accepting a client
//    int client_socket = accept(socketfd, (struct sockaddr *) &address,
//                               (socklen_t *) &address);
//    if (client_socket == -1) {
//      cerr << "Error accepting client" << endl;
//      exit(1);
//    }
//    close(socketfd); //closing the listening socket
//    thread thread_in(readFromSim,client_socket);
//    thread_in.join();
//    return readFromSim(client_socket);
//
//  }
//
//  void createAndBindSocket(int port, int &socketfd, sockaddr_in &address) const {
//    socketfd = socket(AF_INET, SOCK_STREAM, 0);//create socket
//    if (socketfd == -1) {
//      //error
//      cerr << "Could not create a socket" << endl;
//      exit(1);
//    }
//    //bind socket to IP address
//// we first need to create the sockaddr obj.
////in means IP4
//    address.sin_family = AF_INET;
//    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
//    address.sin_port = htons(port);
//    //we need to convert our number
//// to a number that the network understands.
////the actual bind command
//    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
//      cerr << "Could not bind the socket to an IP" << endl;
//      exit(1);
//    }
  }
};
#endif