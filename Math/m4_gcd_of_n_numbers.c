#include <stdio.h>
#include <stdlib.h>

int *create_input_array(char **av, int number_of_input)
{
	int *input_array;
	int i;

	input_array = (int *)malloc((number_of_input + 1) * sizeof(int *));
	if (!input_array)
		return (0);
	i = 0;
	while (i < number_of_input - 1)
	{
		input_array[i] = atoi(av[i + 1]);
		i++;
	}
	input_array[i] = '\0';
	return (input_array);
}

int check_if_divisible(int *input_array, int divider)
{
	int i;

	i = 0;
	while (input_array[i])
	{
		if (input_array[i] % divider != 0)
			return (0);
		i++;
	}
	return (1);
}

int find_smallest(int *input_array)
{
	int smallest;
	int i;

	i = 0;
	smallest = 0;
	while (input_array[i])
	{
		if (smallest < input_array[i])
			smallest = input_array[i];
		i++;
	}
	return (smallest);
}

int main(int ac, char **av)
{
	int smallest;
	int biggest_possible_divider;
	int i;
	int *input_array;

	if (ac < 2)
		return (1);
	input_array = create_input_array(av, ac);
	smallest = find_smallest(input_array);
	biggest_possible_divider = 1;
	i = 2;
	while (i <= smallest / 2)
	{
		if (check_if_divisible(input_array, i) == 1)
			biggest_possible_divider = i;
		i++;
	}
	printf("%d", biggest_possible_divider);
	free(input_array);
	return (0);
}