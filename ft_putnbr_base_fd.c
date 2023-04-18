/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:41:48 by eleleux           #+#    #+#             */
/*   Updated: 2023/04/17 15:02:05 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int		i;
	int		count;
	char	tab[16];

	i = 0;
	count = 0;
	if (nbr == 0)
		return (count += ft_intputchar_fd('0', fd));
	if (nbr == -2147483648)
		return (count += ft_intputstr_fd("-2147483648", fd));
	if (nbr < 0)
	{
		count += ft_intputchar_fd('-', fd);
		nbr *= -1;
	}
	while (nbr > 0)
	{
		tab[i] = base[nbr % ft_strlen(base)];
		nbr /= ft_strlen(base);
		i++;
	}
	tab[i] = '\0';
	i--;
	while (i >= 0)
		count += ft_intputchar_fd(tab[i--], fd);
	return (count);
}
