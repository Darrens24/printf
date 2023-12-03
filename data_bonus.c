/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:46:22 by eleleux           #+#    #+#             */
/*   Updated: 2023/06/08 12:08:56 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_variables(t_printf *pf)
{
	pf->i_arg = 0;
	pf->u_arg = 0;
	pf->c_arg = '\0';
	pf->s_arg = NULL;
	pf->arg_len = 0;
	pf->minus = 0;
	pf->space = 0;
	pf->dot = 0;
	pf->zero = 0;
	pf->plus = 0;
	pf->hashtag = 0;
	pf->field = 0;
	pf->precision = 0;
	pf->result = NULL;
	pf->i = 0;
	pf->conversion = 0;
	pf->negative = 0;
	pf->nothing = 0;
	pf->j = 0;
	pf->k = -1;
}

void	dot_flag(t_printf *pf, int *i)
{
	pf->dot++;
	if (ft_isdigit(pf->string[*i + 1]))
	{
		pf->precision = ft_atoi(pf->string + *i + 1);
	}
	if (!ft_isdigit(pf->string[*i + 1]) || (pf->dot && pf->precision == 0))
	{
		pf->nothing++;
	}
	*i = go_to_next_flag(pf, *i);
}

void	get_flags(t_printf *pf, int i)
{
	while (is_flag(pf->string[i]) || ft_isdigit(pf->string[i]))
	{
		if (ft_isdigit(pf->string[i]) && pf->string[i] != '0')
		{
			pf->field = ft_atoi(pf->string + i);
			i = go_to_next_flag(pf, i);
		}
		else if (pf->string[i] == '-')
			pf->minus++;
		else if (pf->string[i] == ' ')
			pf->space++;
		else if (pf->string[i] == '.')
			dot_flag(pf, &i);
		else if (pf->string[i] == '0')
			pf->zero++;
		else if (pf->string[i] == '+')
		{
			pf->plus++;
		}
		else if (pf->string[i] == '#')
			pf->hashtag++;
		i++;
	}
}

void	arg_is_number(t_printf *pf)
{
	if (pf->conversion == 'p')
	{
		pf->p_arg = va_arg(pf->ap, void *);
		pf->arg_len = hexa_len((size_t)pf->p_arg, HEXALOW) + 2;
	}
	else if (pf->conversion == 'd' || pf->conversion == 'i')
	{
		pf->i_arg = va_arg(pf->ap, int);
		pf->arg_len = nb_len(pf->i_arg);
		if (pf->i_arg < 0)
			arg_is_negative(pf);
		else if (pf->plus && pf->i_arg >= 0)
			pf->field--;
	}
	else if (pf->conversion == 'X' || pf->conversion == 'x'
		|| pf->conversion == 'u')
	{
		pf->u_arg = va_arg(pf->ap, unsigned int);
		if (pf->conversion == 'u')
			pf->arg_len = u_nb_len(pf->u_arg);
		else
			pf->arg_len = hexa_len(pf->u_arg, HEXALOW);
	}
}

void	get_args_and_conv(t_printf *pf, int i)
{
	i = go_to_arg_end(pf, i);
	pf->conversion = pf->string[i];
	arg_is_number(pf);
	arg_is_char_or_percent(pf);
	if (pf->conversion == 's')
	{
		pf->s_arg = va_arg(pf->ap, char *);
		if (!pf->s_arg)
		{
			pf->s_arg = "(null)";
			pf->arg_len = 6;
		}
		else
			pf->arg_len = ft_strlen(pf->s_arg);
	}
	else if (pf->conversion != 'd' && pf->conversion != 'u'
		&& pf->conversion != 'x' && pf->conversion != 'X'
		&& pf->conversion != 'p' && pf->conversion != 'c')
		pf->c_arg = pf->string[i];
}
