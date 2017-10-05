/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_dev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:44:11 by hlouar            #+#    #+#             */
/*   Updated: 2016/04/23 18:44:12 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ls.h"

int		ft_cnum(int n)
{
	int		c;

	c = 0;
	if (n <= 9)
		c = 1;
	if (n >= 10)
	{
		while (n > 0)
		{
			n = n / 10;
			c++;
		}
	}
	return (c);
}

void	devprint(t_liste *liste)
{
	int min;
	int max;

	min = ft_cnum(LMIN(liste->db.r_dev));
	max = ft_cnum(LMAJ(liste->db.r_dev));
	while (max++ < 3)
		ft_putchar(' ');
	ft_putnbr(LMAJ(liste->db.r_dev));
	ft_putstr(",");
	ft_putchar(' ');
	while (min++ <= 2)
		ft_putchar(' ');
	ft_putnbr(LMIN(liste->db.r_dev));
	ft_putchar(' ');
}
