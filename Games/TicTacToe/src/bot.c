#include "../incl/tictactoe.h"

int random_corner()
{
	int corners[] = { 0, 2, 6, 8 };
	int n;

	srand(time(NULL));
	n = floor(rand() % 4);
	// corners[0] = 0;
	// corners[1] = 2;
	// corners[2] = 6;
	// corners[3] = 8;
	return (corners[n]);	
}

void starting_move(data *d)
{
	int n;

	srand(time(NULL));
	n = floor(rand() % 2);
	if (n == 0)
		d->board[MIDDLE] = 'x';
	else
		d->board[random_corner()] = 'x';
	d->moves++;
}

void bot_first(data *d)
{
	starting_move(d);

}

void bot_second(data *d)
{
	
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
			d->moves++;
			return ;
		}
	}
}