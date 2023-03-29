/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.c>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:34:54 by nimai             #+#    #+#             */
/*   Updated: 2022/12/14 11:35:06 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*pmem;

	len = ft_strlen(s1) + ft_strlen(s2);
	pmem = malloc(len + 1);
	if (pmem == NULL)
		return (NULL);
	ft_strlcpy(pmem, s1, ft_strlen(s1) + 1);
	ft_strlcat(pmem, s2, len + 1);
	return (pmem);
}
