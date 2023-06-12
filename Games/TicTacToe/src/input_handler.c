#include "../incl/tictactoe.h"

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

int play_again(void)
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