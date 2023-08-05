#define BUILDINGS 100

enum	quality = { IMPURE, NORMAL, PURE };
enum	type = { ORE };

typedef struct s_node
{
	char	*ore;
	int		quality;
}			t_node;

typedef struct s_ore
{
	int		prod_impure;
	int		prod_normal;
	int		prod_pure;
}			t_ore;

typedef struct s_requirement
{
	char	*item;
	int		amount_needed;
}			t_requirement;

typedef struct S_building
{
	char		*name;
	int			power_usage_MW;
	int			n_items_needed;
}				t_building;

typedef struct s_recipe
{
	char		*product;
	int			type;
	int			production_amount;
	int			second_interval;
	t_building	building;
}				t_recipe;

typedef struct s_item
{
	char		*name;
	int			recipe_amount;
	t_recipe	recipes[3];
}				t_node;

typedef struct s_data
{
	t_building		buildings[BUILDINGS];
	int				power_consumption;
	int				max_conveyor_speed;
	T_requirement	player_requirement;
}				t_data;