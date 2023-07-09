#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


char *find_end_bracket(char **start)
{
	char *bracket_end;
	int	brackets;

	brackets = 0;
	while (++(*bracket_end) && !(*bracket_end == ']' && brackets != 0))
	{
		if (*bracket_end == '[')
			brackets++;
		else if (*bracket_end == ']' && brackets > 0)
			brackets--;
	}
	if (!(*bracket_end))
	{
		printf("Did not find closing bracket\n");
		exit(1);
	}
	*start = bracket_end;
}

void bracket(char **bracket_start, char **ptr)
{
	char *bracket_end;
	char *input;
	char *p;

	bracket_end = *bracket_start;
	input = *bracket_start;
	find_end_bracket(&bracket_end);
	p = *ptr;
	while (++input < bracket_end && *input)
	{
		if (*input == '>')
			p++;
		else if (*input == '<')
			p--;
		else if (*input == '+')
			(*p)++;
		else if (*input == '-')
			(*p)--;
		else if (*input == '.')
			putchar(*p);
		else if (*input == ',')
			*p = getchar();
		else if (*input == '[')
			bracket(&input, &p);
		else if (*input == ']' && *p)
			input = *bracket_start;
		else if (*input == ']' && !(*p))
			break;
		else
		{
			printf("'%c' is not an allowed character\n", *input);
			exit(1);
		}
	}
	*bracket_start = bracket_end;
	*ptr = p;
}

void bf(char *input)
{
	char buf[32768];
	char *p;

	p = &buf[0];
	while (*input)
	{
		if (*input == '>')
			p++;
		else if (*input == '<')
			p--;
		else if (*input == '+')
			(*p)++;
		else if (*input == '-')
			(*p)--;
		else if (*input == '.')
			putchar(*p);
		else if (*input == ',')
			*p = getchar();
		else if (*input == '[')
			bracket(&input, &p);
		input++;
	}
}

int main(int ac, char **av)
{
	int fd;
	char file[100];
	char buffer[1024];

	if (ac == 2)
	{
		bf(av[1]);
	}
	if (ac == 1)
	{
		printf("Enter a filename: ");
		scanf("%s", file);
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			printf("Failed to open the file.\n");
			return (1);
		}
		if (read(fd, buffer, sizeof(buffer)) <= 0)
		{
			printf("Failed reading, or file empty.\n");
			close(fd);
			return (1);
		}
		bf(buffer);
		close(fd);
	}
	return (0);
}