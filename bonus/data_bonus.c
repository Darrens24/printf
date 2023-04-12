/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:46:22 by eleleux           #+#    #+#             */
/*   Updated: 2023/04/12 15:53:17 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void    initialize_variables(t_printf *pf)
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
}

void    get_flags(t_printf *pf, int i)
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
        else if (pf->string[i] == '.' && ft_isdigit(pf->string[i + 1]))
        {
            pf->dot++;
            pf->precision = ft_atoi(pf->string + i + 1);
            i = go_to_next_flag(pf, i);
        }
        else if (pf->string[i] == '0')
            pf->zero++;
        else if (pf->string[i] == '+')
            pf->plus++;
        else if (pf->string[i] == '#')
            pf->hashtag++;
        i++;
    }
}

void    arg_is_number(t_printf *pf)
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
   }
   else if (pf->conversion == 'X' || pf->conversion == 'x'
           || pf->conversion == 'u')
   {
       pf->u_arg = va_arg(pf->ap, unsigned int); 
       //printf("arg is %u\n", pf->u_arg);
       if (pf->conversion == 'u')
           pf->arg_len = u_nb_len(pf->u_arg);
       else
           pf->arg_len = hexa_len(pf->u_arg, HEXALOW);
     //  printf("arglen is %d\n", pf->arg_len);
   }
    
}

void    get_args_and_conv(t_printf *pf, int i)
{
   i = go_to_arg_end(pf, i); 
   pf->conversion = pf->string[i];
   arg_is_number(pf);
   if (pf->conversion == 'c')
   {
       pf->c_arg = va_arg(pf->ap, int);
       pf->arg_len = 1;
   }
   else if (pf->conversion == 's')
   {
       pf->s_arg = va_arg(pf->ap, char *); 
       pf->arg_len = ft_strlen(pf->s_arg);
   }
   else if (pf->conversion != 'd' && pf->conversion != 'u'
           && pf->conversion != 'x' && pf->conversion != 'X'
           && pf->conversion != 'p')
       pf->c_arg = pf->string[i];
}

void    put_string_to_return(t_printf *pf)
{
    pf->result = malloc(sizeof(char) * (pf->field + pf->precision + pf->arg_len + 1)); // A FREE
    put_left_flags(pf);
    put_arg(pf);
    if (pf->minus)
        put_right_flags(pf);
    free(pf->result);
    /*
    if (pf->precision)
    {
        if (pf->arg_len >= pf->precision && pf->arg_len >= pf->field)
            do_stuff_malloc_arglen;
        else if (pf->arg_len >= pf->precision && pf->arg_len < pf->field)
            put_field;
    }
    else if (pf->precision >= pf->field)
        do_stuff_malloc_pre;
    else if (pf->arg_len < pf->precision && pf->arg_len >= pf->field)
        do_stuff;
        */
}

int go_to_next_flag(t_printf *pf, int i)
{
    while (ft_isdigit(pf->string[i + 1]))
        i++;
    return (i);
}

int go_to_arg_end(t_printf *pf, int i)
{
    while (is_flag(pf->string[i]) || ft_isdigit(pf->string[i]))
        i++;
    return (i);
}
