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

int check_board(char board[][3], char p);

int main(int argc, char *argv[]){
	
	if (argc != 2){
		fprintf(stderr,"Usage: %s <CLIENT SOCKET>", argv[0]);
		exit(1);
	}
	
	int cSocket = atoi(argv[1]);

	pinfo("Game started.");
	char board[3][3] = {{ ' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

	send_int(cSocket, COMMAND_START);

	char prev_turn = PLAYER_COMPUTER;
	char turn = PLAYER_HUMAN;
	int turn_count = 0;
	int game_over_flag = 0;
	char msg[BUFL];

	while (!game_over_flag){
		if (turn == PLAYER_HUMAN){
			int valid = 0;
			int move = 0;	
			while (!valid){
				if (move == -1) {break;}
				send_int(cSocket, COMMAND_MOVE);
				move = get_int(cSocket);
				if ((move == 9) || (board[move/3][move%3] == ' ')){
					valid = 1;
				}
				else{
					send_int(cSocket, COMMAND_INVALID);
				}
			}
			if (move == 9 ) {
				send_int(cSocket, COMMAND_LOSE);
				sprintf(msg, "Player forfeit.\n");
				printf(msg, "Player forfeit.\n");
				send_msg(cSocket, msg);
				break;
			} else {
				board[move/3][move%3] = turn;
				send_int(cSocket, COMMAND_UPDATE);
				send_int(cSocket, (int)PLAYER_HUMAN);
				send_int(cSocket, move);
			
				int playerWins = check_board(board, PLAYER_HUMAN);
				if (playerWins>0){
					sprintf(msg, "Human won.\n");
					printf(msg, "Human won.\n");
					game_over_flag = 1;
					send_int(cSocket, COMMAND_WIN);
					send_msg(cSocket, msg);
				}
			}
		} else {
			int move = get_random_move(board);	
			board[move/3][move%3] = turn;
			send_int(cSocket, COMMAND_UPDATE);
			send_int(cSocket, (int)PLAYER_COMPUTER);
			send_int(cSocket, move);
		
			int computerWins = check_board(board, PLAYER_COMPUTER);
			if (computerWins>0)
			{
		
				sprintf(msg, "Computer won.\n");
				printf(msg, "Computer won.\n");
				game_over_flag = 1;
				send_int(cSocket, COMMAND_LOSE);
				send_msg(cSocket, msg);
			}
		}

		if (game_over_flag == 0 && turn_count == 8){
			sprintf(msg, "Draw.\n");
			printf(msg, "Draw.\n");
			send_int(cSocket, COMMAND_DRAW);
			send_msg(cSocket, msg);
			game_over_flag = 1;
		}
        
		char tempPlayer = prev_turn;
		prev_turn = turn;
		turn = tempPlayer;
		turn_count++;
	}
	/* Close client socket */
	close(cSocket);	
	return 0;	
}