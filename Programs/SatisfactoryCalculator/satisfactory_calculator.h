#include "item_list.h"
#include "building_list.h"
#include <stdio.h>
#include <math.h>

#define BUILDINGS 100

#define ORE 0
#define ITEM 1

typedef struct s_item t_item;

typedef struct s_node
{
	char	*ore;
	int		quality;
}			t_node;

typedef struct s_requirement
{
	t_item	*item;
	double	amount_needed;
}			t_requirement;

typedef struct s_building
{
	char		*name;
	int			power_usage_MW;
}				t_building;

typedef struct s_recipe
{
	char 		*recipe_name;
	double		production_amount;
	double		second_interval;
	int			n_resources;
	t_item		*items_needed[4];
	double		item_amount_needed[4];
	t_item		*waste;
	t_building	building;
}				t_recipe;

typedef struct s_item
{
	char		*name;
	int			type;
	int			recipe_amount;
	t_recipe	recipes[3];
	double		amount_needed;
}				t_item;

typedef struct s_data
{
	t_item			items[ITEMS];
	t_building		buildings[BUILDINGS];
	double			power_consumption;
	int				max_conveyor_speed;
	t_requirement	player_requirement;
}				t_data;

// recipes.c
void create_iron_ore_recipe(t_data *d);
void create_iron_ingot_recipe(t_data *d);
void create_iron_rod_recipe(t_data *d);

// print_result.c
void print_item_requirements(t_data *d);
void print_power_consumption(t_data *d);

// init_data.c
void init_data(t_data *d);

