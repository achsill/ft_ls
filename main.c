/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:44:31 by hlouar            #+#    #+#             */
/*   Updated: 2016/04/23 18:44:32 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ls.h"

void			print_dir_name(int i, char **argv, t_env *e)
{
	if (i >= 2 && argv[i])
	{
		lstat(argv[i], &e->info);
		if (S_ISDIR(e->info.st_mode))
		{
			ft_putstr(argv[i]);
			ft_putendl(":");
		}
	}
}

void			sub_main(int argc, char **argv, int i, t_env *e)
{
	int			ret;

	while (i < argc)
	{
		print_dir_name(i, argv, e);
		if ((ret = ifjustopt(argv, argc, i)) == 1)
		{
			openner(argv, 0, e);
			exit(0);
		}
		else
		{
			while (argv[i][0] == '-' && argv[i + 1])
				i++;
			openner(argv, i, e);
		}
		i++;
	}
}

void			sub_main_2(int argc, char **argv, t_env *e, int i)
{
	if (argc == 1)
		openner(argv, i, e);
	else
	{
		i = 1;
		check_option(e, argc, argv);
		sub_main(argc, argv, i, e);
	}
}

int				main(int argc, char **argv)
{
	t_env		e;
	int			i;
	int			j;

	j = 1;
	i = 0;
	if (argc >= 2)
	{
		if (checkiftiret(argv[i + 1]) == 1)
		{
			if (ft_badltr(argv[i + 1]) == 0)
			{
				opt_set(&e);
				return (-1);
			}
		}
	}
	sub_main_2(argc, argv, &e, i);
	return (0);
}
