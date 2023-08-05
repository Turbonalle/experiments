#include "satisfactory_calculator.h"

//------------------------------------------------------------------------------

void init_items(t_data *d)
{
	t_item	iron_ore = { ORE, 0, 0, 0 };
	t_item	iron_ingot = { ITEM, 1, 0, 0 };

	d->items[IRON_ORE] = iron_ore;
	d->items[IRON_INGOT] = iron_ingot;
}

//------------------------------------------------------------------------------

void init_buildings(t_data *d)
{
	t_building	smelter = { "Smelter", 4, 1 };
	t_building	constructor = { "Constructor", 4, 1 };
	t_building	manufacturer = { "Manufacturer", 4, 1 };
	t_building	coal_generator = { "Coal Generator", 4, 1 };
	t_building	biomass_burner = { "Biomass Burner", 4, 1 };
	t_building	coal_power_plant = { "Coal Power Plant", 4, 1 };
	t_building	oil_refinery = { "Oil Refinery", 4, 1 };
	t_building	compactor = { "Compactor", 4, 1 };
	t_building	assembler = { "Assembler", 4, 1 };
	t_building	foundry = { "Foundry", 4, 1 };

	d->buildings[SMELTER] = smelter;
	d->buildings[CONSTRUCTOR] = constructor;
}

//------------------------------------------------------------------------------

void	get_requirements(t_data *d, t_item *item)
{
	item->recipes[0].items_needed[0].amount_needed = item->amount_needed / item->recipes[0].production_amount * item->recipes[0].item_amount_needed[0];
}

//------------------------------------------------------------------------------

void	calculate_power_consumption(t_data *d)
{
	int i;

	d->power_consumption = 0;
	i = -1;
	while (++i < ITEMS)
	{
		if (d->items[i].type == ITEM)
		{
			d->power_consumption += ceil(d->items[i].amount_needed / d->items[i].recipes[0].production_amount) * d->items[i].recipes[0].building.power_usage_MW;
		}
		else if (d->items[i].type == ORE)
		{
			d->power_consumption += ceil(d->items[i].amount_needed / d->items[i].recipes[0].production_amount) * d->items[i].recipes[0].building.power_usage_MW;
		}
	}
}

//------------------------------------------------------------------------------

void print_item_requirements(t_data *d, t_item *item)
{
	int i;

	i = -1;
	while (++i < ITEMS)
	{
		if (d->items[i].type == ITEM)
			printf("%s: %d\n", d->items[i].recipes[0].items_needed[0].ore, d->items[i].recipes[0].items_needed[0].amount_needed);
	}
}

//------------------------------------------------------------------------------

void print_power_consumption(t_data *d)
{
	printf("Power consumption: %d MW\n", d->power_consumption);
}

//------------------------------------------------------------------------------

void create_iron_ingot_recipe(t_data *d)
{
	t_recipe iron_ingot_recipe;

	iron_ingot_recipe.production_amount = 30;
	iron_ingot_recipe.second_interval = 2;
	iron_ingot_recipe.building = d->buildings[SMELTER];
	iron_ingot_recipe.items_needed[0] = d->items[IRON_ORE];
	iron_ingot_recipe.item_amount_needed[0] = 30;

	// Add recipe to list
	d->items[IRON_INGOT].recipes[0] = iron_ingot_recipe;
}

int main(void)
{
	t_data d;

	init_items(&d);
	init_buildings(&d);

	t_item	iron_ore = { ORE, 0, 0, 0 };
	t_item	iron_ingot = { ITEM, 1, 0, 0 };
	t_recipe iron_ingot_recipe;

	// Initialize amount needed to 0
	iron_ore.amount_needed = 0;
	iron_ingot.amount_needed = 0;

	// Create recipe for iron ingot
	create_iron_ingot_recipe(&d);
	iron_ingot_recipe.production_amount = 30;
	iron_ingot_recipe.second_interval = 2;
	iron_ingot_recipe.building = d.buildings[SMELTER];

	// Add recipe to list
	iron_ingot.recipes[0] = iron_ingot_recipe;

	iron_ingot.amount_needed = 120;

	get_requirements(&d, &iron_ingot);

	calculate_power_consumption(&d);

	print_item_requirements(&d, &iron_ingot);
	print_power_consumption(&d);

	
	return (0);
}