// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 8080 

int main(int argc, char const *argv[]) 
{ 
	int sock = 0, valread; 
	struct sockaddr_in serv_addr; 
	char *hello = "10 from client";
        int c;
        printf("enter operand\n");
        c = getchar();
        //char *opr = "+";
        int c1 = 0;
        int c2 = 0;
        printf("enter num1\n"); 
        scanf("%d",&c1);
        printf("enter num2\n");
        scanf("%d",&c2);
        //printf("enter operand\n");
        //c = getchar();
        int sumc = 0;
	char buffer[1024] = {0}; 
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
	{ 
		printf("\nInvalid address/ Address not supported \n"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{ 
		printf("\nConnection Failed \n"); 
		return -1; 
	} 
	send(sock , &c1 , sizeof(int) , 0 ); 
	printf("c1 message sent\n"); 
        send(sock , &c2 , sizeof(int) , 0 ); 
	printf("c2 message sent\n"); 
        send(sock , &c , sizeof(int) , 0 ); 
	printf("operand sent message sent\n"); 
	valread = read( sock , &sumc,sizeof(int)); 
	printf("output from server is %d\n",sumc ); 
	return 0; 
} 

