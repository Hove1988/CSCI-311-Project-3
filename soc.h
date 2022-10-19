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
#include <signal.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SERVERPORT() 31101 
#define SERVERPORTSTR "31101"
#define SERVERIP "199.17.28.80"
#define SERVERNAME "ahscentos"
#define BUFL 100
#define MAX_REQ 5

int serverSocket(int port){

    //Local variables
    int sSocket;
    int err;
    struct sockaddr_in sAddr;
     
    //Create socket for incoming connections 
    if ((sSocket = socket ( AF_INET, SOCK_STREAM, 0)) < 0) {
        perror ("socserver: socket creation failed");
        exit(0);
    }

    //Construct local adress structure
    memset(&sAddr, 0, sizeof(struct sockaddr_in));      //Zero out structure
	sAddr.sin_family = AF_INET;                         //IPv4 address family
    sAddr.sin_port = htons(port);                       //Local port
	sAddr.sin_addr.s_addr = htonl(INADDR_ANY);          //Any incoming address
    
	//Bind to the local address
    if (bind(sSocket, (struct sockaddr*) &sAddr, sizeof(sAddr)) == -1){
		perror("Bind failed.");
        exit(0);
    }

    return sSocket;
}

int clientSocket(int sSocket){
    
    //Local variables
    int cSocket;
    struct sockaddr_in cAddr;
    unsigned int cLen = sizeof(cAddr);
    
    //Wait for client to connect
    cSocket = accept(sSocket, (struct sockaddr *) &cAddr, &cLen); 

    //Checks client socket and see if it is able to connect
    if (cSocket == -1) {
        perror ("failed to connect to client");
    }
    
    return cSocket;
}

#endif