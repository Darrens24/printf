/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:29:52 by eleleux           #+#    #+#             */
/*   Updated: 2023/06/08 12:09:27 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	minus_norm(t_printf *pf)
{
	if (pf->plus != 0 && (pf->conversion == 'd'
			|| pf->conversion == 'i') && pf->i_arg >= 0)
		pf->result[pf->i++] = '+';
	else if (pf->space != 0 && (pf->conversion == 'd'
			|| pf->conversion == 'i') && pf->i_arg >= 0)
	{
		pf->result[pf->i++] = ' ';
		if (pf->precision > pf->arg_len)
			pf->field--;
	}
	else if (pf->hashtag && (pf->conversion == 'x'
			|| pf->conversion == 'X') && pf->u_arg != 0)
	{
		pf->result[pf->i] = '0';
		if (pf->conversion == 'x')
			pf->result[pf->i + 1] = 'x';
		else if (pf->conversion == 'X')
			pf->result[pf->i + 1] = 'X';
		pf->i += 2;
	}
}

void	norm_justify(t_printf *pf)
{
	if (pf->plus != 0 && pf->zero != 0 && pf->dot == 0 && (pf->conversion == 'd'
			|| pf->conversion == 'i') && pf->i_arg >= 0)
		pf->result[pf->i++] = '+';
}

void	arg_is_negative(t_printf *pf)
{
	pf->negative++;
	if (pf->field > pf->arg_len && pf->precision > pf->arg_len)
		pf->field--;
}

void	arg_is_char_or_percent(t_printf *pf)
{
	if (pf->conversion == 'c')
	{
		pf->c_arg = va_arg(pf->ap, int);
		pf->arg_len = 1;
	}
	else if (pf->conversion == '%')
	{
		pf->c_arg = '%';
		pf->arg_len = 1;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*recipe;
	size_t	memory;
	size_t	i;

	if (count && size > SIZE_MAX / count)
		return (NULL);
	memory = count * size;
	recipe = malloc(sizeof(char) * memory);
	if (!recipe)
		return (NULL);
	i = 0;
	while (memory--)
		recipe[i++] = 0;
	return ((void *)recipe);
}
