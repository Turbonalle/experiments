#include "satisfactory_calculator.h"

//------------------------------------------------------------------------------

void init_items(t_data *d)
{
	// Initialize items
	t_item	adaptive_control_unit = { "adaptive_control_unit", ELEVATOR_ITEM, 2, NULL, 0, 0, 0 };
	t_item	ai_limiter = { "ai_limiter", ITEM, 1, NULL, 0, 0, 0 };
	t_item	alclad_aluminum_sheet = { "alclad_aluminum_sheet", ITEM, 1, NULL, 0, 0, 0 };
	t_item	alien_DNA_capsule = { "alien_DNA_capsule", ITEM, 1, NULL, 0, 0, 0 };
	t_item	alien_protein = { "alien_protein", ITEM, 1, NULL, 0, 0, 0 };
	t_item	alien_remains = { "alien_remains", SCAVENGE, 3, NULL, 0, 0, 0 };
	t_item	alumina_solution = { "alumina_solution", ITEM, 1, NULL, 0, 0, 0 };
	t_item	aluminum_casing = { "aluminum_casing", ITEM, 1, NULL, 0, 0, 0 };
	t_item	aluminum_ingot = { "aluminum_ingot", ITEM, 1, NULL, 0, 0, 0 };
	t_item	aluminum_scrap = { "aluminum_scrap", ITEM, 1, NULL, 0, 0, 0 };
	t_item	assembly_director_system = { "assembly_director_system", ELEVATOR_ITEM, 2, NULL, 0, 0, 0 };
	t_item	automated_wiring = { "automated_wiring", ELEVATOR_ITEM, 2, NULL, 0, 0, 0 };
	t_item	bacon_agaric = { "bacon_agaric", SCAVENGE, 3, NULL, 0, 0, 0 };
	t_item	battery = { "battery", ITEM, 1, NULL, 0, 0, 0 };
	t_item	bauxite = { "bauxite", ORE, 0, NULL, 0, 0, 0 };
	t_item	beacon = { "beacon", ITEM, 1, NULL, 0, 0, 0 };

	t_item	cable = { "cable", ITEM, 1, NULL, 0, 0, 0 };
	t_item	caterium_ingot = { "caterium_ingot", ITEM, 1, NULL, 0, 0, 0 };
	t_item	caterium_ore = { "caterium_ore", ORE, 0, NULL, 0, 0, 0 };
	t_item	circuit_board = { "circuit_board", ITEM, 1, NULL, 0, 0, 0 };

	t_item	coal = { "coal", ORE, 0, NULL, 0, 0, 0 };
	t_item	copper_ingot = { "copper_ingot", ITEM, 1, NULL, 0, 0, 0 };
	t_item	copper_ore = { "copper_ore", ORE, 0, NULL, 0, 0, 0 };
	t_item	copper_sheet = { "copper_sheet", ITEM, 1, NULL, 0, 0, 0 };
	t_item	iron_ore = { "iron_ore", ORE, 0, NULL, 0, 0, 0 };
	t_item	iron_ingot = { "iron_ingot", ITEM, 1, NULL, 0, 0, 0 };
	t_item	iron_rod = { "iron_rod", ITEM, 1, NULL, 0, 0, 0 };
	t_item	iron_plate = { "iron_plate", ITEM, 1, NULL, 0, 0, 0 };
	t_item	limestone = { "limestone", ORE, 0, NULL, 0, 0, 0 };
	t_item	quickwire = { "quickwire", ITEM, 1, NULL, 0, 0, 0 };
	t_item	screw = { "screw", ITEM, 1, NULL, 0, 0, 0 };
	t_item	water = { "water", LIQUID, 4, NULL, 0, 0, 0 };
	t_item	wire = { "wire", ITEM, 1, NULL, 0, 0, 0 };

	// Create item list
	d->items[e_adaptive_control_unit] = adaptive_control_unit;
	d->items[e_ai_limiter] = ai_limiter;
	d->items[e_alclad_aluminum_sheet] = alclad_aluminum_sheet;
	d->items[e_alien_DNA_capsule] = alien_DNA_capsule;
	d->items[e_alien_protein] = alien_protein;
	d->items[e_alumina_solution] = alumina_solution;
	d->items[e_aluminum_casing] = aluminum_casing;
	d->items[e_aluminum_ingot] = aluminum_ingot;
	d->items[e_aluminum_scrap] = aluminum_scrap;
	d->items[e_assembly_director_system] = assembly_director_system;
	d->items[e_automated_wiring] = automated_wiring;
	d->items[e_bacon_agaric] = bacon_agaric;
	d->items[e_battery] = battery;
	d->items[e_bauxite] = bauxite;
	d->items[e_beacon] = beacon;

	d->items[e_cable] = cable;
	d->items[e_caterium_ingot] = caterium_ingot;
	d->items[e_caterium_ore] = caterium_ore;
	d->items[e_circuit_board] = circuit_board;

	d->items[e_coal] = coal;
	d->items[e_copper_ingot] = copper_ingot;
	d->items[e_copper_ore] = copper_ore;
	d->items[e_copper_sheet] = copper_sheet;
	d->items[e_iron_ingot] = iron_ingot;
	d->items[e_iron_ore] = iron_ore;
	d->items[e_iron_plate] = iron_plate;
	d->items[e_iron_rod] = iron_rod;
	d->items[e_limestone] = limestone;
	d->items[e_quickwire] = quickwire;
	d->items[e_screw] = screw;
	d->items[e_water] = water;
	d->items[e_wire] = wire;
	d->items[e_alien_remains] = alien_remains;
}

