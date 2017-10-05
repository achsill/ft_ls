/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:44:02 by hlouar            #+#    #+#             */
/*   Updated: 2016/04/23 18:44:04 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ls.h"

int				ft_checkpls(char c, char k)
{
	if (c == k)
		return (1);
	return (0);
}

void			ft_badltr2(char *str, int i)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(str[i]);
	ft_putchar('\n');
	ft_putstr("usage: ls [-Ralrt] ");
	ft_putstr("[file...]");
	ft_putchar('\n');
}

int				ft_badltr(char *str)
{
	int			i;
	int			o;
	int			k;

	o = ft_strlen(str) - 1;
	i = 1;
	k = 0;
	while (str[i])
	{
		if ((ft_checkpls(str[i], 'l') != 0)
				|| (ft_checkpls(str[i], 'a') != 0)
				|| (ft_checkpls(str[i], 'r') != 0)
				|| (ft_checkpls(str[i], 'R') != 0)
				|| (ft_checkpls(str[i], 't') != 0))
			k++;
		else
		{
			ft_badltr2(str, i);
			return (0);
		}
		i++;
	}
	return (1);
}
