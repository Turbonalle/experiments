#include "satisfactory_calculator.h"

//------------------------------------------------------------------------------

void	calculate_power_consumption(t_data *d)
{
	int buildings_needed;
	int i;

	printf("\n");
	printf("----Calculating power consumption----\n");
	d->power_consumption = 0;
	i = -1;
	while (++i < ITEMS)
	{
		printf("i = %d\n", i);
		if (d->items[i].type == ITEM)
		{
			buildings_needed = ceil(d->items[i].amount_needed / d->items[i].recipes[0].production_amount);
			d->power_consumption += buildings_needed * d->items[i].recipes[0].building.power_usage_MW;
			printf("--[%s]--\n", d->items[i].name);
			printf("Buildings needed = %d\n", buildings_needed);
			printf("Power_consumption = %.0f\n", d->power_consumption);
		}
		else if (d->items[i].type == ORE)
		{
			buildings_needed = ceil(d->items[i].amount_needed / d->items[i].recipes[0].production_amount);
			d->power_consumption += buildings_needed * d->items[i].recipes[0].building.power_usage_MW;
			printf("--[%s]--\n", d->items[i].name);
			printf("Miners needed = %d\n", buildings_needed);
			printf("d->power_consumption = %.0f\n", d->power_consumption);
		}
	}
}
