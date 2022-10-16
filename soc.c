/********************************************************************************
 * 
 *  soc.c
 *  Purpose: Declares both sockets between client to serverg?
 *
 *  Assignment: Project 3
 *  Authors: Jacob Haapoja, Joseph Hoversten, Faysal Osman, Matthew Xiong
 *  Class: CSCI 311
 * 
*********************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "soc.h"


int ServerSocket( int serverPort){
    int sSocket;
    sSocket = socket ( AF_INET, SOCK_STREAM, 0); 
    if (sSocket == -1) {
     perror ("socserver: socket creation failed");
     exit (1);
    }

}

int ClientSocket(int serverPort){
    int err;
    int sSocket;
    int cSocket;
    int cSocLen;
    char Buf[BUFL];
    struct addrinfo criteria; //idk what this does..
    struct addrinfo *serverResult; //idk what this does..

//
cSocket = socket ( AF_INET, SOCK_STREAM, 0); 
if (cSocket == -1) {
    perror ("socClient: socket creation failed");
    exit (1);
}
}

/*
err = connect (cSocket, serverResult->ai_addr,sizeof(struct sockaddr_in));
if (err == -1) {
    perror ("socClient: connect failed");
    exit (3);
}
freeaddrinfo (serverResult);
*/
