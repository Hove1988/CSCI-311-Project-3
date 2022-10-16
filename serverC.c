/********************************************************************************
 * 
 *  serverC.c
 * 
 *  Assignment: Project 3
 *  Authors: Jacob Haapoja, Joseph Hoversten, Faysal Osman, Matthew Xiang
 *  Class: CSCI 311
 * 
*********************************************************************************/

#include "soc.h"

unsigned int ACTIVE_CLIENTS = 0;

int main(int argc, char argv[]){

    if (argc != 2){
	fprintf(stderr,"Usage: %s <SERVER PORT>\n", argv[0]);
		exit(1);
    }
//General Delcaring variables.
    int err;
    int scSocket; //server c socket
    int cSocket; // client socket

    unsigned short serverPort = atoi(argv[1]);

    struct sockaddr_in sAddr;
    struct sockaddr_in cAddr;
    int cSocLen;
    char Buf[BUFL];


    //Creating the socket
    scSocket = socket (AF_INET, SOCK_STREAM, 0); // AF_INET
    if (scSocket == -1) {
        perror ("socServer: socket creation failed");
        exit (1);
    }

    //Intialize the socket strucutre

    sAddr.sin_family = AF_INET;
    sAddr.sin_port = htons (SERVERPORT);
    sAddr.sin_addr.s_addr = htonl (INADDR_ANY);
    




/*  memset (&sAddr, 0, sizeof (struct sockaddr_in));
    sAddr.sin_family = AF_INET;
    sAddr.sin_port = htons (SERVERPORT);
    sAddr.sin_addr.s_addr = htonl (INADDR_ANY);
    err = bind (sSocket, (struct sockaddr*)&sAddr,
    sizeof (struct sockaddr_in));
    if (err == -1) {
    perror ("socServer: bind address to socket failed");
    exit (2);
    }
    err = listen (sSocket, 5);
    if (err == -1) {
    perror ("socServer: listen failed");
    exit (3);
    }
    cSocket = accept (sSocket, (struct sockaddr *)&cAddr, &cSocLen);
 */



}