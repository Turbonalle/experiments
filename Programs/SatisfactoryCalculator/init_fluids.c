#include "satisfactory_calculator.h"

//------------------------------------------------------------------------------

void	init_fluids(t_data *d)
{
	// Create fluids
	t_item	crude_oil = { "crude_oil", FLUID, 1, NULL, 0, 0, 0 };
	d->items[e_crude_oil] = crude_oil;
	t_item	fuel = { "fuel", FLUID, 1, NULL, 0, 0, 0 };
	d->items[e_fuel] = fuel;
	t_item	heavy_oil_residue = { "heavy_oil_residue", FLUID, 1, NULL, 0, 0, 0 };
	d->items[e_heavy_oil_residue] = heavy_oil_residue;
	t_item	nitric_acid = { "nitric_acid", FLUID, 1, NULL, 0, 0, 0 };
	d->items[e_nitric_acid] = nitric_acid;
	t_item	nitrogen_gas = { "nitrogen_gas", FLUID, 1, NULL, 0, 0, 0 };
	d->items[e_nitrogen_gas] = nitrogen_gas;
	t_item	turbofuel = { "turbofuel", FLUID, 1, NULL, 0, 0, 0 };
	d->items[e_turbofuel] = turbofuel;
	t_item	sulfuric_acid = { "sulfuric_acid", FLUID, 1, NULL, 0, 0, 0 };
	d->items[e_sulfuric_acid] = sulfuric_acid;
	t_item	water = { "water", FLUID, 1, NULL, 0, 0, 0 };
	d->items[e_water] = water;
}

//------------------------------------------------------------------------------

void	init_fluid_recipes(t_data *d)
{
	// Create fluid recipes
	t_recipe crude_oil_recipe = { "crude_oil", 120, 0, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_oil_extractor] };
	d->items[e_crude_oil].recipes[0] = crude_oil_recipe;
	t_recipe fuel_recipe = { "fuel", 40, 6, 1, { &d->items[e_crude_oil] }, { 60 }, &d->items[e_polymer_resin], 30, d->buildings[e_refinery] };
	d->items[e_fuel].recipes[0] = fuel_recipe;
	t_recipe heavy_oil_residue = { "heavy_oil_residue", 40, 6, 1, { &d->items[e_crude_oil] }, { 30 }, &d->items[e_polymer_resin], 20, d->buildings[e_refinery] };
	d->items[e_heavy_oil_residue].recipes[0] = heavy_oil_residue;
	t_recipe nitric_acid = { "nitric_acid", 30, 6, 3, { &d->items[e_nitrogen_gas], &d->items[e_water], &d->items[e_iron_plate] }, { 120, 30, 10 }, NULL, 0, d->buildings[e_blender] };
	d->items[e_nitric_acid].recipes[0] = nitric_acid;
	t_recipe nitrogen_gas = { "nitrogen_gas", 60, 0, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_resource_well_extractor] };
	d->items[e_nitrogen_gas].recipes[0] = nitrogen_gas;
	t_recipe turbofuel_recipe = { "turbofuel", 18.75, 16, 2, { &d->items[e_fuel], &d->items[e_compacted_coal] }, { 22.5, 15 }, NULL, 0, d->buildings[e_refinery] };
	d->items[e_turbofuel].recipes[0] = turbofuel_recipe;
	t_recipe sulfuric_acid_recipe = { "sulfuric_acid", 50, 6, 2, { &d->items[e_sulfur], &d->items[e_water] }, { 50, 50 }, NULL, 0, d->buildings[e_refinery] };
	d->items[e_sulfuric_acid].recipes[0] = sulfuric_acid_recipe;
	t_recipe water_recipe = { "water", 120, 0, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_water_extractor] };
	d->items[e_water].recipes[0] = water_recipe;
}