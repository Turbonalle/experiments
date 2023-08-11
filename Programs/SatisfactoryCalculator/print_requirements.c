#include "satisfactory_calculator.h"

//------------------------------------------------------------------------------

void print_requirements(t_data *d)
{
	t_item *item;
	int i;

	printf("\n");
	printf("----Requirements----\n");
	printf("%-15s | %6s | %3s * %-12s | %5s |\n", "Item", "Amount", "n", "Building", "Power");
	printf("----------------|--------|---------------------|-------|\n");

	i = -1;
	while (++i < ITEMS)
	{
		item = &d->items[i];
		if (item->amount_needed > 0)
		{
			printf("%-15s |", item->name);
			printf(" %6.0f |", item->amount_needed);
			printf(" %3.0f", item->buildings_needed);
			printf(" * %-12s |", item->recipes[0].building.name);
			printf(" %5.0f |", item->power_needed);
			printf("\n");
		}
	}
	printf("----------------|--------|---------------------|-------|\n");
	printf("Total power consumption: %.0f MW\n", d->power_consumption);
}