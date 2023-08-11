#include "satisfactory_calculator.h"

//------------------------------------------------------------------------------

void	calculate_power_consumption(t_data *d)
{
	t_item		*item;
	int			i;

	d->power_consumption = 0;
	i = -1;
	while (++i < ITEMS)
	{
		item = &d->items[i];
		item->buildings_needed = ceil(item->amount_needed / item->recipes[0].production_amount);
		item->power_needed = item->buildings_needed * item->recipes[0].building.power_usage_MW;
		d->power_consumption += item->power_needed;
	}
}
