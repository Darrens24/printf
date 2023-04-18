/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:11:35 by eleleux           #+#    #+#             */
/*   Updated: 2023/04/18 19:14:30 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# define TRUE 1
# define FALSE 0
# define DECIMAL "0123456789"
# define HEXAUP "0123456789ABCDEF"
# define HEXALOW "0123456789abcdef"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

/***        STRUCTURES       ***/

typedef struct  s_printf
{
	va_list         ap;
	char            *string;
	int             i;
	int             i_arg;
	unsigned int    u_arg;
	void            *p_arg;
	char            c_arg;
	char            *s_arg;
	int             arg_len;
	int             minus;
	int             space;
	int             dot;
	int             zero;
	int             plus;
	int				negative;
	int             hashtag;
	int				nothing;
	char            conversion;
	int             field;
	int             precision;
	char            *result;
	int             count;
}               t_printf;

/***        PRINTF       ***/

int                 ft_printf(const char *arg, ...);
int                 go_to_next_flag(t_printf *pf, int i);
int                 go_to_next_arg(t_printf *pf, int i);
int                 go_to_arg_end(t_printf *pf, int i);
void                put_string_to_return(t_printf *pf);

/***        FLAGS       ***/

void                put_left_flags(t_printf *pf);
void                put_arg(t_printf *pf);
void                put_right_flags(t_printf *pf);
void                standard_justify(t_printf *pf);
void                minus_left(t_printf *pf);

/***        DATA       ***/

void                initialize_variables(t_printf *pf);
void                get_flags(t_printf *pf, int i);
void                get_args_and_conv(t_printf *pf, int i);
void                arg_is_number(t_printf *pf);
int					print_untill_precision(t_printf *pf);

/***        PRINTERS       ***/

int                 iput_char(char c);
int                 iput_str(char *str);
int                 iput_nbr(int nb);
int                 iput_unsigned(unsigned int nb);
int                 iput_hexa_base(size_t nb, char *base);

/***        LIBFT       ***/

size_t              ft_strlen(const char *str);
int                 ft_isdigit(int c);
int                 ft_atoi(const char *str);

/***        UTILS       ***/

int                 nb_len(int nb);
int                 u_nb_len(unsigned int nb);
int                 hexa_len(size_t nb, char *base);
int                 is_flag(char c);
int                 is_conversion(char c);

#endif
