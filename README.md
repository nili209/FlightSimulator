# Flight_Simulator
The program reads instructions from a text file, and operates as a compile.  
 That means that it interprets the instructions, converts them into commands, and runs them. 
 The instructions given in the text file are supposed to make an airplane fly by operating both as a client and as a server,
sending and receiving data from the flight gear simulator.  
The compilation process is done in two steps:
1. A Lexer
2. A Parser
### A Lexer
Given a text file, the lexer separates the text into tokens that are then inserted into a queue.
### A Parser
Given a queue of tokens, the parser converts the tokens into the correct commands and executes them.  
### Commands  
The legal instructions of the file text are:
  1. OpenDataServer(**server's port**)
  2. ConnectControl(**client's ip**, **client's port**)
  3. Var **var_name** -> or <- sim(**a simulator's variable path**)
  4. Print(**var_name** or **string** or **expression of numbers or/and var_names**)
  5. Sleep(**number of miliseconds**)
  6. **var_name** = **number** or **expression of numbers or/and var_names**
  7. while **condition** {
  8. if **condition** { 
  
**condition** might be: **expression** </>/<=/>=/==/!= **expression**  
**expression** might be: any expression using variables that has been declared and the operators *,/,+,-.  

## How to run our program
### Installation  
First, to install the flight gear simulator, use the following link: https://www.flightgear.org/download/main-program/.  
Then, go to the setting and add the following lines in the additional settings block:  
*--telnet=socket,in,10,127.0.0.1,5402,tcp --httpd=8080*  
*--generic=socket,out,10,127.0.0.1,5400,tcp,generic_small*  
### Implementation  
Second, you should create two files:  
1. file_name.txt - set of legal instructions as detailed above. The file name is sent as an argument to the program.
2. generic_small.xml - data the simulator will send to the program.
You can see examples of those files under the names fly.txt, generic_small.xml.  

Put those files in the same directory as the program and run the following commands in the terminal:  
_g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread_  
_./a.out file_name.txt_

When "Server is now listening..." appears on the screen, open the flight gear simulator and press the 'fly' button.  
If the server and the client have connected successfully, the message "Client is now connected to server" will appear on the screen.  
Now, all you have to do is sit down and enjoy the view :)  

#### Versioning  
We used [Github](https://github.com/shiraz318/Flight_Simulator) for version control

#### Authors
Nili Cohen and Shiraz Berger.
