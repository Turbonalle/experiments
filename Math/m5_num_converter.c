#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
	int	number;
	int	base;
	int	tries;
}		data;

void welcome_text(void)
{
	printf("I will convert any positive number for you!\n");
	printf("Tell me which number system to convert from, by writing the following characters:\n");
	printf("b : Binary\n");
	printf("o : Octal\n");
	printf("d : Decimal\n");
	printf("h : Hexadecimal\n\n");
}

int get_base_input(data *data)
{
	char	c[1];
	int		base;

	scanf("%s", c);
	if (c[0] != 'b' && c[0] != 'o' && c[0] != 'd' && c[0] != 'h')
		return (0);
	if (c[0] == 'b')
		data->base = 2;
	else if (c[0] == 'o')
		data->base = 8;
	else if (c[0] == 'd')
		data->base = 10;
	else
		data->base = 16;
	return (1);
}
void get_number_input(data *data)
{
	char input[32];

	printf("Enter number you want to convert: ");
	scanf("%s", input);
	write(1, "\n", 1);
	data->number = atoi(input);
}

void convert_decimal(data *data, int base)
{
	char *hex_numbers;
	char buffer[50];
	char *result;
	int n;

	n = data->number;
	hex_numbers = "0123456789abcdef";
	result = &buffer[49];
	*result = '\0';
	while (n > 0)
	{
		*--result = hex_numbers[n % base];
		n /= base;
	}
	while (*result)
	{
		write(1, &(*result), 1);
		result++;
	}
	write(1, "\n", 1);
}

void handle_input(data *data)
{
	write(1, "Binary      : ", 14);
	convert_decimal(data, 2);
	write(1, "Octal       : ", 14);
	convert_decimal(data, 8);
	write(1, "Decimal     : ", 14);
	convert_decimal(data, 10);
	write(1, "Hexadecimal : ", 14);
	convert_decimal(data, 16);
}

int program(data *data)
{
	welcome_text();
	if (!get_base_input(data))
	{
		data->tries++;
		if (data->tries == 3)
		{
			printf("Failed to enter correct input 3 times!\nExiting...\n");
			exit(EXIT_FAILURE);
		}
		printf("Incorrect input! Please try again.\n");
		program(data);
	}
	write(1, "\n", 1);
	get_number_input(data);
	handle_input(data);
	return (1);
}

int main()
{
	data data;

	data.tries = 0;
	program(&data);
	return (0);
}