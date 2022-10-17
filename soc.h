/********************************************************************************
 * 
 *  soc.h
 * 
 *  Assignment: Project 3
 *  Authors: Jacob Haapoja, Joseph Hoversten, Faysal Osman, Matthew Xiong
 *  Class: CSCI 311
 * 
*********************************************************************************/

#ifndef SOC_H
#define SOC_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SERVERPORT 31100
#define SERVERPORTSTR "31100"
#define SERVERIP "199.17.28.80"
#define SERVERNAME "ahscentos"
#define BUFL 100
#define MAX_REQ 5


int serverSocket( int port){
    int sSocket;
    struct sockaddr_in sAddr;
     
    if (sSocket = socket ( AF_INET, SOCK_STREAM, 0) < 0) {
        perror ("socserver: socket creation failed");
    }

    memset(&sAddr, 0, sizeof(sAddr)); // Empty
	sAddr.sin_family = AF_INET;
	sAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	sAddr.sin_port = htons(port);
    
	int err = bind(serverSocket, (struct sockaddr*) &sAddr, sizeof(sAddr));
    if (err){
		display_error("Bind failed.");
    }
    return sSocket;
}

int clientSocket(int serverPort){
    
    int cSocket;
    struct sockaddr_in cAddr;
    unsigned int cLen = sizeof(cAddr);

    cSocket = accept(serverSocket, (struct sockaddr *) &cAddr, &cLen); 
    if (cSocket == -1) {
        perror ("failed to connect to client");
        exit (1);
    }
    return cSocket;
}


#endif
