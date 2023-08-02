/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:25:31 by jbagger           #+#    #+#             */
/*   Updated: 2023/03/28 15:31:53 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	main(int ac, char *av[])
{
	t_data	data;

	if ((ac != 2 && ac != 4) || !init_fractal(&data, av[1]))
	{
		ft_printf("\033[32mUsage: ./fractol Fractal\n");
		ft_printf("[Mandelbrot] [Julia]\n");
		exit(-1);
	}
	if (ac == 4)
	{
		if (!init_variables(&data, atof(av[2]), atof(av[3])))
			ft_printf("Failed to initialize variables\n");
	}
	else
	{
		if (!init_variables(&data, 0, 0))
			ft_printf("Failed to initialize variables\n");
	}
	init_img(&data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, 17, 0, handle_close, &data);
	mlx_key_hook(data.win, handle_keys, &data);
	fractol(&data);
	mlx_loop(data.mlx);
	return (0);
}
