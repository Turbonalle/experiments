#include "satisfactory_calculator.h"

void	init_elevator_items(t_data *d)
{
	t_item	adaptive_control_unit = { "adaptive_control_unit", ELEVATOR_ITEM, 1, NULL, 0, 0, 0 };
	d->items[e_adaptive_control_unit] = adaptive_control_unit;
	t_item	assembly_director_system = { "assembly_director_system", ELEVATOR_ITEM, 1, NULL, 0, 0, 0 };
	d->items[e_assembly_director_system] = assembly_director_system;
	t_item	automated_wiring = { "automated_wiring", ELEVATOR_ITEM, 1, NULL, 0, 0, 0 };
	d->items[e_automated_wiring] = automated_wiring;
	t_item	magnetic_field_generator = { "magnetic_field_generator", ELEVATOR_ITEM, 1, NULL, 0, 0, 0 };
	d->items[e_magnetic_field_generator] = magnetic_field_generator;
	t_item	modular_engine = { "modular_engine", ELEVATOR_ITEM, 1, NULL, 0, 0, 0 };
	d->items[e_modular_engine] = modular_engine;
	t_item	nuclear_pasta = { "nuclear_pasta", ELEVATOR_ITEM, 1, NULL, 0, 0, 0 };
	d->items[e_nuclear_pasta] = nuclear_pasta;
	t_item	smart_plating = { "smart_plating", ELEVATOR_ITEM, 1, NULL, 0, 0, 0 };
	d->items[e_smart_plating] = smart_plating;
	t_item	versatile_framework = { "versatile_framework", ITEM, 1, NULL, 0, 0, 0 };
	d->items[e_versatile_framework] = versatile_framework;
}

//------------------------------------------------------------------------------

void	init_elevator_item_recipes(t_data *d)
{
	t_recipe adaptive_control_unit_recipe = { "adaptive_control_unit", 1, 120, 4, { &d->items[e_automated_wiring], &d->items[e_circuit_board], &d->items[e_heavy_modular_frame], &d->items[e_computer] }, { 7.5, 5, 1, 1 }, NULL, 0, d->buildings[e_manufacturer] };
	d->items[e_adaptive_control_unit].recipes[0] = adaptive_control_unit_recipe;
	t_recipe assembly_director_system_recipe = { "assemply_director_system", 0.75, 80, 2, { &d->items[e_adaptive_control_unit], &d->items[e_supercomputer] }, { 1.5, 0.75 }, NULL, 0, d->buildings[e_assembler] };
	d->items[e_assembly_director_system].recipes[0] = assembly_director_system_recipe;
	t_recipe automated_wiring_recipe = { "automated_wiring", 2.5, 24, 2, { &d->items[e_stator], &d->items[e_cable] }, { 2.5, 50 }, NULL, 0, d->buildings[e_assembler] };
	d->items[e_automated_wiring].recipes[0] = automated_wiring_recipe;
	t_recipe magnetic_field_generator_recipe = { "magnetic_field_generator", 1, 120, 3, { &d->items[e_versatile_framework], &d->items[e_electromagnetic_control_rod], &d->items[e_battery] }, { 2.5, 1, 5 }, NULL, 0, d->buildings[e_manufacturer] };
	d->items[e_magnetic_field_generator].recipes[0] = magnetic_field_generator_recipe;
	t_recipe modular_engine_recipe = { "modular_engine", 1, 60, 3, { &d->items[e_motor], &d->items[e_rubber], &d->items[e_smart_plating] }, { 2, 15, 2 }, NULL, 0, d->buildings[e_manufacturer] };
	d->items[e_modular_engine].recipes[0] = modular_engine_recipe;
	t_recipe nuclear_pasta = { "nuclear_pasta", 0.5, 120, 2, { &d->items[e_copper_powder], &d->items[e_pressure_conversion_cube] }, { 100, 0.5 }, NULL, 0, d->buildings[e_particle_accelerator] };
	d->items[e_nuclear_pasta].recipes[0] = nuclear_pasta;
	t_recipe smart_plating_recipe = { "smart_plating", 2, 30, 2, { &d->items[e_reinforced_iron_plate], &d->items[e_rotor] }, { 2, 2 }, NULL, 0, d->buildings[e_assembler] };
	d->items[e_smart_plating].recipes[0] = smart_plating_recipe;
	t_recipe versatile_framework_recipe = { "versatile_framework", 5, 24, 2, { &d->items[e_modular_frame], &d->items[e_steel_beam] }, { 2.5, 30 }, NULL, 0, d->buildings[e_assembler] };
	d->items[e_versatile_framework].recipes[0] = versatile_framework_recipe;
}