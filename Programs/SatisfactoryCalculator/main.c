#include "satisfactory_calculator.h"

//------------------------------------------------------------------------------

int valid_input_check(int ac, char **av)
{
	int i;

	// Check that requirements are given in pairs
	if (ac < 3 || ac % 2 == 0)
	{
		printf("Invalid input\n");
		exit(0);
	}

	// Check that requirements are positive
	i = 1;
	while (i < ac)
	{
		if (atoi(av[i + 1]) <= 0)
			exit(0);
		i += 2;
	}
	return (1);
}

//------------------------------------------------------------------------------

int main(int ac, char **av)
{
	t_data d;

	valid_input_check(ac, av);

	init_data(&d);
	get_player_requirement(&d, ac, av);

	calculate_requirements(&d);
	print_item_requirements(&d);

	calculate_power_consumption(&d);
	print_power_consumption(&d);

	
	return (0);
}