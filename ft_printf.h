/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:01:01 by eleleux           #+#    #+#             */
/*   Updated: 2023/04/17 15:02:29 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEXALOW "0123456789abcdef"
# define HEXAUP "0123456789ABCDEF"
# define DECIMAL "0123456789"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int		ft_printf(const char *param, ...);
int		ft_putnbr_base_fd(int nbr, char *base, int fd);
int		ft_sizebase_fd(size_t n, char *base, int fd);
size_t	ft_strlen(const char *str);
int		ft_intputchar_fd(char c, int fd);
int		ft_intputstr_fd(char *s, int fd);

#endif
