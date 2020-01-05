# Flight_Simulator
The program reads a text file with instructions, and operates as a compiler,
 meaning it's interprets the instructions into commands and operate them. 
 The instructions given in the text file are suppose to make an airplain fly by operating both as client and server,
sends and receives data from the flight gear simulator.  
The compilation process is done in two steps:
1. Lexer
2. Parser
### Lexer
Given a text file, the lexer separates the text into tokens that being inserted into a queue.
### Parser
Given a queue of tokens, the parser converts the tokens into the right commands and executes them.  
### Commands  
The legal instructions of the file text are:
  1. OpenDataServer(**port of server**)
  2. ConnectControl(**ip of client**, **port of client**)
  3. Var **var_name** -> or <- sim(**path of a simulator variable**)
  4. Print(**var_name** or **string** or an **expression of numbers or/and var_names**)
  5. Sleep(**number of miliseconds**)
  6. **var_name** = **number** or **expression of numbers or/and var_names**
  7. while **condition** {
  8. if **condition** { 
  
**conditoin** might be: **expression** </>/<=/>=/==/!= **expression**  
**expression** might be: any expression using variables that has been declared and the operators *,/,+,-.  

## How to run our program
First, install the flight gear simulator, you can use the following link: https://www.flightgear.org/download/main-program/ .  
Then, goes to the setting and add the following lines in the additoinal settings block:  
*--telnet=socket,in,10,127.0.0.1,5402,tcp --httpd=8080*  
*--generic=socket,out,10,127.0.0.1,5400,tcp,generic_small*  

Second, you should create two files:  
1. file_name.txt - set of legal instructions as mentioned above. The file name will be sent as an argument to the program.
2. generic_small.xml - data the simulator will send to the program.

Put those files in the same directory as the program and run the following commands in the terminal:  
_g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread_  
_./a.out file_name.txt_

When "Server is now listenting..." appears on the screen, open the flight gear simulator and press the button 'fly'.  
If connection has been made successfully, "Client is now connected to server" will appear on the screen.  
Now, all you have to do is just sit down and enjoy seeing the plain fly :)  

#### Versioning  
We used [Github](https://github.com/shiraz318/Flight_Simulator) for version control

#### Authors
Nili Cohen and Shiraz Berger.
