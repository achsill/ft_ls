/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:45:51 by hlouar            #+#    #+#             */
/*   Updated: 2016/04/23 18:45:56 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ls.h"

int					check_type(t_env *e)
{
	if (S_ISDIR(e->info.st_mode))
		return (1);
	else if (S_ISREG(e->info.st_mode) || (S_ISLNK(e->info.st_mode)))
		return (2);
	else
		return (0);
}

int					count_node(t_liste *list)
{
	t_liste			*tmp_ptr;
	int				nb_node;

	tmp_ptr = list;
	nb_node = 0;
	while (tmp_ptr->next)
	{
		tmp_ptr = tmp_ptr->next;
		nb_node++;
	}
	return (nb_node);
}

void				subloop(t_ascii *ref_addr, t_liste *ptr)
{
	t_data			tmp;

	while (ref_addr->i != ref_addr->nb_node - 1)
	{
		if (ft_strcmp(ptr->db.name, ptr->next->db.name) > 0)
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

t_liste				*sort_by_ascii(t_liste *list)
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
		subloop(&ref, ptr);
		ptr = begin;
		ref.nb_node--;
		ref.i = 0;
	}
	return (begin);
}
