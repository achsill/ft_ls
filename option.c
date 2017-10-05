/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:45:00 by hlouar            #+#    #+#             */
/*   Updated: 2016/04/23 18:45:01 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ls.h"

int				checkifdot(char *str, char c)
{
	int			i;

	i = 0;
	if (str)
	{
		if (str[i] == c)
			return (-1);
		return (0);
	}
	return (0);
}

void			opt_set(t_env *e)
{
	e->opt.l = 0;
	e->opt.gr = 0;
	e->opt.a = 0;
	e->opt.r = 0;
	e->opt.t = 0;
	e->ifpath = 0;
}

int				sub_check(char *str, int j, t_env *e)
{
	if (str[j] == 'l')
		e->opt.l = 1;
	if (str[j] == 'R')
		e->opt.gr = 1;
	if (str[j] == 'a')
		e->opt.a = 1;
	if (str[j] == 'r')
		e->opt.r = 1;
	if (str[j] == 't')
		e->opt.t = 1;
	j++;
	return (j);
}

void			check_option(t_env *e, int argc, char **argv)
{
	char		*str;
	int			i;
	int			j;

	i = 1;
	j = 0;
	while ((i < argc) && (argv[i][0] == '-'))
	{
		j = 1;
		str = argv[i];
		while (str[j])
			j = sub_check(str, j, e);
		i++;
	}
	if (argv[1][0] != '-')
		opt_set(e);
}

int				ifjustopt(char **av, int ac, int i)
{
	int			o;

	o = 0;
	while (i < ac)
	{
		if (av[i][0] == '-')
			o++;
		i++;
	}
	if (o > 0 && i == o + 1)
		return (1);
	return (0);
}
