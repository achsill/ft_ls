/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reparse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:45:39 by hlouar            #+#    #+#             */
/*   Updated: 2016/04/23 18:51:07 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ls.h"

void			sub_concat(t_liste *tmp, t_liste *end)
{
	while (end->next)
	{
		tmp->next = malloc(sizeof(t_liste));
		tmp->db.name = end->db.name;
		tmp->db.path = end->db.path;
		tmp->db.type = end->db.type;
		tmp = tmp->next;
		end = end->next;
		tmp->next = NULL;
	}
}

t_liste			*concat(t_liste *ptr, t_liste *end)
{
	t_liste		*tmp;
	t_liste		*begin;

	tmp = malloc(sizeof(t_liste));
	begin = tmp;
	tmp->next = NULL;
	while (ptr->next)
	{
		tmp->next = malloc(sizeof(t_liste));
		tmp->db.name = ptr->db.name;
		tmp->db.path = ptr->db.path;
		tmp->db.type = ptr->db.type;
		tmp = tmp->next;
		ptr = ptr->next;
		tmp->next = NULL;
	}
	end = end->next;
	sub_concat(tmp, end);
	return (begin);
}

void			sub_list_loader(t_env *e, t_liste *liste)
{
	liste->db.path = ft_strjoin("/", e->content->d_name);
	liste->db.path = ft_joinfree(e->cur_path, liste->db.path, 2);
	lstat(liste->db.path, &e->info);
	liste->db.r_dev = e->info.st_rdev;
}

void			list_loader(t_env *e, t_liste *begin)
{
	t_liste		*liste;
	int			ret;
	long long	h;
	int			o;

	e->total = 0;
	o = 0;
	h = 0;
	liste = begin;
	while ((e->content = readdir(e->rep)) != NULL)
	{
		sub_list_loader(e, liste);
		h = (long long)e->info.st_blocks;
		o = (int)h;
		if (checkifdot(e->content->d_name, '.') != -1)
			e->total = o + e->total;
		liste->next = malloc(sizeof(t_liste));
		liste->db.name = ft_strdup(e->content->d_name);
		if ((ret = check_type(e)) == 2)
			liste->db.type = 0;
		else if ((ret = check_type(e)) == 1)
			liste->db.type = 1;
		liste = liste->next;
		liste->next = NULL;
	}
}

t_env			*openner(char **argv, int i, t_env *e)
{
	t_liste		*liste;
	int			ret;

	ret = 0;
	e->deep = 0;
	e->i = 0;
	e->list = malloc(sizeof(t_liste));
	liste = e->list;
	if ((ret = set_up(e, argv, i, liste)) == 1)
		return (0);
	list_loader(e, liste);
	if ((e->opt.r == 0) && (e->opt.t == 0))
		liste = sort_by_ascii(liste);
	else if ((e->opt.r == 1) && (e->opt.t == 0))
		liste = sort_by_rev_ascii(liste);
	else if ((e->opt.t == 1) && (e->opt.r == 0))
		liste = sort_by_time(liste);
	else if ((e->opt.t == 1) && (e->opt.r == 1))
		liste = sort_by_rev_time(liste);
	afficher_liste(liste, e);
	closedir(e->rep);
	if (e->opt.gr == 1)
		recursive(e, e->list);
	return (e);
}
