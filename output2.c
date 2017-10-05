/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:45:19 by hlouar            #+#    #+#             */
/*   Updated: 2016/04/23 18:45:20 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ls.h"

int				iftimesup6(long long o)
{
	long long	i;

	i = (int)time(0);
	printf("%lld\n", o);
	if (o > i)
	{
		return (1);
	}
	else if (o <= i)
	{
		return (0);
	}
	return (0);
}

int				max_lenght(t_liste *ptr)
{
	int			cur_length;
	int			max_lenght;

	cur_length = 0;
	max_lenght = 0;
	while (ptr->next)
	{
		cur_length = ft_strlen(ptr->db.name);
		if (cur_length > max_lenght)
			max_lenght = cur_length;
		ptr = ptr->next;
	}
	return (max_lenght);
}
