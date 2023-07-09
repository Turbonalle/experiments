#include <stdio.h>
#include <time.h>
#include <math.h>
#define WIN 1
#define LOSE 0
#define YES 1
#define NO 0
#define PLAYER 1
#define BOT 2
#define MIDDLE 4

typedef struct data
{
	char board[9];
	int win;
	int lose;
	int first;
	int moves;
}		data;

// bot.c
void bot_perfect_move(data *d);
void bot_simple_move(data *d);

// check_win.c
int check_rows(data *d, char n); //
int check_columns(data *d, char n); //
int check_diagonals(data *d, char n); //
int someone_won(data *d, char c);

// input_handler.c
void get_starting_player(int player);
void get_input(data *d);
int play_again(void);

// print.c
void welcome(void);
void print_board(data *d, int player);
void end_message(int end);