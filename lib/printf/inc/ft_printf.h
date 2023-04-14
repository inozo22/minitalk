/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:48:38 by nimai             #+#    #+#             */
/*   Updated: 2023/01/10 15:33:00 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int				ft_printf(char const *str, ...);
size_t			put_char(char c);
int				put_nbr(va_list ap);
unsigned long	put_pointer(va_list ap);
size_t			put_str(char *str);
unsigned long	put_u_nbr(unsigned long nb, unsigned long base, int i);

#endif
