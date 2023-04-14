/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:51:27 by nimai             #+#    #+#             */
/*   Updated: 2023/01/12 10:10:56 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	set_u_nbr(char format, va_list ap)
{
	unsigned int	len;

	if (format == 'u')
		len = put_u_nbr(va_arg(ap, unsigned), 10, 0);
	if (format == 'x')
		len = put_u_nbr(va_arg(ap, unsigned), 16, 0);
	if (format == 'X')
		len = put_u_nbr(va_arg(ap, unsigned), 16, 1);
	return (len);
}

size_t	set_print(char format, va_list ap)
{
	char			*str;

	if (format == 'c')
		return (put_char(va_arg(ap, int)));
	if (format == 's')
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			str = "(null)";
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	if (format == 'p')
		return (put_pointer(ap));
	if (format == 'd' || format == 'i')
		return (put_nbr(ap));
	if (format == 'u' || format == 'x' || format == 'X')
		return (set_u_nbr(format, ap));
	return (-1);
}

char	check_format(char c)
{
	char	*list;

	list = "cspiduxX";
	while (*list)
	{
		if (*list == c)
			return (c);
		list++;
	}
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	size_t	len;
	size_t	i;
	char	format;

	len = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			len += put_char(str[i]);
		else
		{
			i++;
			format = check_format(str[i]);
			if (format == 0)
				len += put_char(str[i]);
			else
				len += set_print(format, ap);
		}
		i++;
	}
	va_end(ap);
	return (len);
}
