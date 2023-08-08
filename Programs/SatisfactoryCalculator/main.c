#include "satisfactory_calculator.h"

//------------------------------------------------------------------------------

void	get_requirements(t_data *d, t_item *item)
{
	double total_resource_needed;
	double production_amount_needed;
	double production_amount;
	double resource_amount_needed_per_recipe;
	
	production_amount_needed = item->amount_needed;
	production_amount = item->recipes[0].production_amount;
	resource_amount_needed_per_recipe = item->recipes[0].item_amount_needed[0];

	// Calculate total amount of resource needed
	total_resource_needed = production_amount_needed / production_amount * resource_amount_needed_per_recipe;

	// Set amount needed for resource
	item->recipes[0].items_needed[0]->amount_needed = total_resource_needed;
}

//------------------------------------------------------------------------------

void	calculate_requirements(t_data *d)
{
	// Recursively call get_requirements if items_needed is not NULL
	t_item	*item_needed = d->player_requirement.item;

	while (item_needed->recipes[0].n_resources > 0)
	{
		get_requirements(d, item_needed);
		item_needed = item_needed->recipes[0].items_needed[0];
	}
	
}

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

//------------------------------------------------------------------------------

void get_player_requirement(t_data *d)
{
	d->player_requirement.item = &d->items[e_screw];
	d->player_requirement.item->amount_needed = 500;
}

//------------------------------------------------------------------------------

int main(void)
{
	t_data d;

	init_data(&d);
	get_player_requirement(&d);

	calculate_requirements(&d);
	print_item_requirements(&d);

	calculate_power_consumption(&d);
	print_power_consumption(&d);

	
	return (0);
}