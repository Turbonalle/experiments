#include "satisfactory_calculator.h"

//------------------------------------------------------------------------------

void	get_requirements(t_data *d, t_item *item, int update)
{
	t_recipe *recipe;
	double total_resource_needed;
	double production_amount_needed;
	double production_amount;
	double resource_amount_needed_per_recipe;
	int i;
	
	recipe = &item->recipes[0];
	production_amount_needed = item->amount_needed;
	production_amount = recipe->production_amount;

	i = -1;
	while (++i < recipe->n_resources)
	{
		if (update == UPDATE)
			recipe->resources[i]->amount_needed = 0;
		total_resource_needed = production_amount_needed / production_amount * recipe->resource_amount[i];
		recipe->resources[i]->amount_needed += total_resource_needed;
		if (recipe->resources[i]->amount_needed == 0)
		{
			get_requirements(d, recipe->resources[i], NO_UPDATE);
		}
		else
		{
			get_requirements(d, recipe->resources[i], UPDATE);
		}
	}
}

//------------------------------------------------------------------------------

void	item_requirements(t_data *d, t_item *item)
{
	int i;

	if (item->recipes[0].n_resources > 0)
	{
		get_requirements(d, item, NO_UPDATE);
	}
}

//------------------------------------------------------------------------------

void	calculate_requirements(t_data *d)
{
	int i;

	i = -1;
	while (++i < d->n_player_requirements)
	{
		item_requirements(d, &d->player_requirement[i]);
	}
}
