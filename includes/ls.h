/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 19:00:28 by hlouar            #+#    #+#             */
/*   Updated: 2016/04/23 19:00:31 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <pwd.h>
# include <errno.h>
# include <grp.h>
# include <time.h>
# define LMAJ(x) ((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
# define LMIN(x) ((int32_t)((x) & 0xffffff))

typedef struct		s_ascii
{
	int				nb_node;
	int				sort_end;
	int				i;
}					t_ascii;

typedef struct		s_parse
{
	int				type;
	char			*str;
	struct s_parse	*next;
}					t_parse;

typedef struct		s_data
{
	dev_t			r_dev;
	char			*name;
	char			*path;
	int				type;

}					t_data;

typedef struct		s_liste
{
	struct s_data	db;
	struct s_liste	*next;
}					t_liste;

typedef	struct		s_stage
{
	int				lvl;
}					t_stage;

typedef struct		s_option
{
	int				l;
	int				gr;
	int				a;
	int				r;
	int				t;
}					t_option;
typedef struct		s_env
{
	struct stat		info;
	struct dirent	*content;
	DIR				*rep;
	t_liste			*list;
	struct s_option	opt;
	char			*cur_path;
	int				i;
	int				deep;
	int				ifpath;
	int				total;
}					t_env;

t_liste				*sort_by_ascii(t_liste *list);
t_liste				*sort_by_rev_ascii(t_liste *list);
t_liste				*concat(t_liste *ptr, t_liste *end);
t_liste				*sort_by_rev_time(t_liste *list);
t_liste				*sort_by_time(t_liste *list);
t_env				*openner(char **argv, int i, t_env *e);
int					ft_badltr(char *str);
int					checkiftiret(char *str);
int					set_up(t_env *e, char **argv, int i, t_liste *liste);
int					checkifdot(char *str, char c);
int					count_node(t_liste *list);
int					iftimesup6(long long o);
int					max_lenght(t_liste *ptr);
int					sub_check(char *str, int j, t_env *e);
int					ifjustopt(char **av, int ac, int i);
int					check_type(t_env *e);
int					error_check(char **argv, int i, t_env *e);
char				*ft_chmod(char *str, t_env *e);
char				*write_modsticky(char *tmp, char *str, char *mode, int i);
char				*subsub_convert(char *mode, char *str);
char				*convertchmod(char *str);
void				recursive(t_env *e, t_liste *liste);
void				rev_subloop(t_ascii *ref_addr, t_liste *ptr);
void				subloop(t_ascii *ref_addr, t_liste *ptr);
void				check_option(t_env *e, int argc, char **argv);
void				opt_set(t_env *e);
void				list_loader(t_env *e, t_liste *liste);
void				nbrlinks(char *str, t_env *e);
void				getoct(char *str, t_env *e);
void				getid(t_env *e);
void				gettime(char *str, t_env *e);
void				getgrp(t_env *e);
void				afficher_liste(t_liste *liste, t_env *e);
void				stick1(int k, char *mode);
void				stick2(int k, char *mode);
void				stick3(int k, char *mode);
void				devprint(t_liste *liste);

#endif
