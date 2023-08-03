#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_letter
{
	char		letter;
	int			color;
}				t_letter;

typedef struct s_data
{
	char		*word;
	t_letter	letters[5];
	t_letter	*possibilities[5];
	int			possibilities_count;
	int			exit;
}				t_data;

void	get_word(t_data *d)
{
	char buffer[20];
	
	printf("Enter the word: ");
	scanf("%s", d->word);
	printf("Word: %s\n", d->word);
	printf("Length: %d\n", strlen(d->word));
	if (strlen(d->word) != 5)
	{
		printf("Error: Word must be 5 letters long\n");
		exit(1);
	}
		
}

void	get_letters(t_data *d)
{
	int i;

	i = -1;
	while (++i < 5)
		d->letters[i].letter = d->word[i];
}

void	get_colors(t_data *d)
{
	int i;
	int color;

	i = -1;
	while (++i < 5)
	{
		printf("(1 = gray, 2 = yellow, 3 = green)\n");
		printf("Enter the color of letter %c: ", d->letters[i].letter);
		scanf("%d", &color);
		if (color < 1 || color > 3)
		{
			printf("Error: Color must be between 1 and 3\n");
			exit(1);
		}
		d->letters[i].color = color;
	}
}

void add_possibility(t_data *d, int pos, int color)
{
	int i;

	// Increase count
	d->possibilities_count++;
	
	// Reallocate memory
	d->possibilities = realloc(d->possibilities, d->possibilities_count * sizeof(t_letter *));
	if (d->possibilities == NULL)
	{
		printf("Error: Could not allocate memory\n");
		exit(1);
	}

	// Create possibility
	i = -1;
	while (++i < 5)
	{
		d->possibilities[pos][i].letter = d->letters[i].letter;
		if (i == pos)
			d->possibilities[pos][i].color = color;
		else
			d->possibilities[pos][i].color = d->letters[i].color;
	}
}

void	lie_in_position(t_data *d, int pos)
{
	int color;

	color = 0;
	while (++color < 4)
	{
		if (d.letters[pos].color != color)
		{
			add_possibility(d, pos, color);
		}
	}
	
}

void	get_possibilities(t_data *d)
{
	int pos;

	pos = -1;
	while (++pos < 5)
	{
		lie_in_position(d, pos);
	}
}

int main(void)
{
	t_data d;

	d.word = malloc(6 * sizeof(char));
	d.word[5] = '\0';

	d.possibilities_count = 0;
	d.exit = 0;
	while (exit == 0)
	{
		get_word(&d);
		get_letters(&d);
		get_colors(&d);
		get_possibilities(&d);
		print_possibilities(&d);
	}

	free(word);
	return 0;
}