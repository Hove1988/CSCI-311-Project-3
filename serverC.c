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
#include "shared.h"

void exitSignalHandler();
int serverSocket(int port);
int clientSocket(int sSocket);
unsigned int ACTIVE_CLIENTS = 0;

int main(int argc, char *argv[]){

    if (argc != 2){
	fprintf(stderr,"Usage: %s <SERVER PORT>\n", argv[0]);
		exit(1);
    }
//General Declaring variables.
    int err;
    int sSocket; // server socket
    int cSocket; // client socket

    unsigned short port = atoi(argv[1]);

    struct sigaction sigHandler;
    struct sockaddr_in sAddr;
    struct sockaddr_in cAddr;
    int cSocLen;
    char buf[BUFL];


    //Creating the socket
    sSocket = serverSocket(port); // AF_INET
    
    sigHandler.sa_handler = exitSignalHandler;

    if (sigfillset(&sigHandler.sa_mask) < 0){
		perror("Signal setting failed.");
		sigHandler.sa_flags = SA_RESTART;
	}

	if (sigaction(SIGCHLD, &sigHandler, 0) < 0){
		perror("Action setting for signal failed.");
	}

    if (listen(sSocket, MAX_REQ) < 0){
        perror("server socket listen failed");
    }

    while(1){
        err = -1;
        pinfo("Waiting for Connection...\n");
        cSocket = clientSocket(sSocket);
        sprintf(buf, "%d", cSocket);
        if (cSocket > 0){
            err = fork();
            ACTIVE_CLIENTS++;
        }

        if (err < 0){
            perror("fork failed");
        } else if (err == 0){
            close(sSocket);
            execl("./serverG", "serverG", buf, (char *) NULL);
        }

        memset(buf, 0, BUFL);
        close(cSocket);
    }


    return 0;
}

void exitSignalHandler(){
    //Local Variable
    int err;

    while(ACTIVE_CLIENTS > 0){
        err = waitpid((pid_t) -1, NULL, WNOHANG);
        if (err < 0){
            perror("waitpid failed");
        } else if (err == 0) {
            break;
        } else {
            ACTIVE_CLIENTS--;
        }
    }
}

