#include <stdio.h>
#define WIN 1
#define LOSE 0
#define YES 1
#define NO 0
#define PLAYER 1
#define BOT 2
typedef struct data
{
	char board[9];
	int win;
	int lose;
	int first;
}		data;

void init(data *d)
{
	int i;

	i = -1;
	while (++i < 9)
		d->board[i] = ' ';
	d->win = 0;
	d->lose = 0;
}

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

void get_starting_player(int player)
{
	char response[10];

	printf("Would you like to start? (y/n): ");
	scanf("%s", &response);
	if (response[0] == 'y' || response[0] == 'Y')
		player = PLAYER;
	if (response[0] == 'n' || response[0] == 'N')
		player = BOT;
	printf("\n");
}

void get_input(data *d)
{
	int i;

	printf("Enter a number corresponding to a square of the board: ");
	scanf("%d", &i);
	if (i < 1 || 9 < i)
	{
		printf("Invalid input. Please enter a number from 1 to 9.\n");
		get_input(d);
	}
	else if (d->board[i - 1] == ' ')
	{
		d->board[i - 1] = 'o';
		printf("\n");
	}
	else
	{
		printf("Not an empty square!\n");
		get_input(d);
	}
}

int check_rows(data *d, char n)
{
	int full_row;

	full_row = 0;
	if (d->board[0] == n && d->board[1] == n && d->board[2] == n)
		full_row = 1;
	else if (d->board[3] == n && d->board[4] == n && d->board[5] == n)
		full_row = 1;
	else if (d->board[6] == n && d->board[7] == n && d->board[8] == n)
		full_row = 1;
	return (full_row);
}

int check_columns(data *d, char n)
{
	int full_column;

	full_column = 0;
	if (d->board[0] == n && d->board[3] == n && d->board[6] == n)
		full_column = 1;
	else if (d->board[1] == n && d->board[4] == n && d->board[7] == n)
		full_column = 1;
	else if (d->board[2] == n && d->board[5] == n && d->board[8] == n)
		full_column = 1;
	return (full_column);
}

int check_diagonals(data *d, char n)
{
	int full_diagonal;

	full_diagonal = 0;
	if (d->board[0] == n && d->board[4] == n && d->board[8] == n)
		full_diagonal = 1;
	else if (d->board[2] == n && d->board[4] == n && d->board[6] == n)
		full_diagonal = 1;
	return (full_diagonal);
}

int someone_won(data *d, char c)
{
	d->win += check_rows(d, c);
	d->win += check_columns(d, c);
	d->win += check_diagonals(d, c);
	return (d->win);
}

void end_message(int end)
{
	if (end == WIN)
		printf("CONGRATULATIONS! YOU WON!\n\n");
	else
		printf("Too bad, you lost! Better luck next time!\n\n");
}

int play_again()
{
	// char response;
	char response[10];

	printf("Would you like to play again? (y/n): ");
	scanf("%s", &response);
	// response = getchar();
	// getchar();
	if (response[0] == 'y' || response[0] == 'Y')
	{
		printf("Starting a new game...\n");
		return (YES);
	}
	else if (response[0] == 'n' || response[0] == 'N')
	{
		printf("Exiting the game...\n");
		return (NO);
	}
	else
	{
		printf("Invalid response. Please enter 'y' or 'n'\n");
		return (play_again());
	}
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

void bot_perfect_move(data *d)
{
	if (d->first == PLAYER)
		bot_second(d);
	else
		bot_first(d);
}

void bot_simple_move(data *d)
{
	int i;

	i = -1;
	while (++i < 9)
	{
		if (d->board[i] == ' ')
		{
			d->board[i] = 'x';
			return ;
		}
	}
}

int main(void)
{
	data d;

	welcome();
	init(&d);
	get_starting_player(d.first);
	while (1)
	{
		get_input(&d);
		if (someone_won(&d, 'o'))
		{
			print_board(&d, PLAYER);
			end_message(WIN);
			if (play_again())
				init(&d);
			else
				return (0);
		}
		else
		{
			print_board(&d, PLAYER);
			bot_simple_move(&d);
			if (someone_won(&d, 'x'))
			{
				print_board(&d, PLAYER);
				end_message(LOSE);
				if (play_again())
					init(&d);
				else
					return (0);
			}
			print_board(&d, BOT);
		}
	}
	return (0);
}