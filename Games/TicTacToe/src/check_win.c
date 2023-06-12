#include "../incl/tictactoe.h"

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