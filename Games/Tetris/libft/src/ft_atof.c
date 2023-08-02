/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:04:15 by jbagger           #+#    #+#             */
/*   Updated: 2023/03/28 15:36:43 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	handle_comma(double *result, char *str, int *i)
{
	double	fraction;
	int		divisor;

	fraction = 0.0;
	divisor = 1;
	if (str[*i] == '.')
	{
		(*i)++;
		while (ft_isdigit(str[*i]))
		{
			fraction = fraction * 10.0 + str[*i] - '0';
			divisor *= 10;
			(*i)++;
		}
		*result = *result + (fraction / divisor);
	}
}

void	handle_exponent(double *result, char *str, int *i)
{
	int	exponent;
	int	exponent_sign;

	exponent = 0;
	exponent_sign = 1;
	if (str[*i] == 'e' || str[*i] == 'E')
	{
		(*i)++;
		if (str[*i] == '-')
		{
			exponent_sign = -1;
			(*i)++;
		}
		else if (str[*i] == '+')
			(*i)++;
		while (ft_isdigit(str[*i]))
		{
			exponent = exponent * 10 + (str[*i] - '0');
			(*i)++;
		}
		exponent *= exponent_sign;
		*result *= ft_pow(10.0, exponent);
	}
}

double	ft_atof(char *str)
{
	double	result;
	int		sign;
	int		i;

	result = 0.0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10.0 + str[i] - '0';
		i++;
	}
	handle_comma(&result, str, &i);
	handle_exponent(&result, str, &i);
	result *= sign;
	return (result);
}
