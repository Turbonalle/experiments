#include "satisfactory_calculator.h"

//------------------------------------------------------------------------------

void init_items(t_data *d)
{
	// t_item	adaptive_control_unit = { "adaptive_control_unit", ITEM, 1, NULL, 0 };
	t_item	ai_limiter = { "ai_limiter", ITEM, 1, NULL, 0 };
	t_item	caterium_ingot = { "caterium_ingot", ITEM, 1, NULL, 0 };
	t_item	caterium_ore = { "caterium_ore", ORE, 0, NULL, 0 };
	t_item	copper_ingot = { "copper_ingot", ITEM, 1, NULL, 0 };
	t_item	copper_ore = { "copper_ore", ORE, 0, NULL, 0 };
	t_item	copper_sheet = { "copper_sheet", ITEM, 1, NULL, 0 };
	t_item	iron_ore = { "iron_ore", ORE, 0, NULL, 0 };
	t_item	iron_ingot = { "iron_ingot", ITEM, 1, NULL, 0 };
	t_item	iron_rod = { "iron_rod", ITEM, 1, NULL, 0 };
	t_item	iron_plate = { "iron_plate", ITEM, 1, NULL, 0 };
	t_item	screw = { "screw", ITEM, 1, NULL, 0 };
	t_item	quickwire = { "quickwire", ITEM, 1, NULL, 0 };

	// d->items[e_adaptive_control_unit] = adaptive_control_unit;
	d->items[e_ai_limiter] = ai_limiter;
	d->items[e_caterium_ingot] = caterium_ingot;
	d->items[e_caterium_ore] = caterium_ore;
	d->items[e_copper_ingot] = copper_ingot;
	d->items[e_copper_ore] = copper_ore;
	d->items[e_copper_sheet] = copper_sheet;
	d->items[e_iron_ingot] = iron_ingot;
	d->items[e_iron_ore] = iron_ore;
	d->items[e_iron_plate] = iron_plate;
	d->items[e_iron_rod] = iron_rod;
	d->items[e_screw] = screw;
	d->items[e_quickwire] = quickwire;
}

//------------------------------------------------------------------------------

void init_buildings(t_data *d)
{
	t_building	miner = { "Miner", 30 };
	t_building	smelter = { "Smelter", 4 };
	t_building	constructor = { "Constructor", 4 };
	t_building	assembler = { "Assembler", 15 };
	t_building	manufacturer = { "Manufacturer", 55 };

	d->buildings[e_miner] = miner;
	d->buildings[e_smelter] = smelter;
	d->buildings[e_constructor] = constructor;
	d->buildings[e_assembler] = assembler;
	d->buildings[e_manufacturer] = manufacturer;
}

//------------------------------------------------------------------------------

void init_recipes(t_data *d)
{
	// t_recipe adaptive_control_unit_recipe = { "adaptive_control_unit", 1, 120, 4, { &d->items[e_automated_wiring], &d->items[e_circuit_board], &d->items[e_heavy_modular_frame], &d->items[e_computer] }, { 7.5, 10, 2, 2 }, NULL, d->buildings[e_manufacturer] };
	t_recipe ai_limiter_recipe = { "ai_limiter", 5, 12, 2, { &d->items[e_copper_sheet], &d->items[e_quickwire] }, { 25, 100 }, NULL, d->buildings[e_assembler] };
	t_recipe caterium_ingot_recipe = { "caterium_ingot", 15, 4, 1, { &d->items[e_caterium_ore] }, { 45 }, NULL, d->buildings[e_smelter] };
	t_recipe caterium_ore_recipe = { "caterium_ore", 120, 0.25, 0, { NULL }, { 0 }, NULL, d->buildings[e_miner] };
	t_recipe copper_ingot_recipe = { "copper_ingot", 30, 2, 1, { &d->items[e_copper_ore] }, { 30 }, NULL, d->buildings[e_smelter] };
	t_recipe copper_ore_recipe = { "copper_ore", 240, 0.25, 0, { NULL }, { 0 }, NULL, d->buildings[e_miner] };
	t_recipe copper_sheet_recipe = { "copper_sheet", 10, 6, 1, { &d->items[e_copper_ingot] }, { 20 }, NULL, d->buildings[e_constructor] };
	t_recipe iron_ore_recipe = { "iron_ore", 240, 0.25, 0, { NULL }, { 0 }, NULL, d->buildings[e_miner] };
	t_recipe iron_ingot_recipe = { "iron_ingot", 30, 2, 1, { &d->items[e_iron_ore] }, { 30 }, NULL, d->buildings[e_smelter] };
	t_recipe iron_rod_recipe = { "iron_rod", 15, 4, 1, { &d->items[e_iron_ingot] }, { 15 }, NULL, d->buildings[e_constructor] };
	t_recipe iron_plate_recipe = { "iron_plate", 20, 6, 1, { &d->items[e_iron_ingot] }, { 30 }, NULL, d->buildings[e_constructor] };
	t_recipe screw_recipe = { "screw", 40, 6, 1, { &d->items[e_iron_rod] }, { 10 }, NULL, d->buildings[e_constructor] };
	t_recipe quickwire_recipe = { "quickwire", 60, 5, 1, { &d->items[e_caterium_ingot] }, { 12 }, NULL, d->buildings[e_constructor] };

	// d->items[e_adaptive_control_unit].recipes[0] = adaptive_control_unit_recipe;
	d->items[e_ai_limiter].recipes[0] = ai_limiter_recipe;
	d->items[e_caterium_ingot].recipes[0] = caterium_ingot_recipe;
	d->items[e_caterium_ore].recipes[0] = caterium_ore_recipe;
	d->items[e_copper_ingot].recipes[0] = copper_ingot_recipe;
	d->items[e_copper_ore].recipes[0] = copper_ore_recipe;
	d->items[e_copper_sheet].recipes[0] = copper_sheet_recipe;
	d->items[e_iron_ore].recipes[0] = iron_ore_recipe;
	d->items[e_iron_ingot].recipes[0] = iron_ingot_recipe;
	d->items[e_iron_rod].recipes[0] = iron_rod_recipe;
	d->items[e_iron_plate].recipes[0] = iron_plate_recipe;
	d->items[e_screw].recipes[0] = screw_recipe;
	d->items[e_quickwire].recipes[0] = quickwire_recipe;
}

//------------------------------------------------------------------------------

void init_data(t_data *d)
{
	init_items(d);
	init_buildings(d);
	init_recipes(d);
}
