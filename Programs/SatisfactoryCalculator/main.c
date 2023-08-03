#define BUILDINGS 100

enum	quality = { IMPURE, NORMAL, PURE };
enum	type = { ORE };

typedef struct node
{
	char	*ore;
	int		quality;
}

typedef struct ore
{
	int		prod_impure;
	int		prod_normal;
	int		prod_pure;
}		ore;

typedef struct item
{
	char	*name;
	int		recipe_amount;
	recipe	recipes[3];
}

typedef struct requirement
{
	char	*item;
	int		amount_needed;
}			requirement;

typedef struct recipe
{
	char		*product;
	int			type;
	int			production_amount;
	int			second_interval;
	building	building;
}				recipe;

typedef struct building
{
	char		*name;
	int			power_usage_MW;
	int			n_items_needed;
}				building;

typedef struct data
{
	building	buildings[BUILDINGS];
	int			power_consumption;
	int			max_conveyor_speed;
}				data;

void	init_buildings(data *d)
{
	building	smelter = { "smelter", 4, 1 };
	building	constructor = { "constructor", 4, 1 };

	d.buildings[0] = smelter;

}

void	init_items(data *d)
{
	recipe	iron_ingot;

	iron_ingot.product = "iron_ingot";
	iron_ingot.production_amount = 30;
	iron_ingot.second_interval = 2;
	iron_ingot.building = d.buildings.smelter;
	
	d.recipes[0] = iron_ingot;
}

int main(void)
{
	data d;

	init_buildings(&d);
	init_items(&d);

	return (0);
}