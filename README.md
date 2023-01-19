# TCP-Client-Server-Implementation

```
Problem Statement:
The problem is to implement a client-server user-level application using sockets API in C. 
The server accepts a string from the client and replies with the reverse string. 
For example, when a client sends “NITC”, the Server replies with “CTIN”.
Both server and client(s) have to output both sending & receiving strings on the terminal.
```
Files
1. server.c 
2. client.c
```
To run the program, 
1. Compile the .c programs using GCC compiler for C in two seperate terminals
   $ gcc client.c -o client
   $ gcc server.c -o server
2. Run the server program first followed by client program, 
    when server prints the message "listening"
   $ ./server
   $ ./client 
```
