#include "satisfactory_calculator.h"

//------------------------------------------------------------------------------

void	init_ores(t_data *d)
{
	// Create ores
	t_item	bauxite = { "bauxite", ORE, 1, NULL, 0, 0, 0 };
	d->items[e_bauxite] = bauxite;
	t_item	caterium_ore = { "caterium_ore", ORE, 1, NULL, 0, 0, 0 };
	d->items[e_caterium_ore] = caterium_ore;
	t_item	coal = { "coal", ORE, 1, NULL, 0, 0, 0 };
	d->items[e_coal] = coal;
	t_item	copper_ore = { "copper_ore", ORE, 1, NULL, 0, 0, 0 };
	d->items[e_copper_ore] = copper_ore;
	t_item	iron_ore = { "iron_ore", ORE, 1, NULL, 0, 0, 0 };
	d->items[e_iron_ore] = iron_ore;
	t_item	limestone = { "limestone", ORE, 1, NULL, 0, 0, 0 };
	d->items[e_limestone] = limestone;
	t_item	raw_quartz = { "raw_quartz", ITEM, 1, NULL, 0, 0, 0 };
	d->items[e_raw_quartz] = raw_quartz;
	t_item	sam_ore = { "sam_ore", ORE, 1, NULL, 0, 0, 0 };
	d->items[e_sam_ore] = sam_ore;
	t_item	sulfur = { "sulfur", ORE, 1, NULL, 0, 0, 0 };
	d->items[e_sulfur] = sulfur;
	t_item	uranium = { "uranium", ORE, 1, NULL, 0, 0, 0 };
	d->items[e_uranium] = uranium;
}

//------------------------------------------------------------------------------

void	init_ore_recipes(t_data *d)
{
	// Create ore recipes
	t_recipe bauxite_recipe = { "bauxite", 240, 0.25, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_miner] };
	d->items[e_bauxite].recipes[0] = bauxite_recipe;
	t_recipe caterium_ore_recipe = { "caterium_ore", 240, 0.25, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_miner] };
	d->items[e_caterium_ore].recipes[0] = caterium_ore_recipe;
	t_recipe coal_recipe = { "coal", 240, 0.25, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_miner] };
	d->items[e_coal].recipes[0] = coal_recipe;
	t_recipe copper_ore_recipe = { "copper_ore", 240, 0.25, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_miner] };
	d->items[e_copper_ore].recipes[0] = copper_ore_recipe;
	t_recipe iron_ore_recipe = { "iron_ore", 240, 0.25, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_miner] };
	d->items[e_iron_ore].recipes[0] = iron_ore_recipe;
	t_recipe limestone_recipe = { "limestone", 240, 0.25, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_miner] };
	d->items[e_limestone].recipes[0] = limestone_recipe;
	t_recipe raw_quartz_recipe = { "raw_quartz", 240, 0.25, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_miner] };
	d->items[e_raw_quartz].recipes[0] = raw_quartz_recipe;
	t_recipe sam_ore_recipe = { "sam_ore", 240, 0.25, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_miner] };
	d->items[e_sam_ore].recipes[0] = sam_ore_recipe;
	t_recipe sulfur_recipe = { "sulfur", 240, 0.25, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_miner] };
	d->items[e_sulfur].recipes[0] = sulfur_recipe;
	t_recipe uranium = { "uranium", 240, 0.25, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_miner] };
	d->items[e_uranium].recipes[0] = uranium;
}