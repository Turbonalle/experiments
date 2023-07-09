#include "../incl/tictactoe.h"

void init(data *d)
{
	int i;

	i = -1;
	while (++i < 9)
		d->board[i] = ' ';
	d->win = 0;
	d->lose = 0;
	d->moves = 0;
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
		d.moves++;
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