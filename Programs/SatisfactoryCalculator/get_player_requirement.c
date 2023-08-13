#include "satisfactory_calculator.h"

t_item get_item(t_data *d, char *item_name)
{
	int i;

	i = -1;
	while (++i < ITEMS)
	{
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
		d->player_requirement[n] = get_item(d, av[i]);
		d->player_requirement[n].amount_needed = atof(av[i + 1]);
		n++;
		i += 2;
	}
	d->n_player_requirements = n;
}