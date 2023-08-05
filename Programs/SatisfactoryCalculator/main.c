#include "satisfactory_calculator.h"

void	init_buildings(data *d)
{
	// building: { name, power_usage, items_needed }
	t_building	smelter = { "smelter", 4, 1 };
	t_building	constructor = { "constructor", 4, 1 };

	d.buildings[0] = smelter;

}

void	init_items(data *d)
{
	t_recipe	iron_ingot;

	iron_ingot.product = "iron_ingot";
	iron_ingot.production_amount = 30;
	iron_ingot.second_interval = 2;
	iron_ingot.building = d.buildings.smelter;
	
	d.recipes[0] = iron_ingot;
}

void	get_player_requirement(data *d)
{
	d.player_requirement.item = "iron_ingot";
	d.player_requirement.amount_needed = 60;
}

int main(void)
{
	t_data d;

	init_buildings(&d);
	init_items(&d);

	get_player_requirement(&d);
	calculate_requirements(&d);

	

	iron_ore.requirement = iron_ingot.requirement / iron_ingot.production_amount * iron_ingot.input.iron_ore;

	return (0);
}

double x = 100 / 30 * 30