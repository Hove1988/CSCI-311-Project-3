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

    int err, sgsocket, sSocLen;
    struct sockaddr_in sAddr;
    struct sockaddr_in cAddr;
    char Buf[BUFL];


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
    listen(sgsocket,5);

    //error
    
    //accept to send information to client


    //recieve in client 

    

   



}