//------------------------------------------------------------------------------

void init_buildings(t_data *d)
{
	t_building	miner = { "Miner", 30 };
	t_building	smelter = { "Smelter", 4 };
	t_building	constructor = { "Constructor", 4 };
	t_building	assembler = { "Assembler", 15 };
	t_building	manufacturer = { "Manufacturer", 55 };
	t_building	foundry = { "Foundry", 16 };
	t_building	refinery = { "Refinery", 30 };
	t_building	water_extractor = { "Water Extractor", 20 };
	t_building	blender = { "Blender", 75 };

	d->buildings[e_miner] = miner;
	d->buildings[e_smelter] = smelter;
	d->buildings[e_constructor] = constructor;
	d->buildings[e_assembler] = assembler;
	d->buildings[e_manufacturer] = manufacturer;
	d->buildings[e_foundry] = foundry;
	d->buildings[e_refinery] = refinery;
	d->buildings[e_water_extractor] = water_extractor;
	d->buildings[e_blender] = blender;
}

//------------------------------------------------------------------------------

void init_recipes(t_data *d)
{
	// Initialize recipes
	t_recipe bauxite_recipe = { "bauxite", 240, 0.25, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_miner] };
	t_recipe caterium_ore_recipe = { "caterium_ore", 240, 0.25, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_miner] };
	t_recipe coal_recipe = { "coal", 240, 0.25, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_miner] };
	t_recipe copper_ore_recipe = { "copper_ore", 240, 0.25, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_miner] };
	t_recipe iron_ore_recipe = { "iron_ore", 240, 0.25, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_miner] };
	t_recipe limestone_recipe = { "limestone", 240, 0.25, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_miner] };
	t_recipe water_recipe = { "water", 120, 0, 0, { NULL }, { 0 }, NULL, 0, d->buildings[e_water_extractor] };
	
	t_recipe adaptive_control_unit_recipe = { "adaptive_control_unit", 1, 120, 4, { &d->items[e_automated_wiring], &d->items[e_circuit_board], &d->items[e_heavy_modular_frame], &d->items[e_computer] }, { 7.5, 5, 1, 1 }, NULL, 0, d->buildings[e_manufacturer] };
	t_recipe ai_limiter_recipe = { "ai_limiter", 5, 12, 2, { &d->items[e_copper_sheet], &d->items[e_quickwire] }, { 25, 100 }, NULL, 0, d->buildings[e_assembler] };
	t_recipe alclad_aluminum_sheet_recipe = { "alclad_aluminum_sheet", 30, 6, 2, { &d->items[e_aluminum_ingot], &d->items[e_copper_ingot], &d->items[e_copper_ingot] }, { 30, 10 }, NULL, 0, d->buildings[e_assembler] };
	t_recipe alien_DNA_capsule_recipe = { "alien_DNA_capsule", 10, 6, 1, { &d->items[e_alien_protein] }, { 10 }, NULL, 0, d->buildings[e_constructor] };
	t_recipe alien_protein_recipe = { "alien_protein", 20, 3, 1, { &d->items[e_alien_remains] }, { 20 }, NULL, 0, d->buildings[e_constructor] };
	t_recipe alien_remains_recipe = { "alien_remains", 1, 0, 0, { NULL }, { 0 }, NULL, 0, NULL };
	t_recipe alumina_solution_recipe = { "alumina_solution", 120, 6, 2, { &d->items[e_bauxite], &d->items[e_water] }, { 120, 180 }, &d->items[e_silica], 50, d->buildings[e_refinery] };
	t_recipe aluminum_casing_recipe = { "aluminum_casing", 60, 2, 1, { &d->items[e_aluminum_ingot] }, { 90 }, NULL, 0, d->buildings[e_constructor] };
	t_recipe aluminum_ingot_recipe = { "aluminum_ingot", 60, 4, 2, { &d->items[e_aluminum_scrap], &d->items[e_silica] }, { 90, 75 }, NULL, 0, d->buildings[e_foundry] };
	t_recipe aluminum_scrap_recipe = { "aluminum_scrap", 360, 1, 2, { &d->items[e_alumina_solution], &d->items[e_coal] }, { 240, 120 }, &d->items[e_water], 120, d->buildings[e_refinery] };
	t_recipe assembly_director_system_recipe = { "assemply_director_system", 0.75, 80, 2, { &d->items[e_adaptive_control_unit], &d->items[e_supercomputer] }, { 1.5, 0.75 }, NULL, 0, d->buildings[e_assembler] };
	t_recipe automated_wiring_recipe = { "automated_wiring", 2.5, 24, 2, { &d->items[e_stator], &d->items[e_cable] }, { 2.5, 50 }, NULL, 0, d->buildings[e_assembler] };
	t_recipe bacon_agaric_recipe = { "bacon_agaric", 1, 0, 0, { NULL }, { 0 }, NULL, 0, NULL };
	t_recipe battery_recipe = { "battery", 20, 3, 3, { &d->items[e_sulfuric_acid], &d->items[e_alumina_solution], &d->items[e_aluminum_casing] }, { 50, 40, 20 }, { &d->items[e_water] }, 30, d->buildings[e_blender] };
	t_recipe beacon_recipe = { "beacon", 7.5, 8, 4, { &d->items[e_iron_plate], &d->items[e_iron_rod], &d->items[e_wire], &d->items[e_cable] }, { 22.5, 7.5, 112.5, 15 }, NULL, 0, d->buildings[e_manufacturer] };

	t_recipe cable_recipe = { "cable", 30, 2, 1, { &d->items[e_wire] }, { 60 }, NULL, 0, d->buildings[e_constructor] };
	t_recipe caterium_ingot_recipe = { "caterium_ingot", 15, 4, 1, { &d->items[e_caterium_ore] }, { 45 }, NULL, 0, d->buildings[e_smelter] };
	t_recipe circuit_board_recipe = { "circuit_board", 7.5, 8, 2, { &d->items[e_copper_sheet], &d->items[e_plastic] }, { 15, 30 }, NULL, 0, d->buildings[e_assembler] };

	t_recipe copper_ingot_recipe = { "copper_ingot", 30, 2, 1, { &d->items[e_copper_ore] }, { 30 }, NULL, 0, d->buildings[e_smelter] };
	t_recipe copper_sheet_recipe = { "copper_sheet", 10, 6, 1, { &d->items[e_copper_ingot] }, { 20 }, NULL, 0, d->buildings[e_constructor] };
	t_recipe iron_ingot_recipe = { "iron_ingot", 30, 2, 1, { &d->items[e_iron_ore] }, { 30 }, NULL, 0, d->buildings[e_smelter] };
	t_recipe iron_rod_recipe = { "iron_rod", 15, 4, 1, { &d->items[e_iron_ingot] }, { 15 }, NULL, 0, d->buildings[e_constructor] };
	t_recipe iron_plate_recipe = { "iron_plate", 20, 6, 1, { &d->items[e_iron_ingot] }, { 30 }, NULL, 0, d->buildings[e_constructor] };
	t_recipe quickwire_recipe = { "quickwire", 60, 5, 1, { &d->items[e_caterium_ingot] }, { 12 }, NULL, 0, d->buildings[e_constructor] };
	t_recipe screw_recipe = { "screw", 40, 6, 1, { &d->items[e_iron_rod] }, { 10 }, NULL, 0, d->buildings[e_constructor] };
	t_recipe wire_recipe = { "wire", 30, 4, 1, { &d->items[e_copper_ingot] }, { 15 }, NULL, 0, d->buildings[e_constructor] };

	// Create recipe list
	d->items[e_adaptive_control_unit].recipes[0] = adaptive_control_unit_recipe;
	d->items[e_ai_limiter].recipes[0] = ai_limiter_recipe;
	d->items[e_alclad_aluminum_sheet].recipes[0] = alclad_aluminum_sheet_recipe;
	d->items[e_alien_DNA_capsule].recipes[0] = alien_DNA_capsule_recipe;
	d->items[e_alien_protein].recipes[0] = alien_protein_recipe;
	d->items[e_alien_remains].recipes[0] = alien_remains_recipe;
	d->items[e_alumina_solution].recipes[0] = alumina_solution_recipe;
	d->items[e_aluminum_casing].recipes[0] = aluminum_casing_recipe;
	d->items[e_aluminum_ingot].recipes[0] = aluminum_ingot_recipe;
	d->items[e_aluminum_scrap].recipes[0] = aluminum_scrap_recipe;
	d->items[e_assembly_director_system].recipes[0] = assembly_director_system_recipe;
	d->items[e_automated_wiring].recipes[0] = automated_wiring_recipe;
	d->items[e_bacon_agaric].recipes[0] = bacon_agaric_recipe;
	d->items[e_bauxite].recipes[0] = bauxite_recipe;

	d->items[e_cable].recipes[0] = cable_recipe;
	d->items[e_caterium_ingot].recipes[0] = caterium_ingot_recipe;
	d->items[e_caterium_ore].recipes[0] = caterium_ore_recipe;
	d->items[e_circuit_board].recipes[0] = circuit_board_recipe;
	
	d->items[e_coal].recipes[0] = coal_recipe;
	d->items[e_copper_ingot].recipes[0] = copper_ingot_recipe;
	d->items[e_copper_ore].recipes[0] = copper_ore_recipe;
	d->items[e_copper_sheet].recipes[0] = copper_sheet_recipe;
	d->items[e_iron_ore].recipes[0] = iron_ore_recipe;
	d->items[e_iron_ingot].recipes[0] = iron_ingot_recipe;
	d->items[e_iron_rod].recipes[0] = iron_rod_recipe;
	d->items[e_iron_plate].recipes[0] = iron_plate_recipe;
	d->items[e_limestone].recipes[0] = limestone_recipe;
	d->items[e_quickwire].recipes[0] = quickwire_recipe;
	d->items[e_screw].recipes[0] = screw_recipe;
	d->items[e_water].recipes[0] = water_recipe;
	d->items[e_wire].recipes[0] = wire_recipe;
}

//------------------------------------------------------------------------------

void init_data(t_data *d)
{
	init_items(d);
	init_buildings(d);
	init_recipes(d);
}
