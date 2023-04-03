/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:07:40 by eleleux           #+#    #+#             */
/*   Updated: 2023/04/02 11:20:03 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/ft_printf.h"

int iput_char(char c)
{
	int	i;

	i = 1;
	write(fd, &c, 1);
	return (i);
}

int iput_str(char *str)
{
	int	i;

	if (!str)
		return (write(fd, "(null)", 6));
	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
	return (i);
}

int iput_nbr(int nb)
{
	long	i;
	int		count;
	char	tab[16];

	if (nbr == 0)
		return (iput_char('0'));
	count = 0;
    if (nbr < 0)
    {
        count += iput_char('-');
        nbr = -nbr;
    }
	i = 0;
    while (nbr > 0)
    {
        tab[i++] = nb % 10;
        nb /= 10;
    }
    tab[i] = '\0';
    i--;
    while (i >= 0)
        count += iput_char(tab[i--]);
	return (count);
}

int iput_hexa_base(size_t nb, char *base)
{
	size_t	i;
	char	tab[16];
	int		count;

	if (nbr == 0)
		return (iput_char('0'));
	count = 0;
	i = 0;
    while (nbr > 0)
    {
        tab[i++] = base[nbr % 16];
        nbr /= 16;
    }
    tab[i] = '\0';
    i--;
    while (i >= 0)
        count += iput_char(tab[i--]);
    return (count);
}
