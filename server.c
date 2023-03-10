#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


int main(){

  char *ip = "127.0.0.1";
  int port = 5566;

  int server_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_size;
  char buffer[1024];
  int n;

  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0){
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");

  memset(&server_addr, '\0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);

  n = bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if (n < 0){
    perror("[-]Bind error");
    exit(1);
  }
  printf("[x]Bind to the port number: %d\n", port);
char stop[10]="exit";
  listen(server_sock, 5);
  printf("Listening...\n");

  while(1){
    addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
    printf("[+]Client connected.\n");


  while(1){
    bzero(buffer, 1024);
    recv(client_sock, buffer, sizeof(buffer), 0);

  if(strcmp(stop,buffer)==0)
  {
     break;
  }
    printf("[+]Data Recieved: %s\n", buffer);
    int len = strlen(buffer);
    for(int i=0;i<len/2;i++)
    {
        char temp = buffer[i];
        buffer[i]=buffer[len-1-i];
        buffer[len-1-i]=temp;

    }

    printf("[+]Data Sent: %s\n", buffer);
    send(client_sock, buffer, strlen(buffer), 0);
  }
  close(client_sock);
    printf("[+]Client disconnected.\n\n");
    break;
  }
  return 0;
}