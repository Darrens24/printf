/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:41:48 by eleleux           #+#    #+#             */
/*   Updated: 2023/04/12 12:55:08 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_fd(long nbr, char *base, int fd)
{
	long	i;
	int		count;
	char	tab[16];

	i = 0;
	count = 0;
	if (nbr == 0)
		count += ft_intputchar_fd('0', fd);
    if (nbr < 0)
    {
        count += ft_intputchar_fd('-', fd);
        nbr = -nbr;
    }
    while (nbr > 0)
    {
        tab[i++] = base[nbr % (long)ft_strlen(base)];
        nbr /= (long)ft_strlen(base);
    }
    tab[i] = '\0';
    i--;
    while (i >= 0)
        count += ft_intputchar_fd(tab[i--], fd);
    return (count);
}
