/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:44:37 by hlouar            #+#    #+#             */
/*   Updated: 2016/04/23 18:44:38 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ls.h"

char				*fromintoct(int k)
{
	int				i;
	char			*str;
	int				m;
	char			*dst;

	dst = (char *)malloc(sizeof(char) * 1);
	str = (char *)malloc(sizeof(char) * 6);
	i = k / 8;
	m = k % 8;
	str = ft_itoa(m);
	while (i > 0)
	{
		m = i % 8;
		dst = ft_itoa(m);
		str = ft_strjoin(dst, str);
		i = i / 8;
	}
	str[6] = '\0';
	free(dst);
	return (str);
}

char				*ft_chmod(char *str, t_env *e)
{
	int				i;
	char			*mode;

	stat(str, &e->info);
	i = e->info.st_mode;
	mode = fromintoct(i);
	return (mode);
}

char				*write_mod(char *tmp, char *str, char *mode, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] == '7')
			tmp = "rwx";
		else if (str[i] == '6')
			tmp = "rw-";
		else if (str[i] == '5')
			tmp = "r-x";
		else if (str[i] == '4')
			tmp = "r--";
		else if (str[i] == '3')
			tmp = "-wx";
		else if (str[i] == '2')
			tmp = "-w-";
		else if (str[i] == '1')
			tmp = "--x";
		else if (str[i] == '0')
			tmp = "---";
		mode = ft_strjoin(mode, tmp);
		i++;
	}
	return (mode);
}

char				*sub_convertchmod(char *mode, char *str, char *tmp, int i)
{
	int				length;
	int				k;

	k = 0;
	length = ft_strlen(str);
	if (length == 5)
	{
		if (str[1] != '0')
			k = 1;
		mode = subsub_convert(mode, str);
		i = 2;
	}
	else if (length == 6)
	{
		if (str[2] != '0')
			k = 1;
		mode = "-";
		i = 3;
	}
	if (k != 1)
		mode = write_mod(tmp, str, mode, i);
	else
		mode = write_modsticky(tmp, str, mode, i);
	return (mode);
}

char				*convertchmod(char *str)
{
	char			*mode;
	char			*tmp;
	int				i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * 3);
	mode = (char *)malloc(sizeof(char) * 10);
	mode = sub_convertchmod(mode, str, tmp, i);
	ft_putstr(mode);
	ft_putchar(' ');
	return (mode);
}
