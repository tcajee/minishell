/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/11 16:35:47 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int		ft_ls_print(int *flags, t_dir *dir)
{
	t_info	*l;

	l = (*flags & F_R) ? dir->last : dir->list;
	while (l && l->name && dir->cool)
	{
		if (!(*flags & F_A) && l->name[0] == '.')
			if (!(*flags & F_REG))
			{
				l = (*flags & F_R) ? l->prev : l->next;
				continue;
			}
		if (*flags & F_1)
			ft_print_def(flags, l);
		else if (*flags & F_L)
			ft_print_lst(flags, dir, l);
		l = (*flags & F_R) ? l->prev : l->next;
		F_SET(*flags, F_0, F_REG);
	}
	return (1);
}

void	ft_ls_file(int *flags, char **argv)
{
	t_dir	*dir;
	t_info	*list;

	dir = ft_dir_new(*(argv + 1));
	list = dir->list;
	while (*++argv)
	{
		if (ft_ls_check(*argv) != 1 && ft_ls_check(*argv) != 4)
			continue;
		if (!list)
			list = ft_dir_add(dir->last);
		dir->last = list;
		list->name = ft_strdup(*argv);
		lstat(list->name, &list->s_stat);
		(*flags & F_L) ? ft_dir_form(flags, dir) : NULL;
		list = list->next;
	}
	if (!(*flags & F_F))
		ft_sorts(flags, dir);
	ft_ls_print(flags, dir);
	ft_sort_clean(dir);
}

char	*ft_ls_path(char *path, char *d_name)
{
	char	lpath[PATH_MAX];
	int		i;
	int		len;
	char	*temp;

	if (ft_ls_check(path) == 3)
	{
		readlink(path, ft_memset(lpath, 0, PATH_MAX), PATH_MAX);
		path = lpath;
	}
	i = 0;
	len = ft_strlen(path) + ft_strlen(d_name);
	if (!(temp = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	while (*path)
		temp[i++] = *path++;
	if (temp[i - 1] == '/')
		temp[i] = '/';
	else
		temp[i++] = '/';
	while (*d_name)
		temp[i++] = *d_name++;
	temp[i] = '\0';
	return (temp);
}

int		ft_ls_check(char *path)
{
	t_stat	s_stat;

	if (lstat(path, &s_stat) < 0)
		return (0);
	if ((s_stat.st_mode & S_IFMT) == S_IFREG)
		return (1);
	if ((s_stat.st_mode & S_IFMT) == S_IFDIR)
	{
		return ((!(s_stat.st_mode & S_IRGRP) || !(s_stat.st_mode & S_IROTH)) ?
			5 : 2);
	}
	if ((s_stat.st_mode & S_IFMT) == S_IFLNK)
		return (3);
	if ((s_stat.st_mode & S_IFMT) == S_IFCHR)
		return (4);
	return (11);
}

int		main(int argc, char **argv)
{
	char	path[PATH_MAX];
	int		flags;
	int		i;

	if ((argc - (i = ft_flags(&flags, argv)) > 1))
		F_SET(flags, F_0, F_M);
	(!argv[i]) ? ft_dirs(&flags, ".") : 0;
	(!argv[i]) ? exit(1) : NULL;
	ft_errors(&flags, argv + i - 1);
	ft_ls_file(&flags, argv + i - 1);
	i = (flags & F_R) ? argc - 1 : argc - i - 1;
	while (argv[i])
	{
		if (ft_ls_check(argv[i]) == 2 || ft_ls_check(argv[i]) == 5)
			ft_dirs(&flags, argv[i]);
		else if (ft_ls_check(argv[i]) == 3)
		{
			readlink(argv[i], ft_memset(path, 0, PATH_MAX), PATH_MAX);
			ft_dirs(&flags, path);
		}
		i = (flags & F_R) ? (i - 1) : (i + 1);
	}
	return (1);
}
