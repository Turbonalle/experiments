#include <stdio.h>
#include <math.h>

#define ITEMS 100
#define BUILDINGS 100

#define ORE 0
#define ITEM 1

#define SMELTER 0
#define CONSTRUCTOR 1

#define IRON_ORE 0
#define IRON_INGOT 1

typedef struct s_item t_item;

typedef struct s_node
{
	char	*ore;
	int		quality;
}			t_node;

typedef struct s_requirement
{
	char	*item;
	int		amount_needed;
}			t_requirement;

typedef struct s_building
{
	char		*name;
	int			power_usage_MW;
	int			n_items_needed;
}				t_building;

typedef struct s_recipe
{
	int			production_amount;
	int			second_interval;
	t_item		*items_needed[4];
	int			item_amount_needed[4];
	t_item		*waste;
	t_building	building;
}				t_recipe;

typedef struct s_item
{
	int			type;
	int			recipe_amount;
	t_recipe	recipes[3];
	int			amount_needed;
}				t_item;

typedef struct s_data
{
	t_item			items[ITEMS];
	t_building		buildings[BUILDINGS];
	int				power_consumption;
	int				max_conveyor_speed;
	t_requirement	player_requirement;
}				t_data;