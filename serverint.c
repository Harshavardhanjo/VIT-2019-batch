// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <stdlib.h>
#define PORT 8080 
int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    char *hello = "ya waste from server"; 
       
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
    int num1 = 0;
    int num2 = 0;
    int opr;
    int sum;
    valread = read( new_socket , &num1,sizeof(int)); 
    printf("num1 is %d\n",num1);
    valread = read( new_socket , &num2,sizeof(int)); 
    printf("num2 is   %d\n",num2 );
    valread = read( new_socket , &opr ,sizeof(int)); 
    printf("operand is   %c\n",opr );
    printf("ascii is %d\n",opr);
    switch (opr)
      {
         case 43:
             printf("operand is in switch +\n");
             sum = num1 + num2;
             break;
         case 42:
             printf("operand is in switch *\n");
             sum = num1 * num2;
             break;
         case 45:
             printf("operand is in switch -\n");
             sum = num1 - num2;
             break;
         case 47:
             printf("operand is in switch /\n");
             sum = num1 / num2;
             break;
       }
    printf("server  is %d\n",sum);
    send(new_socket , &sum , sizeof(int) , 0 ); 
    printf("message sent\n"); 
    return 0; 
} 
