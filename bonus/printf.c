/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:25:25 by eleleux           #+#    #+#             */
/*   Updated: 2023/04/12 13:26:56 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int ft_printf(const char *arg, ...)
{
    t_printf    *pf;
    int         i;
    int         count;

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
            initialize_variables(pf);
            get_flags(pf, i);
            get_args_and_conv(pf, i);
            put_string_to_return(pf);
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


