#include "satisfactory_calculator.h"

//------------------------------------------------------------------------------

void init_items(t_data *d)
{
	t_item	iron_ore = { "iron_ore", ORE, 0, NULL, 0 };
	t_item	iron_ingot = { "iron_ingot", ITEM, 1, NULL, 0 };
	t_item	iron_rod = { "iron_rod", ITEM, 1, NULL, 0 };
	t_item	iron_plate = { "iron_plate", ITEM, 1, NULL, 0 };
	t_item	screw = { "screw", ITEM, 1, NULL, 0 };

	d->items[e_iron_ore] = iron_ore;
	d->items[e_iron_ingot] = iron_ingot;
	d->items[e_iron_rod] = iron_rod;
	d->items[e_iron_plate] = iron_plate;
	d->items[e_screw] = screw;
}

//------------------------------------------------------------------------------

void init_buildings(t_data *d)
{
	t_building	miner = { "Miner", 30 };
	t_building	smelter = { "Smelter", 4 };
	t_building	constructor = { "Constructor", 4 };

	d->buildings[MINER] = miner;
	d->buildings[SMELTER] = smelter;
	d->buildings[CONSTRUCTOR] = constructor;
}

//------------------------------------------------------------------------------

void init_recipes(t_data *d)
{
	t_recipe iron_ore_recipe = { "iron_ore", 240, 0.25, 0, { NULL }, { 0 }, NULL, d->buildings[MINER] };
	t_recipe iron_ingot_recipe = { "iron_ingot", 30, 2, 1, { &d->items[e_iron_ore] }, { 30 }, NULL, d->buildings[SMELTER] };
	t_recipe iron_rod_recipe = { "iron_rod", 15, 4, 1, { &d->items[e_iron_ingot] }, { 15 }, NULL, d->buildings[CONSTRUCTOR] };
	t_recipe iron_plate_recipe = { "iron_plate", 20, 6, 1, { &d->items[e_iron_ingot] }, { 30 }, NULL, d->buildings[CONSTRUCTOR] };
	t_recipe screw_recipe = { "screw", 40, 6, 1, { &d->items[e_iron_rod] }, { 10 }, NULL, d->buildings[CONSTRUCTOR] };

	d->items[e_iron_ore].recipes[0] = iron_ore_recipe;
	d->items[e_iron_ingot].recipes[0] = iron_ingot_recipe;
	d->items[e_iron_rod].recipes[0] = iron_rod_recipe;
	d->items[e_iron_plate].recipes[0] = iron_plate_recipe;
	d->items[e_screw].recipes[0] = screw_recipe;
}

//------------------------------------------------------------------------------

void init_data(t_data *d)
{
	init_items(d);
	init_buildings(d);
	init_recipes(d);
}
