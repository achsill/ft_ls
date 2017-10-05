/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:46:12 by hlouar            #+#    #+#             */
/*   Updated: 2016/04/23 18:46:13 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ls.h"

t_ascii				*sub_subloop_rev(t_liste *ptr, t_ascii *ref_addr)
{
	struct stat		first;
	struct stat		second;
	t_data			tmp;

	lstat(ptr->db.path, &first);
	lstat(ptr->next->db.path, &second);
	if (first.st_mtime == second.st_mtime)
	{
		if (first.st_mtimespec.tv_nsec > second.st_mtimespec.tv_nsec)
		{
			tmp = ptr->db;
			ptr->db = ptr->next->db;
			ptr->next->db = tmp;
			ref_addr->sort_end = 1;
		}
	}
	else if (first.st_mtime > second.st_mtime)
	{
		tmp = ptr->db;
		ptr->db = ptr->next->db;
		ptr->next->db = tmp;
		ref_addr->sort_end = 1;
	}
	return (ref_addr);
}

void				subloop_rev_t(t_ascii *ref_addr, t_liste *ptr)
{
	while (ref_addr->i != ref_addr->nb_node - 1)
	{
		ref_addr = sub_subloop_rev(ptr, ref_addr);
		ptr = ptr->next;
		ref_addr->i++;
	}
}

t_liste				*sort_by_rev_time(t_liste *list)
{
	t_liste			*ptr;
	t_liste			*begin;
	t_ascii			ref;
	int				i;

	i = 0;
	ptr = list;
	begin = list;
	if (list->db.name == NULL)
		exit(0);
	ref.nb_node = count_node(list);
	ref.sort_end = 1;
	ref.i = 0;
	while (ref.sort_end)
	{
		i++;
		ref.sort_end = 0;
		subloop_rev_t(&ref, ptr);
		ptr = begin;
		ref.nb_node--;
		ref.i = 0;
	}
	return (begin);
}

void				rev_subloop(t_ascii *ref_addr, t_liste *ptr)
{
	t_data			tmp;

	while (ref_addr->i != ref_addr->nb_node - 1)
	{
		if (ft_strcmp(ptr->next->db.name, ptr->db.name) > 0)
		{
			tmp = ptr->db;
			ptr->db = ptr->next->db;
			ptr->next->db = tmp;
			ref_addr->sort_end = 1;
		}
		ptr = ptr->next;
		ref_addr->i++;
	}
}

t_liste				*sort_by_rev_ascii(t_liste *list)
{
	t_liste			*ptr;
	t_liste			*begin;
	t_ascii			ref;
	int				i;

	i = 0;
	ptr = list;
	begin = list;
	if (list->db.name == NULL)
		exit(0);
	ref.nb_node = count_node(list);
	ref.sort_end = 1;
	ref.i = 0;
	while (ref.sort_end)
	{
		i++;
		ref.sort_end = 0;
		rev_subloop(&ref, ptr);
		ptr = begin;
		ref.nb_node--;
		ref.i = 0;
	}
	return (begin);
}
