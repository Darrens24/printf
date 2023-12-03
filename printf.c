/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:25:25 by eleleux           #+#    #+#             */
/*   Updated: 2023/06/08 12:10:10 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_string_to_return(t_printf *pf)
{
	pf->result = ft_calloc(pf->field + pf->precision + pf->arg_len
			+ 100, 1);
	put_left_flags(pf);
	put_arg(pf);
	if (pf->minus)
		put_right_flags(pf);
	free(pf->result);
}

int	go_to_next_flag(t_printf *pf, int i)
{
	while (ft_isdigit(pf->string[i + 1]))
		i++;
	return (i);
}

int	go_to_arg_end(t_printf *pf, int i)
{
	while (is_flag(pf->string[i]) || ft_isdigit(pf->string[i]))
		i++;
	return (i);
}

void	norm_printf(t_printf *pf, int i)
{
	initialize_variables(pf);
	get_flags(pf, i);
	get_args_and_conv(pf, i);
	put_string_to_return(pf);
}

int	ft_printf(const char *arg, ...)
{
	t_printf	*pf;
	int			i;
	int			count;

	pf = malloc(sizeof(t_printf));
	va_start(pf->ap, arg);
	pf->string = (char *)arg;
	i = 0;
	pf->count = 0;
	while (pf->string && pf->string[i])
	{
		if (pf->string[i] == '%' && pf->string[i + 1])
		{
			i++;
			norm_printf(pf, i);
			i = go_to_arg_end(pf, i);
		}
		else
			pf->count += iput_char(pf->string[i]);
		i++;
	}
	va_end(pf->ap);
	count = pf->count;
	free(pf);
	return (count);
}
