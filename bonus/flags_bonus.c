/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:30:06 by eleleux           #+#    #+#             */
/*   Updated: 2023/04/12 15:19:43 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"
/*
    - minus(all, surcharge zero)
    - plus (signe, surcharge espace)
    - space(signe)
    - hashtag(x et X), il ne change pas la valeur de la precision mais rentre dans le field
    - precision
    - zero (numbers, ignore en cas de precision)
*/
void    put_left_flags(t_printf *pf)
{
    if (pf->minus)
        minus_left(pf);
    else
        standard_justify(pf);
}

void    standard_justify(t_printf *pf)
{
    int j;

    if (pf->plus != 0 && (pf->conversion == 'd' || pf->conversion == 'i'))
        pf->result[pf->i++] = '+';
    else if (pf->space != 0 && (pf->conversion == 'd' || pf->conversion == 'i'))
    {
        pf->result[pf->i++] = ' ';
        pf->field--;
    }
    else if (pf->hashtag && (pf->conversion == 'x' || pf->conversion == 'X'))
        pf->field -= 2;
    j = 0;
    if (pf->field > pf->precision && pf->precision > pf->arg_len)
    {
        while (j++ < (pf->field - pf->precision))
            pf->result[pf->i++] = ' ';
    }
    else if (pf->field && pf->precision == 0 && pf->zero != 0)
    {
        while (j++ < (pf->field - pf->arg_len))
            pf->result[pf->i++] = '0';
    }
    else if (pf->field && pf->precision == 0)
    {
        while (j++ < (pf->field - pf->arg_len))
            pf->result[pf->i++] = ' ';
    }
    if (pf->hashtag && (pf->conversion == 'x' || pf->conversion == 'X'))
    {
        pf->result[pf->i] = '0';
        pf->result[pf->i + 1] = 'x';
        pf->i += 2;
    }
    j = 0;
    if (pf->precision > pf->arg_len)
    {
        while (j++ < (pf->precision - pf->arg_len))
            pf->result[pf->i++] = '0';
    }
    pf->result[pf->i] = '\0';
    pf->count += iput_str(pf->result);
   // printf("result=%s\n", pf->result);
}

void    minus_left(t_printf *pf)
{
    int j;

    if (pf->plus != 0 && (pf->conversion == 'd' || pf->conversion == 'i'))
        pf->result[pf->i++] = '+';
    else if (pf->space != 0 && (pf->conversion == 'd' || pf->conversion == 'i'))
        pf->result[pf->i++] = ' ';
    else if (pf->hashtag && (pf->conversion == 'x' || pf->conversion == 'X'))
    {
        pf->result[pf->i] = '0';
        pf->result[pf->i + 1] = 'x';
        pf->i += 2;
    }
    j = 0;
    if (pf->precision > pf->arg_len)
    {
        while (j++ < (pf->precision - pf->arg_len))
            pf->result[pf->i++] = '0';
    }
    pf->result[pf->i] = '\0';
    pf->count += iput_str(pf->result);
   // printf("result=%s\n", pf->result);
}

void    put_arg(t_printf *pf)
{
    if (pf->conversion == 'd' || pf->conversion == 'i')
    {
        pf->count += iput_nbr(pf->i_arg);
    }
    else if (pf->conversion == 'x')
        pf->count += iput_hexa_base(pf->u_arg, HEXALOW);
    else if (pf->conversion == 'X')
        pf->count += iput_hexa_base(pf->u_arg, HEXAUP);
    else if (pf->conversion == 'u')
        pf->count += iput_hexa_base(pf->u_arg, DECIMAL);
    else if (pf->conversion == 'p')
    {
        pf->count += iput_str("0x");
        pf->count += iput_hexa_base((size_t)pf->p_arg, HEXALOW);
    }
    else if (pf->conversion == 'c')
        pf->count += iput_char(pf->c_arg);
    else if (pf->conversion == 's')
        pf->count += iput_str(pf->s_arg);
    else
        pf->count += iput_char(pf->c_arg);
}

void    put_right_flags(t_printf *pf)
{
    int i;

    i = pf->arg_len + ft_strlen(pf->result);
    printf("arglen is %d\n", pf->arg_len);
    printf("i for right flags is %d\n", i);
    //printf("result len is %d\n", i);
    //printf("field is %d\n", pf->field);
    while (i < pf->field)
    {
        pf->count += iput_char(' ');
        i++;
    }
}



/*
- on se fie a count pour savoir ce qu'on a deja print, verifier l'absence de conflits avec des 0 en cas de precision.
*/











