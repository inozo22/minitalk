/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.c>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:30:56 by nimai             #+#    #+#             */
/*   Updated: 2022/12/14 11:31:05 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dtemp;
	char		*stemp;

	dtemp = (char *)dst;
	stemp = (char *)src;
	if (stemp < dtemp)
	{
		dtemp += len;
		stemp += len;
		while (len--)
			*--dtemp = *--stemp;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
