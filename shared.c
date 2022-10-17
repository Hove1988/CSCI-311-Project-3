/********************************************************************************
 * 
 *  shared.c
 * 
 *  Assignment: Project 3
 *  Authors: Jacob Haapoja, Joseph Hoversten, Faysal Osman, Matthew Xiong
 *  Class: CSCI 311
 * 
*********************************************************************************/

#include "soc.h"
#include "shared.h"

void pinfo(const char *msg){
    printf("[INFO]: ");
    printf(msg);
    printf("\n");
}

void draw_board(char board[][3]){
    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
        printf("-----------\n");
    }
}

int get_random_move(char board[][3]){
    time_t t;
    srand((uint)time(&t));
    int move_count = 0;
    int buffer[9];

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (board[i][j]==' '){
                buffer[move_count++] = i*3+j;
            }
        }
    }

    return buffer[rand() % move_count];
}

int check_board(char board[][3], char p){
    // Check horizontal
    for (int i=0; i<3; i++)
    {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p){
            return 1;
        }
    }

    // Check vertical
    for (int i=0; i<3; i++){
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p){
            return 1;
        }
    }

    // Check diagonal
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p){
        return 1;
    }
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p){
        return 1;
    }
    return 0;
}

void update_board(char board[][3], int location, char player){
    board[location/3][location%3] = player;
    char* msg = "Board updated at location X.";
    msg[26] = location + '0';
    pinfo(msg);
}

void get_msg(int socket, char* message){
    memset(message, 0, 2);
    int err = recv(socket, message, BUFL, 0);
    if (err !=1){
        perror("Failed to read message.");
        pinfo("Read message successfully.");
    }
}

int get_int(int socket){
    int message = 0;
    int err = recv(socket, &message, sizeof(int), 0);
    if (err < 0 || err != sizeof(int)){
        perror("Failed to read int.");
    }
    pinfo("Read int successfully.");
    return message;
}

void send_msg(int socket, char* message){
    int err = send(socket, message, strlen(message), 0);
    if (err < 0){
        perror("Failed to send message.");
    }
}

void send_int(int socket, int message)
{
    int err = send(socket, &message, sizeof(int), 0);
    if (err < 0){
        perror("Failed to send int.");
    }
    pinfo("Sent int successfully.");
}

