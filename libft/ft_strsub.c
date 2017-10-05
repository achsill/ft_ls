/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:23:45 by hlouar            #+#    #+#             */
/*   Updated: 2015/12/09 16:53:22 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t				i;
	char				*str;
	unsigned int		j;

	j = 0;
	i = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (start > ft_strlen(s))
		return (NULL);
	if (s == NULL)
		return (NULL);
	if ((str = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	if (len < start)
		return (NULL);
	while (s[i] != '\0' && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
