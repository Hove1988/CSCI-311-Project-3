/********************************************************************************
 * 
 *  client.c
 * 
 *  Assignment: Project 3
 *  Authors: Jacob Haapoja, Joseph Hoversten, Faysal Osman, Matthew Xiong
 *  Class: CSCI 311
 * 
*********************************************************************************/

#include "soc.h"
#include "shared.h"

void get_board_update(int serverSocket, char board[][3]);
void make_move(int serverSocket);

int main(int argc, char argv[]){

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <Server IP> <Server Port>\n", argv[0]);
        exit(1);
    }

    char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int err;
    char* serverIP = argv[1];
    int port = atoi(argv[2]);
    struct sockaddr_in sAddr;
    int sSock = socket ( AF_INET, SOCK_STREAM, 0); // AF_INET

    if (sSock < 0){
        print_error("failed to open server socket.");
    }

    memset(&sAddr, 0, sizeof(sAddr));
    sAddr.sin_family = AF_INET;
    sAddr.sin_addr.s_addr = inet_addr(serverIP);
    sAddr.sin_port = htons(port);

    if(connect(sSock, (struct sockaddr *)&sAddr, sizeof(sAddr))){
        print_error("failed to connect to server.");
    }

    print_info(" Connection successful.");
    draw_board(board);

    int exit = 0;
    while(!exit){
        switch (msg){
            case COMMAND_DRAW:
                printf("You tied!\n");
                exitFlag = 1;
                break;
            case COMMAND_END:
                printf("The game has ended.\n");
                exitFlag = 1;
                break;
            case COMMAND_INVALID:
                printf("That move is invalid.\n");
                break;
            case COMMAND_LOSE:
                printf("You lost.\n");
                exitFlag = 1;
                break;
            case COMMAND_MOVE:
                printf("It's your turn.\n");
                make_move(serverSocket);
                break;
            case COMMAND_START:
                printf("The game has started!\n");
                break;
            case COMMAND_UPDATE:
                get_board_update(serverSocket, board);
                draw_board(board);
                break;
            case COMMAND_WIN:
                printf("You win!\n");
                exitFlag = 1;
                break;
            default:
                display_error("Unknown message.\n");
                exitFlag = 1;
                break;
        }
    }

    printf("GAME OVER\n");
    close(sSock);
    return 0;
}

void get_board_update(int serverSocket, char board[][3]){

    int player = receive_int(serverSocket);
    int move = receive_int(serverSocket);
    board[move/3][move%3] = (char)player;

}

void make_move(int serverSocket){

    char buffer[10];
    for (int i=0; i<3; i++){
        printf(" %i | %i | %i \n", i*3, (i*3)+1, (i*3)+2);
        if (i < 2){
            printf("-----------\n");
        }
    }

    printf("Enter 0-8 to make a move, 9 to forfeit.\n");
    fgets(buffer, 10, stdin);
    int move = stoi(buffer);
    send_int(serverSocket, move);

}

