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
	t_item	*item_needed = &d->player_requirement[0];

	int n = 0;
	while (n < d->n_player_requirements)
	{
		while (item_needed->recipes[0].n_resources > 0)
		{
			get_requirements(d, item_needed);
			item_needed = item_needed->recipes[0].items_needed[0];
		}
		n++;
	}
}