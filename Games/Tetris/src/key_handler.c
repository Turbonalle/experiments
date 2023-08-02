#include "../incl/fractol.h"

int	handle_close(void)
{
	exit (1);
}

void	check_exit(t_data *data, int keycode)
{
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
}

int	handle_keys(int keycode, t_data *data)
{
	// printf("%d\n", keycode);
	check_exit(data, keycode);
	return (1);
}