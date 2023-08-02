/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_by_iterations_pink.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:08:08 by jbagger           #+#    #+#             */
/*   Updated: 2023/03/22 18:09:27 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	find_rgb(t_map *map, t_color *c, int color1, int color2)
{
	map->min2 = get_r(color1);
	map->max2 = get_r(color2);
	c->r = map_struct(map);
	map->min2 = get_g(color1);
	map->max2 = get_g(color2);
	c->g = map_struct(map);
	map->min2 = get_b(color1);
	map->max2 = get_b(color2);
	c->b = map_struct(map);
}
