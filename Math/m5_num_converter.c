typedef struct data
{
	char	*string;
	char	base;
	int		tries;
}			data;

void welcome_text(void)
{
	printf("I will convert any number for you!\n");
	printf("Tell me which number system to convert from, by writing the following characters:\n");
	printf("Binary:\tb\n");
	printf("Binary:\to\n");
	printf("Binary:\td\n");
	printf("Binary:\th\n");
}

int get_base_input(data *data)
{
	char c;

	scanf("%c", c);
	if (c != 'b' && c != 'o' && c != 'd' && c != 'h')
	{
		printf("Incorrect input! Please try again.\n");
		return (0);
	}
	data->base = c;
	return (1);
}

void handle_input(data *data)
{
	
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
			return (0);
		}
		program(data);
	}
	get_number_input(data);
	handle_input(data);
	return (1);
}

int main()
{
	data data;

	data.tries = 0;
	program(&data);
	free(&data);
	return (0);
}