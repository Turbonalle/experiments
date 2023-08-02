/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:03:15 by jbagger           #+#    #+#             */
/*   Updated: 2023/03/28 15:37:05 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(double base, double exponent)
{
	double	result;

	result = 1;
	if (exponent < 0)
	{
		while (exponent++)
			result /= base;
	}
	else
	{
		while (exponent-- > 0)
			result *= base;
	}
	return (result);
}
