#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define RESET "\033[0m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define ON 1
#define OFF 0
#define MAX_WORD_LENGTH 6

typedef struct s_data
{
	char board[5][5];
	char guess[20];
	char **word_list;
	char *word;
	int attempts;
	int game;
	int file;
}		t_data;

//------------------------------------------------------------------------------

int get_random_word(t_data *d)
{
    int num_words = 1;
    int random_line;
    int line_count;
    char ch;

	// Open file
	d->file = open("words.txt", O_RDONLY, 0444);
    if (!d->file) {
        perror("Error opening file");
        return (0);
    }

	// Count number of words in file
	while (read(d->file, &ch, 1) > 0)
	{
		if (ch == '\n')
			num_words++;
	}
	printf("Number of words: %d\n", num_words);
	close(d->file);
	
	// Open file again
	d->file = open("words.txt", O_RDONLY, 0444);
	if (!d->file) {
		perror("Error opening file");
		return (0);
	}

	// Allocate memory for word list
	d->word_list = malloc(sizeof(char *) * num_words);
	if (!d->word_list)
		return (0);
	
	// Allocate memory for each word
	int i = 0;
	while (i < num_words)
	{
		d->word_list[i] = malloc(sizeof(char) * MAX_WORD_LENGTH);
		if (!d->word_list[i])
			return (0);
		int j = 0;
		// Read each character into word
		while (j < MAX_WORD_LENGTH)
		{
			read(d->file, &ch, 1);
			d->word_list[i][j] = ch;
			j++;
		}
		d->word_list[i][--j] = '\0';
		i++;
	}
    close(d->file);

	// Select random word
    srand(time(NULL));
	random_line = rand() % num_words + 1;
	d->word = d->word_list[random_line];
	printf("Random word: %s\n", d->word);
	return (1);
}

//------------------------------------------------------------------------------

void clear_board(t_data *d)
{
	int i;
	int j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			d->board[i][j] = '_';
			j++;
		}
		i++;
	}
}

//------------------------------------------------------------------------------

int initialize(t_data *d)
{
	if (!get_random_word(d))
		return (0);
	clear_board(d);
	d->attempts = 0;
	d->game = ON;
	return (1);
}

//------------------------------------------------------------------------------

void print_header(void)
{
	printf(PURPLE);
	printf("----------------------\n");
	printf("--------WORDLE--------\n");
	printf("----------------------\n\n");
	printf(RESET);
}

//------------------------------------------------------------------------------

// void set_color(char *word, char c, int pos)
// {
// 	if ()
// }

//------------------------------------------------------------------------------



//------------------------------------------------------------------------------

void print_board(t_data *d)
{
	int line;
	int pos;

	line = 0;
	while (line < 5)
	{
		pos = 0;
		while (pos < 4)
		{
			// set_color(d->word, d->board[line][pos], pos);
			printf("%c ", d->board[line][pos]);
			// reset_color();
			pos++;
		}
		printf("%c\n", d->board[line][pos]);
		printf("\n");
		line++;
	}
	printf("\n");
}

//------------------------------------------------------------------------------

int all_letters(char *guess)
{
	int i;

	i = -1;
	while (++i < 5)
	{
		if (!('a' <= guess[i] && guess[i] <= 'z') || ('A' <= guess[i] && guess[i] <= 'Z'))
			return (0);
	}
	return (1);
}

//------------------------------------------------------------------------------

void get_guess(t_data *d)
{
	int valid_guess = 0;

	while (valid_guess == 0)
	{
		printf(CYAN"Enter a guess: "RESET);
		scanf("%s", d->guess);
		if (strlen(d->guess) != 5)
			printf(RED"Error: Guess must be 5 letters long\n"RESET);
		else if (!all_letters(d->guess))
			printf(RED"Error: Only alphabetic characters allowed\n"RESET);
		else
			valid_guess = 1;
	}
}

//------------------------------------------------------------------------------

int check_win(t_data *d)
{
	if (strcmp(d->guess, d->word) == 0)
	{
		printf(GREEN"Congratulations! You win!\n"RESET);
		return (1);
	}
	else
	{
		printf(RED"Sorry, that's not the word\n"RESET);
		d->attempts++;
		if (d->attempts == 5)
		{
			printf(RED"Sorry, you lose!\n"RESET);
			return (1);
		}
	}
	return (0);
}

//------------------------------------------------------------------------------

void update_board(t_data *d)
{
	int i;

	i = -1;
	while (++i < 5)
		d->board[d->attempts][i] = d->guess[i];
}

//------------------------------------------------------------------------------

int main(void)
{
	t_data d;
	int	fd;
	int valid_guess = 0;

	if (!initialize(&d))
		return (1);
	printf("Word: %s\n", d.word);

	d.game = ON;
	while (d.game == ON)
	{
		fflush(stdout);
		print_header();
		print_board(&d);
		get_guess(&d);
		update_board(&d);
		if (check_win(&d))
			d.game = OFF;
	}
	close(fd);
	return (0);
}