/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:07:13 by eleleux           #+#    #+#             */
/*   Updated: 2023/06/08 12:09:48 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	string_field_precision(t_printf *pf)
{
	if (pf->nothing != 0 && pf->field != 0)
		while (pf->j++ < pf->field)
			pf->result[pf->i++] = ' ';
	else if (!pf->dot && pf->field >= pf->arg_len)
		while (pf->j++ < (pf->field - pf->arg_len))
			pf->result[pf->i++] = ' ';
	else if (pf->field >= pf->precision && (pf->precision >= pf->arg_len
			&& pf->field > pf->arg_len))
		while (pf->j++ < (pf->field - pf->arg_len))
			pf->result[pf->i++] = ' ';
	else if (pf->field >= pf->precision && pf->field >= pf->arg_len
		&& pf->precision < pf->arg_len)
		while (pf->j++ < (pf->field - pf->precision))
			pf->result[pf->i++] = ' ';
	else if (pf->precision > pf->field && pf->precision > pf->arg_len)
		while (pf->j++ < pf->field - pf->arg_len)
			pf->result[pf->i++] = ' ';
	else if (pf->dot && !pf->space && pf->field > pf->precision
		&& pf->precision < pf->arg_len && pf->field < pf->arg_len)
		while (pf->j++ < (pf->field - pf->precision))
			pf->result[pf->i++] = ' ';
}

static void	nothing_case_with_field(t_printf *pf)
{
	if (pf->conversion == 'd' || pf->conversion == 'i')
	{
		print_for_d_i(pf);
	}
	else if (pf->conversion == 'u' || pf->conversion == 'x'
		|| pf->conversion == 'X')
	{
		if (pf->nothing && pf->hashtag)
			pf->field -= 2;
		if (pf->u_arg != 0)
			while (pf->j++ < (pf->field - pf->arg_len))
				pf->result[pf->i++] = ' ';
		else
			while (pf->j++ < pf->field)
				pf->result[pf->i++] = ' ';
		if (pf->hashtag && (pf->conversion == 'x' || pf->conversion == 'X')
			&& pf->u_arg != 0)
			print_0x(pf);
	}
	else if (pf->conversion == 'c')
		while (pf->j++ < (pf->field - pf->arg_len))
			pf->result[pf->i++] = ' ';
}

static void	try_some_more_cases(t_printf *pf)
{
	if (pf->field && pf->precision == 0 && pf->zero != 0)
	{
		if (pf->negative != 0)
		{
			pf->result[pf->i++] = '-';
			pf->negative = 0;
		}
		while (pf->j++ < (pf->field - pf->arg_len))
			pf->result[pf->i++] = '0';
	}
	else if (pf->field && pf->precision == 0)
	{
		while (pf->j++ < (pf->field - pf->arg_len))
			pf->result[pf->i++] = ' ';
		if (pf->negative != 0)
		{
			pf->result[pf->i++] = '-';
			pf->negative = 0;
		}
	}
}

static void	other_cases(t_printf *pf)
{
	if (pf->hashtag)
		pf->field -= 2;
	if (pf->field >= pf->precision && (pf->precision >= pf->arg_len
			&& pf->field > pf->arg_len) && pf->conversion != 's'
		&& pf->conversion != 'c')
		print_some_field(pf);
	else if (pf->field >= pf->precision && pf->precision > pf->arg_len)
	{
		while (pf->j++ < (pf->field - pf->precision))
			pf->result[pf->i++] = ' ';
	}
	else if (pf->dot && pf->field >= pf->precision
		&& pf->precision < pf->arg_len && pf->field >= pf->arg_len)
	{
		while (pf->j++ < (pf->field - pf->arg_len))
			pf->result[pf->i++] = ' ';
	}
	else
		try_some_more_cases(pf);
	if (pf->hashtag && (pf->conversion == 'x' || pf->conversion == 'X')
		&& pf->u_arg != 0 && (!pf->zero || pf->precision != 0))
		print_0x(pf);
}

void	field_precision_justify(t_printf *pf)
{
	if (pf->hashtag && (pf->conversion == 'x' || pf->conversion == 'X'))
	{
		if (pf->u_arg == 0)
			pf->field += 2;
	}
	if (pf->conversion == 's')
		string_field_precision(pf);
	else if (pf->nothing != 0 && pf->field != 0 && pf->conversion != 's')
		nothing_case_with_field(pf);
	else
		other_cases(pf);
}
