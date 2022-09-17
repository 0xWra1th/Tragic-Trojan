/*
Apparently writing backdoors in C/C++ is a lot harder but brings benefits that balance the scales.
Benefits:
    - AV evasion because it is harder to decompile/reverse.
    - Analysis evasion for the same reason.
    - Lower level code allows for more portability (No need to install python on the victim)
*/

#include <stdio.h>
#include <sstream>
#include <winsock2.h>

void openup()
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    char *message;

    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
    }
    
    printf("Initialised.\n");
    
    //Create a socket
    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }

    printf("Socket created.\n");
    
    
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 44444 );

    //Connect to remote server
    if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
    }
    
    puts("Connected");
    
    //Send some data
    message = "Hello, World!\n";
    if( send(s , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
    }
    puts("Data Send\n");

    for(int i = 0; i < 100; i++){
        if( send(s , message , strlen(message) , 0) < 0)
        {
            puts("More data sent...");
        }
    }
}