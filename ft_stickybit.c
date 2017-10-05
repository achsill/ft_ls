/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stickybit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:44:23 by hlouar            #+#    #+#             */
/*   Updated: 2016/04/23 18:44:24 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ls.h"

char		*print_right(char *tmp, char *mode, int i, char *str)
{
	while (str[i] != '\0')
	{
		if (str[i] == '7')
			tmp = "rws";
		else if (str[i] == '6')
			tmp = "rwS";
		else if (str[i] == '5')
			tmp = "r-s";
		else if (str[i] == '4')
			tmp = "r-S";
		else if (str[i] == '3')
			tmp = "-ws";
		else if (str[i] == '2')
			tmp = "-wS";
		else if (str[i] == '1')
			tmp = "--s";
		else if (str[i] == '0')
			tmp = "---";
		mode = ft_strjoin(mode, tmp);
		i++;
	}
	return (mode);
}

char		*write_modsticky(char *tmp, char *str, char *mode, int i)
{
	int		length;
	char	k;

	length = ft_strlen(str);
	if (length == 5)
		i = 1;
	else if (length == 6)
		i = 2;
	k = str[i];
	i++;
	mode = print_right(tmp, mode, i, str);
	stick1(k, mode);
	stick2(k, mode);
	stick3(k, mode);
	return (mode);
}

void		stick1(int k, char *mode)
{
	if (k == '7')
		mode[9] = mode[9] + 1;
	if (k == '6')
	{
		if (mode[9] >= 'a' && mode[9] <= 'z')
			mode[9] = mode[9] + 5;
		else
			mode[9] = '-';
	}
	if (k == '5')
	{
		if (mode[6] == 's')
			mode[6] = 'x';
		else
			mode[6] = '-';
		mode[9] = mode[9] + 1;
	}
}

void		stick2(int k, char *mode)
{
	if (k == '3')
	{
		if (mode[3] == 'S')
			mode[3] = '-';
		else if (mode[3] == 's')
			mode[3] = mode[3] + 5;
		mode[9] = mode[9] + 1;
	}
	if (k == '2')
	{
		if (mode[3] == 's')
			mode[3] = mode[3] + 5;
		else if (mode[3] == 'S')
			mode[3] = '-';
		if (mode[9] == 's')
			mode[9] = mode[9] + 5;
		else
			mode[9] = '-';
	}
}

void		stick3(int k, char *mode)
{
	if (k == '4')
	{
		if (mode[9] >= 'a' && mode[9] <= 'z')
			mode[9] = mode[9] + 5;
		if (mode[9] == 'S')
			mode[9] = '-';
		if (mode[6] == 's')
			mode[6] = 'x';
		else
			mode[6] = '-';
	}
	if (k == '1')
	{
		if (mode[3] == 's')
			mode[3] = mode[3] + 5;
		else
			mode[3] = '-';
		if (mode[6] == 's')
			mode[6] = mode[6] + 5;
		mode[9] = mode[9] + 1;
	}
}
