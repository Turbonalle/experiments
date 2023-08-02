#include "../incl/fractol.h"

void	mlx_pixel_put2(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr;
	dst += (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	clear_image(t_data *data)
{
	t_index	i;

	i.y = 0;
	while (i.y < HEIGHT)
	{
		i.x = 0;
		while (i.x < WIDTH)
		{
			mlx_pixel_put2(data, i.x, i.y, 0);
			i.x++;
		}
		i.y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}