#include "../incl/fractol.h"

void	draw_bg(t_data *data)
{
	t_index i;

	i.y = -1;
	while (++i.y < HEIGHT)
	{
		i.x = -1;
		while (++i.x < WIDTH)
			mlx_pixel_put2(data, i.x, i.y, data->bg);
	}
}

// void	draw_grid(t_data *data)
// {
	
// }

void	set_game_info(t_data *data)
{
	data->bg = DARK_GRAY;
}

void	tetris(t_data *data)
{
	set_game_info(data);
	draw_bg(data);
	// draw_grid(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

int main(void)
{
	t_data	data;

	if (!init_variables(&data))
	{
		printf("Initializing failed\n");
		exit (-1);
	}
	mlx_hook(data.win, 17, 0, handle_close, &data);
	mlx_key_hook(data.win, handle_keys, &data);
	tetris(&data);
	mlx_loop(data.mlx);
	return (0);
}