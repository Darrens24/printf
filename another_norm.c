/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:26:48 by eleleux           #+#    #+#             */
/*   Updated: 2023/06/08 12:08:48 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nothing_cases(t_printf *pf)
{
	if (pf->conversion == 'd' || pf->conversion == 'i')
	{
		if (pf->i_arg == 0)
			return (1);
	}
	if (pf->conversion == 'u' || pf->conversion == 'x' || pf->conversion == 'X')
	{
		if (pf->u_arg == 0)
			return (1);
	}
	else if (pf->conversion == 's')
		return (1);
	return (0);
}

void	put_left_flags(t_printf *pf)
{
	if (pf->minus)
		minus_left(pf);
	else
		standard_justify(pf);
}

void	minus_left(t_printf *pf)
{
	int	j;

	minus_norm(pf);
	j = 0;
	if (pf->negative != 0)
		pf->result[pf->i++] = '-';
	if (pf->precision >= pf->arg_len && pf->conversion != 's'
		&& pf->conversion != 'c')
	{
		while (j++ < (pf->precision - pf->arg_len))
			pf->result[pf->i++] = '0';
		if (pf->negative)
			pf->result[pf->i++] = '0';
	}
	if (pf->i != 0)
	{
		pf->result[pf->i] = '\0';
		pf->count += iput_str(pf->result);
	}
}

void	hashtag_justify(t_printf *pf)
{
	if (pf->hashtag && (pf->conversion == 'x'
			|| pf->conversion == 'X') && pf->u_arg != 0
		&& pf->zero && pf->field > pf->arg_len && !pf->dot)
	{
		pf->result[pf->i] = '0';
		if (pf->conversion == 'x')
			pf->result[pf->i + 1] = 'x';
		else if (pf->conversion == 'X')
			pf->result[pf->i + 1] = 'X';
		pf->i += 2;
	}
	else if (pf->hashtag && (pf->conversion == 'x'
			|| pf->conversion == 'X') && pf->u_arg != 0 && pf->zero
		&& pf->field <= pf->arg_len && (!pf->dot
			|| (pf->nothing && !pf->field)))
	{
		pf->result[pf->i] = '0';
		if (pf->conversion == 'x')
			pf->result[pf->i + 1] = 'x';
		else if (pf->conversion == 'X')
			pf->result[pf->i + 1] = 'X';
		pf->i += 2;
	}
}

int	print_untill_precision(t_printf *pf)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < pf->precision)
		count += iput_char(pf->s_arg[i++]);
	return (count);
}
