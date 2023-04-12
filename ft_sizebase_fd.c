/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizebase_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:41:48 by eleleux           #+#    #+#             */
/*   Updated: 2023/04/12 12:56:51 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sizebase_fd(size_t nbr, char *base, int fd)
{
	size_t	i;
	char	tab[16];
	int		count;

	count = 0;
	if (nbr == 0)
		return (count += ft_intputchar_fd('0', fd));
	i = 0;
    while (nbr > 0)
    {
        tab[i++] = base[nbr % ft_strlen(base)];
        nbr /= ft_strlen(base);
    }
    tab[i] = '\0';
    while (i > 0)
        count += ft_intputchar_fd(tab[i--], fd);
    count += ft_intputchar_fd(tab[i], fd);
    return (count);
}
