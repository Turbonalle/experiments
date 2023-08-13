#include "satisfactory_calculator.h"

//------------------------------------------------------------------------------

void init_buildings(t_data *d)
{
	// Create buildings
	t_building	miner = { "Miner", 30 };
	d->buildings[e_miner] = miner;
	t_building	smelter = { "Smelter", 4 };
	d->buildings[e_smelter] = smelter;
	t_building	constructor = { "Constructor", 4 };
	d->buildings[e_constructor] = constructor;
	t_building	assembler = { "Assembler", 15 };
	d->buildings[e_assembler] = assembler;
	t_building	manufacturer = { "Manufacturer", 55 };
	d->buildings[e_manufacturer] = manufacturer;
	t_building	foundry = { "Foundry", 16 };
	d->buildings[e_foundry] = foundry;
	t_building	refinery = { "Refinery", 30 };
	d->buildings[e_refinery] = refinery;
	t_building	water_extractor = { "Water Extractor", 20 };
	d->buildings[e_water_extractor] = water_extractor;
	t_building	oil_extractor = { "Oil Extractor", 50 };
	d->buildings[e_oil_extractor] = oil_extractor;
	t_building	resource_well_extractor = { "Resource Well Extractor", 0 };
	d->buildings[e_resource_well_extractor] = resource_well_extractor;
	t_building	blender = { "Blender", 75 };
	d->buildings[e_blender] = blender;
	t_building	particle_accelerator = { "Particle Accelerator", 50 };
	d->buildings[e_particle_accelerator] = particle_accelerator;
	t_building	nuclear_power_plant = { "Nuclear Power Plant", 2500 };
	d->buildings[e_nuclear_power_plant] = nuclear_power_plant;
}