/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:33:35 by nimai             #+#    #+#             */
/*   Updated: 2023/03/01 15:04:35 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_nbr(char const *str, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[x])
	{
		if (str[x] != c)
			i++;
		while (str[x] != c && str[x])
			x++;
		if (str[x])
			x++;
	}
	return (i);
}

int	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**free_error(char **tab, int i)
{
	while (i > 0)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	len;

	i = 0;
	tab = (char **) malloc(sizeof(char *) * (word_nbr(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		len = word_len(s, c) + 1;
		tab[i] = (char *)malloc(sizeof(char) * len);
		if (!tab[i])
			return (free_error(tab, i));
		ft_strlcpy(tab[i], s, len);
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
