/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:45:09 by hlouar            #+#    #+#             */
/*   Updated: 2016/04/23 18:45:10 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ls.h"

void			sub_tabber(int space)
{
	while (space > 0)
	{
		ft_putchar(' ');
		space--;
	}
	ft_putchar('\t');
}

void			tabber(t_env *e, t_liste *liste, int lenght)
{
	int			space;
	char		*buff;
	int			i;
	int			o;

	i = 0;
	buff = (char*)malloc(255);
	lstat(liste->db.path, &e->info);
	space = lenght - ft_strlen(liste->db.name);
	ft_putstr(liste->db.name);
	if ((S_ISLNK(e->info.st_mode) && (i = readlink(liste->db.path, buff, 255)))
		&& (e->opt.l == 1))
	{
		o = 1;
		buff[i] = '\0';
		ft_putstr(" -> ");
		ft_putendl(buff);
	}
	if (e->opt.l == 1 && o != 1)
		ft_putchar('\n');
	else if (e->opt.l != 1)
		sub_tabber(space);
}

void			print_l(t_liste *liste, t_env *e)
{
	convertchmod(ft_chmod(liste->db.path, e));
	nbrlinks(liste->db.path, e);
	getid(e);
	getgrp(e);
	if (liste->db.r_dev != 0)
		devprint(liste);
	else
		getoct(liste->db.path, e);
	gettime(liste->db.path, e);
	ft_putchar(' ');
}

void			sub_output(t_env *e, t_liste *liste, int lenght)
{
	while (liste->next != NULL)
	{
		if (e->opt.a == 1)
		{
			if (e->opt.l == 1)
				print_l(liste, e);
			tabber(e, liste, lenght);
		}
		else
		{
			if (checkifdot(liste->db.name, '.') != -1)
			{
				if (e->opt.l == 1)
					print_l(liste, e);
				tabber(e, liste, lenght);
			}
		}
		liste = liste->next;
		e->ifpath = 1;
	}
}

void			afficher_liste(t_liste *liste, t_env *e)
{
	int			lenght;

	lenght = max_lenght(liste);
	if (e->ifpath == 1)
		ft_putendl(e->cur_path);
	if (e->opt.l == 1)
	{
		ft_putstr("total ");
		ft_putnbr(e->total);
		ft_putchar('\n');
	}
	sub_output(e, liste, lenght);
	if (e->opt.l != 1)
	{
		ft_putchar('\n');
	}
}
