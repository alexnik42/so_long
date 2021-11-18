/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:08:02 by crendeha          #+#    #+#             */
/*   Updated: 2021/11/03 12:39:48 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_white_space(char c)
{
	return (c == ' ' || c == '\t'
		|| c == '\n' || c == '\v'
		|| c == '\f' || c == '\r');
}

int	ft_atoi(const char *str)
{
	int				i;
	long long int	num;
	long long int	sign;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] != '\0' && is_white_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
		num = num * 10 + (str[i++] - 48);
	num *= sign;
	if (num <= 2147483647 && num >= -2147483648)
		return ((int) num);
	else if (sign == 1)
		return (-1);
	else
		return (0);
}
