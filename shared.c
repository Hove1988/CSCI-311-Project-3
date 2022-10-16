/********************************************************************************
 * 
 *  shared.c
 * 
 *  Assignment: Project 3
 *  Authors: Jacob Haapoja, Joseph Hoversten, Faysal Osman, Matthew Xiong
 *  Class: CSCI 311
 * 
*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>
//#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

void print_info(const char *msg){
    printf("[INFO]: ");
    printf(msg);
    printf("\n");
}

void print_error(const char *msg)
{
    printf("[ERROR]: %s", msg);
    perror(msg);
    exit(1);
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
    print_info(msg);
}

void get_msg(int socket, char* message){
    memset(message, 0, 2);
    int err = read(socket, message, 1);
    if (err !=1){
        print_error("Failed to read message.");
        print_info("Read message successfully.");
    }
}

int get_int(int socket){
    int message = 0;
    int err = read(socket, &message, sizeof(int));
    if (err < 0 || err != sizeof(int)){
        print_error("Failed to read int.");
    }
    print_info("Read int successfully.");
    return message;
}

void send_msg(int socket, char* message){
    int err = write(socket, message, strlen(message));
    if (err < 0){
        print_error("Failed to send message.");
    }
}

void send_int(int socket, int message)
{
    int err = write(socket, &message, sizeof(int));
    if (err < 0){
        print_error("Failed to send int.");
    }
    print_info("Sent int successfully.");
}

