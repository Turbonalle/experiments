/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_by_iteration.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:02:55 by jbagger           #+#    #+#             */
/*   Updated: 2023/03/28 15:32:39 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	color_crazy_rainbow(int i)
{
	int	c[5];

	c[0] = RED;
	c[1] = CYAN;
	c[2] = YELLOW;
	c[3] = MAGENTA;
	c[4] = LIME;
	return (c[i % 5]);
}

int	color_pink_psychedelic(int i, int turn)
{
	t_map	map;
	t_color	c;

	map.val = i;
	map.min1 = 0;
	map.max1 = turn;
	find_rgb(&map, &c, BLACK, HOT_PINK);
	return (set_color(0, c.r, c.g, c.b));
}

int	color_black_pink(int i, int max_i)
{
	t_map	map;
	t_color	c;

	map.val = i;
	map.min1 = 0;
	map.max1 = max_i;
	find_rgb(&map, &c, BLACK, HOT_PINK);
	return (set_color(0, c.r, c.g, c.b));
}

int	color_blue_brown(int i, int max_i, int turn)
{
	t_map	map;
	t_color	c;

	map.val = i;
	if (i < turn)
	{
		map.min1 = 0;
		map.max1 = turn;
		find_rgb(&map, &c, ALICE_BLUE, MIDNIGHT_BLUE);
	}
	else
	{
		map.min1 = turn;
		map.max1 = max_i;
		find_rgb(&map, &c, MIDNIGHT_BLUE, SADDLEBROWN);
	}
	return (set_color(0, c.r, c.g, c.b));
}

void	get_color(t_mega *mega, t_map *mi)
{
	int	turn;
	int	n;

	turn = 80;
	n = map_struct(mi);
	if (mega->color_scheme == 0)
		mega->color = set_color(0, n, n, n);
	else if (mega->color_scheme == 1)
		mega->color = color_crazy_rainbow(mi->val);
	else if (mega->color_scheme == 2)
		mega->color = color_blue_brown(mi->val, mi->max2, turn);
	else if (mega->color_scheme == 3)
		mega->color = color_pink_psychedelic(mi->val, turn);
	else if (mega->color_scheme == 4)
		mega->color = color_black_pink(mi->val, mi->max2);
	if (mi->val == mi->max2)
		mega->color = BLACK;
}
