/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:50:12 by hlouar            #+#    #+#             */
/*   Updated: 2015/12/09 16:57:06 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count(char const *s, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			i++;
			j++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (j);
}

static char		*add_mot(size_t *i, char const *s, char c)
{
	size_t	size;
	size_t	j;
	char	*mot;

	size = *i;
	j = 0;
	while (s[size] && s[size] != c)
		size++;
	mot = ft_strnew(size - *i);
	if (mot)
	{
		while (*i < size)
		{
			mot[j] = s[*i];
			j++;
			*i += 1;
		}
		return (mot);
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	o;
	size_t	*i;
	size_t	j;

	o = 0;
	i = &o;
	j = 0;
	tab = NULL;
	if (s)
		tab = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (tab)
	{
		while (j < ft_count(s, c))
		{
			while (s[*i] == c)
				*i += 1;
			if (s[*i] != c && s[*i])
				tab[j++] = add_mot(i, s, c);
		}
		tab[j] = 0;
		return (tab);
	}
	return (0);
}
