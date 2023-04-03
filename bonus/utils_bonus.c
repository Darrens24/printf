/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:48:58 by eleleux           #+#    #+#             */
/*   Updated: 2023/04/02 15:18:00 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int nb_len(int nb)
{
    int len;

    if (nb == 0)
        return (1);
    len = 0;
    if (nb < 0)
    {
        len++;
        nb = -nb;
    }
    while (nb > 0)
    {
        len++;
        nb /= 10;
    }
    return (len);
}

int u_nb_len(unsigned int nb);
{
    int len;

    if (nb == 0)
        return (1);
    len = 0;
    while (nb > 0)
    {
        len++;
        nb /= 10;
    }
    return (len);
}

int hexa_len(size_t nb, char *base)
{
	size_t  i;
	char	tab[16];

	if (nbr == 0)
		return (1);
	i = 0;
    while (nbr > 0)
    {
        tab[i++] = base[nbr % 16];
        nbr /= 16;
    }
    tab[i] = '\0';
    return ((int)ft_strlen(tab));
}

int is_flag(char c)
{
    if (c == '-' || c == '+' || c == '0' || c == ' '
            || c == '#' || c == '.')
        return (TRUE);
    return (FALSE);
}

int is_conversion(char c)
{
    if (c == 'd' || c == 'i' || c == 'u' || c == 'x'
            || c == 'X' || c == 'p' || c == 'c' || c == 's')
        return (TRUE);
    return (FALSE);
}

int go_to_next_arg(t_printf *pf, int i)
{
    while (pf->string[i] && (is_flag(pf->string[i])
                || ft_isdigit(pf->string[i])))
        i++;
    return (i);
}
