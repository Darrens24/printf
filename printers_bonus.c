/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:07:40 by eleleux           #+#    #+#             */
/*   Updated: 2023/06/08 12:09:58 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	iput_char(char c)
{
	int	i;

	i = 1;
	write(1, &c, 1);
	return (i);
}

int	iput_str(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	iput_nbr(int nb)
{
	int		i;
	int		count;
	char	tab[16];

	if (nb == 0)
		return (iput_char('0'));
	if (nb == -2147483648)
		return (iput_str("2147483648"));
	count = 0;
	if (nb < 0)
		nb *= -1;
	i = 0;
	while (nb > 0)
	{
		tab[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	tab[i] = '\0';
	i--;
	while (i >= 0)
		count += iput_char(tab[i--]);
	return (count);
}

int	iput_unsigned(unsigned int nb)
{
	unsigned int	i;
	int				count;
	char			tab[16];

	if (nb == 0)
		return (iput_char('0'));
	count = 0;
	i = 0;
	while (nb > 0)
	{
		tab[i++] = nb % 10 + '0';
		nb /= 10;
	}
	tab[i] = '\0';
	i--;
	while (i > 0)
		count += iput_char(tab[i--]);
	count += iput_char(tab[i]);
	return (count);
}

int	iput_hexa_base(size_t nb, char *base)
{
	size_t	i;
	char	tab[16];
	int		count;

	if (nb == 0)
		return (iput_char('0'));
	count = 0;
	i = 0;
	while (nb > 0)
	{
		tab[i++] = base[nb % 16];
		nb /= 16;
	}
	i--;
	while (i > 0)
		count += iput_char(tab[i--]);
	count += iput_char(tab[i]);
	return (count);
}
