/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:43:52 by hlouar            #+#    #+#             */
/*   Updated: 2016/04/23 18:43:54 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ls.h"

int				checkiftiret(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			return (1);
		else
			return (0);
		i++;
	}
	return (0);
}

void			sub_error_check(char **argv, int i, t_env *e)
{
	if (argv[i + 1] && e->opt.l != 1)
	{
		ft_putendl(argv[i]);
		ft_putchar('\n');
	}
	else
	{
		if (e->opt.l == 1)
		{
			convertchmod(ft_chmod(argv[i], e));
			nbrlinks(argv[i], e);
			getid(e);
			getgrp(e);
			getoct(argv[i], e);
			gettime(argv[i], e);
			ft_putchar(' ');
			ft_putendl(argv[i]);
		}
		else
			ft_putendl(argv[i]);
	}
}

int				error_check(char **argv, int i, t_env *e)
{
	char		*str;

	if (e->rep == NULL)
	{
		if (ft_strcmp(str = strerror(errno), "Not a directory") == 0)
		{
			sub_error_check(argv, i, e);
			return (1);
		}
		else
		{
			ft_putstr("ls: ");
			ft_putstr(argv[i]);
			ft_putstr(": ");
			perror("");
			return (1);
		}
	}
	return (0);
}

int				set_up(t_env *e, char **argv, int i, t_liste *liste)
{
	int			ret;

	(void)liste;
	ret = 0;
	if (i < 1)
	{
		e->cur_path = ".";
		e->rep = opendir(".");
	}
	else
	{
		e->cur_path = argv[i];
		e->rep = opendir(argv[i]);
	}
	if ((ret = error_check(argv, i, e)) == 1)
		return (1);
	return (0);
}
