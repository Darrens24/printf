/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:30:06 by eleleux           #+#    #+#             */
/*   Updated: 2023/06/08 12:09:06 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	space_case(t_printf *pf)
{
	if (pf->space != 0 && (pf->conversion == 'd' || pf->conversion == 'i')
		&& (pf->field <= 0 || pf->field <= pf->precision
			|| pf->arg_len >= pf->field || pf->zero) && !pf->negative)
	{
		pf->result[pf->i++] = ' ';
		pf->field--;
	}
}

void	standard_justify(t_printf *pf)
{
	int	j;

	space_case(pf);
	norm_justify(pf);
	hashtag_justify(pf);
	field_precision_justify(pf);
	if (pf->plus != 0 && (pf->zero == 0 || pf->dot) && (pf->conversion == 'd'
			|| pf->conversion == 'i') && pf->i_arg >= 0)
		pf->result[pf->i++] = '+';
	j = 0;
	if (pf->negative != 0)
		pf->arg_len--;
	if (pf->negative != 0)
		pf->result[pf->i++] = '-';
	if (pf->precision > pf->arg_len && pf->conversion != 's')
	{
		while (j++ < (pf->precision - pf->arg_len))
			pf->result[pf->i++] = '0';
	}
	if (pf->result && pf->i != 0)
	{
		pf->result[pf->i] = '\0';
		pf->count += iput_str(pf->result);
	}
}

static int	return_cases(t_printf *pf)
{
	if (pf->field <= pf->arg_len && (pf->conversion == 'i'
			|| pf->conversion == 'd') && pf->i_arg != 0)
		return (1);
	else if (pf->field <= pf->arg_len && pf->conversion == 'u'
		&& pf->u_arg != 0)
		return (1);
	else if (pf->field <= pf->arg_len && (pf->conversion == 'i'
			|| pf->conversion == 'd') && pf->i_arg == 0 && pf->space
		&& pf->nothing)
		return (1);
	return (0);
}

static void	print_right(t_printf *pf, int i)
{
	if (return_cases(pf))
		return ;
	if (pf->negative != 0 && !pf->dot)
		i--;
	else if (pf->negative && pf->field > pf->arg_len
		&& pf->precision <= pf->arg_len)
		i--;
	else if (pf->space && pf->nothing && (pf->conversion == 'i'
			|| pf->conversion == 'd') && pf->i_arg == 0)
		i++;
	else if (pf->nothing && pf->conversion == 'u' && pf->u_arg != 0)
		while (++pf->k < pf->arg_len)
			i++;
	else if (pf->plus && pf->arg_len >= pf->precision && pf->i_arg != 0)
		i--;
	else if ((pf->conversion == 'i' || pf->conversion == 'd') && pf->i_arg == 0
		&& (pf->plus) && (!pf->dot || pf->precision <= pf->arg_len)
		&& pf->nothing == 0)
		i--;
	while (i < pf->field)
	{
		pf->count += iput_char(' ');
		i++;
	}
}

void	put_right_flags(t_printf *pf)
{
	int	i;

	if (pf->dot && pf->precision < pf->arg_len && pf->conversion == 's')
		i = pf->precision;
	else if (pf->dot && pf->precision > pf->arg_len && (pf->conversion == 'd'
			|| pf->conversion == 'i'))
		i = pf->precision;
	else if (pf->nothing && (pf->conversion == 'x' || pf->conversion == 'X')
		&& pf->u_arg != 0)
		i = pf->arg_len + ft_strlen(pf->result);
	else if (pf->nothing && (pf->conversion == 'i' || pf->conversion == 'd')
		&& pf->i_arg != 0 && pf->field > pf->arg_len)
		i = pf->arg_len + ft_strlen(pf->result);
	else if (pf->nothing && pf->conversion != 's')
		i = 0;
	else
		i = pf->arg_len + ft_strlen(pf->result);
	print_right(pf, i);
}
