#include "../incl/tictactoe.h"

void welcome(void)
{
	printf("---------------------------\n");
	printf("|        TICTACTOE        |\n");
	printf("---------------------------\n");
	printf("\n");
	printf("Every square of the board has it's own corresponding number, from 1 to 9.\n");
	printf("You play by entering one of those numbers.\n\n");
	printf("-------------\n");
	printf("| 7 | 8 | 9 |\n");
	printf("-------------\n");
	printf("| 4 | 5 | 6 |\n");
	printf("-------------\n");
	printf("| 1 | 2 | 3 |\n");
	printf("-------------\n");
	printf("\n");
}

void print_board(data *d, int player)
{
	if (player == PLAYER)
		printf("YOU:\n");
	if (player == BOT)
		printf("BOT:\n");
	printf("-------------\n");
	printf("| %c | %c | %c |\n", d->board[6], d->board[7], d->board[8]);
	printf("-------------\n");
	printf("| %c | %c | %c |\n", d->board[3], d->board[4], d->board[5]);
	printf("-------------\n");
	printf("| %c | %c | %c |\n", d->board[0], d->board[1], d->board[2]);
	printf("-------------\n");
	printf("\n");
}

void end_message(int end)
{
	if (end == WIN)
		printf("CONGRATULATIONS! YOU WON!\n\n");
	else
		printf("Too bad, you lost! Better luck next time!\n\n");
}