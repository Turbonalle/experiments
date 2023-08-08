#include "satisfactory_calculator.h"

t_item get_item(t_data *d, char *item_name)
{
	int i;

	i = -1;
	while (++i < ITEMS)
	{
		printf("[%d] strcmp(%s, %s)\n", i, d->items[i].name, item_name);
		if (strcmp(d->items[i].name, item_name) == 0)
			return (d->items[i]);
	}
	printf("Item [%s] not found\n", item_name);
	exit(1);
}

//------------------------------------------------------------------------------

void get_player_requirement(t_data *d, int ac, char **av)
{
	int i, n;

	i = 1;
	n = 0;
	while (i < ac && n < MAX_REQUIREMENTS)
	{
		printf("av[%d] = %s\n", i, av[i]);
		d->player_requirement[n] = get_item(d, av[i]);
		printf("d->player_requirement[%d].name = %s\n", n, d->player_requirement[n].name);
		d->player_requirement[n].amount_needed = atof(av[i + 1]);
		n++;
		i += 2;
	}
	d->n_player_requirements = n;

	// print player requirements
	i = -1;
	while (++i < d->n_player_requirements)
	{
		printf("Player requirement: %s %lf\n", d->player_requirement[i].name, d->player_requirement[i].amount_needed);
	}

	// d->player_requirement = &d->items[e_ai_limiter];
	// d->player_requirement->amount_needed = 5;
}