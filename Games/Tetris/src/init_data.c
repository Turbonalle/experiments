#include "../incl/fractol.h"

void	init_img(t_data *data)
{
	int	bpp;
	int	line_len;
	int	endian;

	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &bpp, &line_len, &endian);
	data->img.bpp = bpp;
	data->img.line_len = line_len;
	data->img.endian = endian;
}

int	init_variables(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_printf("Mlx initialization failed\n");
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Tetris");
	if (!data->win)
		ft_printf("Window creation failed\n");
	init_img(data);
	if (!data->img.img)
		ft_printf("Image creation failed\n");
	return (1);
}