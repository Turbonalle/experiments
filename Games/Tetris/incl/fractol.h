/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:14:30 by jbagger           #+#    #+#             */
/*   Updated: 2023/03/30 11:21:04 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "keys_windows.h"
# include "colors.h"
# define WIDTH 800
# define HEIGHT 800
# define EMPTY 0

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}		t_color;

typedef struct s_index
{
	int		x;
	int		y;
}			t_index;

typedef struct s_index_d
{
	double		x;
	double		y;
}				t_index_d;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_image;

typedef struct s_display
{
	double	miny;
	double	minx;
	double	size;
}			t_display;

typedef struct s_map
{
	int	val;
	int	min1;
	int	max1;
	int	min2;
	int	max2;
}		t_map;

typedef struct s_box
{
	int		x;
	int		y;
	int		state;
	int		color;
	int		piece;
}			t_box;

typedef struct s_grid
{
	t_box	grid[20][10];
	int		columns;
	int		lines;
	int		bg;
	int		thickness;
	t_index	pos;
}			t_grid;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_image			img;
	int				bg;
	t_grid			grid;
}					t_data;

// MAIN

// INIT
void	init_img(t_data *data);
int		init_variables(t_data *data);

// HOOKS
int		mouse_hook(int keycode, int x, int y, t_data *data);
int		handle_keys(int keycode, t_data *data);
int		handle_close(void);
void	zoom(t_data *data, int x, int y, double multiplier);

// KEY_CHECKS
void	check_exit(t_data *data, int keycode);
void	check_reset(t_data *data, int keycode);
void	check_pan(t_data *data, int keycode);
void	check_zoom(t_data *data, int keycode);
void	check_color(t_data *data, int keycode);
void	check_julia_constant(t_data *data, int keycode);
void	check_fractal(t_data *data, int keycode);

// DRAWING
void	mlx_pixel_put2(t_data *data, int x, int y, int color);
void	clear_image(t_data *data);

// COLORS
int		set_color(int transparency, int red, int green, int blue);
int		get_t(int color);
int		get_r(int color);
int		get_g(int color);
int		get_b(int color);

#endif