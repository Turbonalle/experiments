/**
 * Main MLX handle, carries important data in regards to the program.
 * @param window The window itself.
 * @param context Abstracted opengl data.
 * @param width The width of the window.
 * @param height The height of the window.
 * @param delta_time The time difference between the previous frame and the current frame.
 */

/**
typedef struct mlx
{
	void*		window;
	void*		context;
	int			width;
	int			height;
	double		delta_time;
}	mlx_t;
*/

// Note: Compile MLX42 with -DDEBUG=1 to see assertions and to add debug flags. This can help you find critical mistakes during development!

#include "../lib/raycaster.h"

//------------------------------------------------------------------------------

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void reset_map(map_t *map)
{
	int column;
	int row;

	row = -1;
	while (++row < map->rows)
	{
		column = -1;
		while (++column < map->columns)
			map->grid[row][column] = 0;
	}
}

int	main(void)
{
	// mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx;
	mlx_image_t* img;
	map_t map;

	mlx = mlx_init(WIDTH, HEIGHT, "Raycaster", true);
	if (!mlx)
		ft_error();
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	init_map(&map, 30, 30, 16);
	print_map(&map);

	draw_background(img, BLACK);
	draw_grid_relative_size(img, DARK_GRAY, map.columns, map.rows);

	mlx_key_hook(mlx, &my_keyhook, NULL);
	mlx_scroll_hook(mlx, &my_scrollhook, NULL);
	mlx_loop_hook(mlx, &my_hook, mlx);
	mlx_mouse_hook(mlx, &my_mousehook, NULL);
	
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_map(&map);
	return (EXIT_SUCCESS);
}