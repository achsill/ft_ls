/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:44:45 by hlouar            #+#    #+#             */
/*   Updated: 2016/04/23 18:44:46 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ls.h"

void				nbrlinks(char *str, t_env *e)
{
	int				i;

	stat(str, &e->info);
	i = e->info.st_nlink;
	ft_putchar(' ');
	ft_putnbr(i);
	ft_putchar(' ');
}

void				getid(t_env *e)
{
	struct passwd	*pwd;

	pwd = getpwuid(e->info.st_uid);
	if (pwd->pw_name)
	{
		ft_putstr(pwd->pw_name);
		ft_putchar(' ');
	}
	else
		exit(0);
}

void				getgrp(t_env *e)
{
	struct group	*grp;

	grp = getgrgid(e->info.st_gid);
	if (grp->gr_name)
	{
		ft_putstr(grp->gr_name);
		ft_putchar(' ');
	}
	else
		exit(0);
}

void				getoct(char *str, t_env *e)
{
	int				i;
	int				o;
	int				b;

	o = 0;
	b = 0;
	lstat(str, &e->info);
	i = e->info.st_size;
	ft_putnbr(i);
	ft_putchar(' ');
}

void				gettime(char *str, t_env *e)
{
	char			*stime;
	char			*vtime;
	int				i;
	int				o;

	o = 0;
	i = 0;
	lstat(str, &e->info);
	stime = ctime(&e->info.st_mtime);
	vtime = (char *)malloc(sizeof(char) * ft_strlen(stime));
	while (stime[i] && i < 16)
	{
		while (i <= 3)
			i++;
		vtime[o] = stime[i];
		o++;
		i++;
	}
	ft_putstr(vtime);
}
