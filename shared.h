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


void print_info(const char *msg);
void print_error(const char *msg);
void draw_board(char board[][3]);
int get_random_move(char board[][3]);
int check_board(char board[][3], char p);
void update_board(char board[][3], int location, char player);
void get_msg(int socket, char* message);
int get_int(int socket);
void send_msg(int socket, char* message);
void send_int(int socket, int message);

#endif