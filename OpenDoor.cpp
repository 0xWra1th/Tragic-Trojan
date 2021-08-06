/*
Apparently writing backdoors in C/C++ is a lot harder but brings benefits that balance the scales.
Benefits:
    - AV evasion because it is harder to decompile/reverse.
    - Analysis evasion for the same reason.
    - Lower level code allows for more portability (No need to install python on the victim)
*/

#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 44444
#define REMOTE_HOST "127.0.0.1"
   
int main(int argc, char const *argv[])
{
    // Socket Settings and Buffer
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "(Client): Hello\n(Server):";
    char buffer[1024] = {0};

    // Connection Setup
    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, REMOTE_HOST, &serv_addr.sin_addr);
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // Functionality Loop
    while(true){
        send(sock , hello , strlen(hello) , 0 );
        valread = read( sock , buffer, 1024);
        printf("%s\n",buffer );
    }
    return 0;
}