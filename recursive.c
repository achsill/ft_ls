/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:45:30 by hlouar            #+#    #+#             */
/*   Updated: 2016/04/23 18:45:31 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ls.h"

t_liste			*go_for_direct(t_liste *liste, t_env *e)
{
	if (e->opt.a == 1)
	{
		while ((liste->db.type != 1 && liste->next) ||
			(ft_strcmp(liste->db.name, ".") == 0 && liste->next) ||
			(ft_strcmp(liste->db.name, "..") == 0 && liste->next))
		{
			liste = liste->next;
			if (liste->next == NULL)
				exit(0);
		}
	}
	else
	{
		while ((liste->db.type != 1 && liste->next) ||
			(checkifdot(liste->db.name, '.') && liste->next) ||
			(ft_strcmp(liste->db.name, ".") == 0 && liste->next) ||
			(ft_strcmp(liste->db.name, "..") == 0 && liste->next))
		{
			liste = liste->next;
			if (liste->next == NULL)
				exit(0);
		}
	}
	return (liste);
}

void			rights_manag(t_liste *liste, t_env *e)
{
	char		*str;

	if (!(e->rep = opendir(liste->db.path)))
	{
		ft_putendl(liste->db.path);
		if (ft_strcmp(str = strerror(errno), "Permission denied")
			== 0 && liste->next)
			recursive(e, liste->next);
		else if (ft_strcmp(str = strerror(errno), "Bad file descriptor")
			== 0 && liste->next)
			recursive(e, liste->next);
		else if (ft_strcmp(str = strerror(errno), "Not a directory")
			== 0 && liste->next)
			recursive(e, liste->next);
		else if (ft_strcmp(str = strerror(errno), "directory causes a cycle")
			== 0 && liste->next)
			recursive(e, liste->next);
		else
		{
			perror("errno");
			exit(0);
		}
	}
}

t_liste			*sub_recursive(t_env *e, t_liste *ptr)
{
	if ((e->opt.r == 0) && (e->opt.t == 0))
		ptr = sort_by_ascii(ptr);
	else if ((e->opt.r == 1) && (e->opt.t == 0))
		ptr = sort_by_rev_ascii(ptr);
	else if ((e->opt.t == 1) && (e->opt.r == 0))
		ptr = sort_by_time(ptr);
	else if ((e->opt.t == 1) && (e->opt.r == 1))
		ptr = sort_by_rev_time(ptr);
	return (ptr);
}

void			recursive(t_env *e, t_liste *liste)
{
	t_liste		*begin;
	t_liste		*ptr;

	begin = malloc(sizeof(t_liste));
	ptr = begin;
	liste = go_for_direct(liste, e);
	if (!liste->next)
		exit(0);
	if (e->deep == 104800)
		exit_with_message("To long for the stack");
	e->deep++;
	e->cur_path = liste->db.path;
	rights_manag(liste, e);
	list_loader(e, ptr);
	ptr = sub_recursive(e, ptr);
	afficher_liste(ptr, e);
	ft_putchar('\n');
	begin = concat(begin, liste);
	closedir(e->rep);
	recursive(e, begin);
}
