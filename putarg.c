/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putarg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:37:15 by eleleux           #+#    #+#             */
/*   Updated: 2023/06/08 12:10:20 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_arg(t_printf *pf)
{
	if (pf->nothing && nothing_cases(pf))
		return ;
	else if (pf->conversion == 'd' || pf->conversion == 'i')
		pf->count += iput_nbr(pf->i_arg);
	else if (pf->conversion == 'x')
		pf->count += iput_hexa_base(pf->u_arg, HEXALOW);
	else if (pf->conversion == 'X')
		pf->count += iput_hexa_base(pf->u_arg, HEXAUP);
	else if (pf->conversion == 'u')
		pf->count += iput_unsigned(pf->u_arg);
	else if (pf->conversion == 'p')
	{
		pf->count += iput_str("0x");
		pf->count += iput_hexa_base((size_t)pf->p_arg, HEXALOW);
	}
	else if (pf->conversion == 's')
	{
		if (pf->arg_len > pf->precision && pf->dot)
			pf->count += print_untill_precision(pf);
		else
			pf->count += iput_str(pf->s_arg);
	}
	else
		pf->count += iput_char(pf->c_arg);
}

void	print_0x(t_printf *pf)
{
	pf->result[pf->i] = '0';
	if (pf->conversion == 'x')
		pf->result[pf->i + 1] = 'x';
	else if (pf->conversion == 'X')
		pf->result[pf->i + 1] = 'X';
	pf->i += 2;
}

void	print_for_d_i(t_printf *pf)
{
	if (pf->i_arg != 0)
		while (pf->j++ < (pf->field - pf->arg_len))
			pf->result[pf->i++] = ' ';
	else
		while (pf->j++ < pf->field)
			pf->result[pf->i++] = ' ';
}

void	print_some_field(t_printf *pf)
{
	if (pf->negative && pf->arg_len >= pf->precision)
		pf->field--;
	while (pf->j++ < (pf->field - pf->precision))
		pf->result[pf->i++] = ' ';
}
