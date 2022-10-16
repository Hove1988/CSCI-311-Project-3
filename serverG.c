/********************************************************************************
 * 
 *  serverG.c
 * 
 *  Assignment: Project 3
 *  Authors: Jacob Haapoja, Joseph Hoversten, Faysal Osman, Matthew Xiong
 *  Class: CSCI 311
 * 
*********************************************************************************/

#include "soc.h"
#include "shared.h"

int main(int argc, char argv[]){

    if (argc != 2){
	    sprintf(stderr,"Usage: %s <CLIENT SOCKET>", argv[0]);
        exit(1);
    }
    int cSock = atoi(argv[1]);
    int err;
    char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

    //Creating the socket
    sgSocket = socket  (AF_INET, SOCK_STREAM, 0); // AF_INET
    if (sgSocket == -1) {
        perror ("socServer: socket creation failed");
        exit (1);
    }

    //Intialize the socket strucutre
    memset(&sadder,0,sizeof(struct sockadder_ing))
    sAddr.sin_family = AF_INET;
    sAddr.sin_port = htons (SERVERPORT);
    sAddr.sin_addr.s_addr = htonl (INADDR_ANY); 

    //Bind the host address using bind
    if(bind(sgsocket, (struct sockaddr*)&sAddr, sizeof(struct sockadder_in))< 0){
        perror("Server G: Error on Binding");
        exit(2);
    }

    //listen from serverC 
    listen(sgsocket,1);

    //error checking for listen
    if(listen(sgsocket, (struct sockaddr*)&sAddr, sizeof(struct sockadder_in))< 0)
    {
        perror("ServerG: Error on Listen");
        exit(3);
    }
    //accept to send information to client Interface
    accept (sgsocket, (struct sockaddr *)&cAddr, &cSocLen);

    //error checking for accepts
    if(accept(sgsocket, (struct sockaddr*)&cAddr, sizeof(struct sockadder_in))< 0)
    {
        perror("Server G: Error on Accept");
        exit(4);
    }
    
    //recieve in client
    recieve (scsocket, (struct sockaddr *)&cAddr, &cSocLen);
      
      //error checking for recieve
    if(recieve(scsocket, (struct sockaddr*)&cAddr, sizeof(struct sockadder_in))< 0)
    {
        perror("Server G: Error on Recieve");
        exit(4);
    }

}