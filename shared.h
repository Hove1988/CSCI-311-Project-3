/********************************************************************************
 * 
 *  shared.c
 * 
 *  Assignment: Project 3
 *  Authors: Jacob Haapoja, Joseph Hoversten, Faysal Osman, Matthew Xiong
 *  Class: CSCI 311
 * 
*********************************************************************************/

#ifndef _SHARED_H
#define _SHARED_H
#define COMMAND_DRAW 100
#define COMMAND_END 200
#define COMMAND_INVALID 300
#define COMMAND_LOSE 400
#define COMMAND_MOVE 500
#define COMMAND_START 600
#define COMMAND_UPDATE 700
#define COMMAND_WIN 800
#define PLAYER_COMPUTER 'O'
#define PLAYER_HUMAN 'X'

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

void pinfo(const char *msg);
void draw_board(char board[][3]);
int get_random_move(char board[][3]);
int check_board(char board[][3], char p);
void update_board(char board[][3], int location, char player);
void get_msg(int socket, char* message);
int get_int(int socket);
void send_msg(int socket, char* message);
void send_int(int socket, int message);

void pinfo(const char *msg){
    printf("[INFO]: ");
    printf(msg);
    printf("\n");
}

void draw_board(char board[][3]){
    int i = 0;
    while (i < 3){
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
        printf("-----------\n");
        i++;
    }
}

int get_random_move(char board[][3]){
    time_t t;
    srand((uint)time(&t));
    int randMove = rand() % 9;
    return randMove;
}

int check_board(char board[][3], char p){
    // Check horizontal
    int i = 0;
    while (i<3)
    {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p){
            return 1;
        }
        i++;
    }
    i = 0;

    // Check vertical
    while (i<3){
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p){
            return 1;
        }
        i++;
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
    memset(message, 0, BUFL);
    int err = recv(socket, message, BUFL, 0);
    if (err < 0){
        perror("Failed to read message.");
    } else {
        pinfo("Read message successfully.");
    }
}

int get_int(int socket){
    int message = 0;
    int err = recv(socket, &message, sizeof(int), 0);
    if (err < 0)
    {
        perror("Failed to read int.");
    } else {
        pinfo("Read int successfully.");
    }
    return message;
}

void send_msg(int socket, char* message){
    int err = send(socket, message, strlen(message), 0);
    if (err < 0){
        perror("Failed to send message.");
    } else {
        pinfo("Sent msg successfully");
    }
}

void send_int(int socket, int message){
    int err = send(socket, &message, sizeof(int), 0);
    if (err < 0){
        perror("Failed to send int.");
    } else {
        pinfo("Sent int successfully.");
    }
}

#endif