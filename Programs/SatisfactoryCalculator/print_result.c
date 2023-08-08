#include "satisfactory_calculator.h"

//------------------------------------------------------------------------------

void print_item_requirements(t_data *d)
{
	int i;

	printf("----Calculating requirements----\n");
	i = -1;
	while (++i < ITEMS)
	{
		if (d->items[i].type == ITEM)
		{
			printf("%s: ", d->items[i].name);
			printf("%.0f\n", d->items[i].amount_needed);
		}
		else if (d->items[i].type == ORE)
		{
			printf("%s: ", d->items[i].name);
			printf("%.0f\n", d->items[i].amount_needed);
		}
	}
}

//------------------------------------------------------------------------------

void print_power_consumption(t_data *d)
{
	printf("Power consumption: %.0f MW\n", d->power_consumption);
}