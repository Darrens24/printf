/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:20:24 by eleleux           #+#    #+#             */
/*   Updated: 2023/04/02 11:24:24 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/ft_printf.h"

size_t  ft_strlen(const char *str)
{
	size_t	i;

    if (!str)
        return (0);
	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	res;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	minus = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * minus);
}
