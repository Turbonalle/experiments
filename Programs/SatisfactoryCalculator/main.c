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

void set_item(t_data *d, t_item *item, t_recipe *recipe, int index)
{
	d->items[index] = *item;
	item->recipes[0] = *recipe;
}

//------------------------------------------------------------------------------

void init_data(t_data *d)
{
	init_buildings(d);
	init_ores(d);
	init_fluids(d);
	init_items(d);
	init_elevator_items(d);
	init_ore_recipes(d);
	init_fluid_recipes(d);
	init_item_recipes(d);
	init_elevator_item_recipes(d);
}

//------------------------------------------------------------------------------

int main(int ac, char **av)
{
	t_data d;

	valid_input_check(ac, av);

	init_data(&d);
	get_player_requirement(&d, ac, av);
	printf("item[0].name: %s\n", d.items[0].name);

	calculate_requirements(&d);
	printf("resource amount needed = %f\n", d.items[0].amount_needed);
	calculate_power_consumption(&d);

	print_requirements(&d);

	
	return (0);
}