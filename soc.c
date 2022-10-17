/********************************************************************************
 * 
 *  soc.c
 *  Purpose: Declares both sockets between client to serverg?
 *
 *  Assignment: Project 3
 *  Authors: Jacob Haapoja, Joseph Hoversten, Faysal Osman, Matthew Xiong
 *  Class: CSCI 311
 * 
********************************************************************************/

#include "soc.h"
#include "shared.h"


int serverSocket( int port){
    int sSocket;
    struct sockaddr_in sAddr;
     
    if (sSocket = socket ( AF_INET, SOCK_STREAM, 0) < 0) {
        perror ("socserver: socket creation failed");
    }

    memset(&serverAddress, 0, sizeof(serverAddress)); // Empty
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons(port);
	
    if (bind(serverSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) < 0){
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
