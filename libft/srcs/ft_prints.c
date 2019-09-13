/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/12 12:06:53 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_print_perms(char *permissions, t_stat *s_stat)
{
	if (s_stat->st_mode & S_IRUSR)
		permissions[1] = 'r';
	if (s_stat->st_mode & S_IWUSR)
		permissions[2] = 'w';
	if (s_stat->st_mode & S_IXUSR)
		permissions[3] = 'x';
	if (s_stat->st_mode & S_IRGRP)
		permissions[4] = 'r';
	if (s_stat->st_mode & S_IWGRP)
		permissions[5] = 'w';
	if (s_stat->st_mode & S_IXGRP)
		permissions[6] = 'x';
	if (s_stat->st_mode & S_IROTH)
		permissions[7] = 'r';
	if (s_stat->st_mode & S_IWOTH)
		permissions[8] = 'w';
	if (s_stat->st_mode & S_IXOTH)
		permissions[9] = 'x';
}

void	ft_print_perm(int *flags, t_info *list)
{
	char	permissions[12];

	ft_memset(permissions, '-', 11);
	if ((list->s_stat.st_mode & S_IFMT) == S_IFDIR)
		permissions[0] = 'd';
	else if ((list->s_stat.st_mode & S_IFMT) == S_IFREG)
		permissions[0] = '-';
	else if ((list->s_stat.st_mode & S_IFMT) == S_IFCHR)
		permissions[0] = 'c';
	else if ((list->s_stat.st_mode & S_IFMT) == S_IFBLK)
		permissions[0] = 'b';
	else if ((list->s_stat.st_mode & S_IFMT) == S_IFLNK)
		permissions[0] = 'l';
	else if ((list->s_stat.st_mode & S_IFMT) == S_IFSOCK)
		permissions[0] = 's';
	else if ((list->s_stat.st_mode & S_IFMT) == S_IFIFO)
		permissions[0] = 'p';
	ft_print_perms(permissions, &list->s_stat);
	permissions[10] = ' ';
	permissions[11] = '\0';
	(*flags & F_I) ? ft_printf_("%l ", list->s_stat.st_ino) : NULL;
	ft_printf_("%s", permissions);
}

void	ft_print_def(int *flags, t_info *list)
{
	char	path[PATH_MAX];

	ft_bzero(path, PATH_MAX);
	if ((list->s_stat.st_mode & S_IFMT) == S_IFLNK && (*flags & F_L))
		readlink(list->path, path, PATH_MAX);
	ft_printf_("%s", list->name);
	if (*flags & F_FF)
	{
		if (ft_ls_check(list->path) == 2)
			ft_printf_("/");
		else if ((list->s_stat.st_mode & S_IFMT) == S_IFLNK)
			(*flags & F_L) ? (ft_printf_("@ -> %s", path)) : ft_printf_("@");
		else if ((list->s_stat.st_mode & S_IFMT) == S_IFIFO)
			ft_printf_("|");
		else if ((list->s_stat.st_mode & S_IFMT) == S_IFSOCK)
			ft_printf_("=");
		else if (list->s_stat.st_mode & S_IXUSR)
			ft_printf_("*");
	}
	else if ((list->s_stat.st_mode & S_IFMT) == S_IFLNK && (*flags & F_L))
		ft_printf_(" -> %s", path);
	ft_printf_("\n");
}

void	ft_print_lst(int *flags, t_dir *dir, t_info *l)
{
	t_passwd	*s_pwd;
	t_group		*s_grp;

	ft_print_perm(flags, l);
	ft_printf_("%.%x ", dir->s_form.link_len, l->s_stat.st_nlink);
	if (!(*flags & F_O))
	{
		if ((s_pwd = getpwuid(l->s_stat.st_uid)) != NULL)
			ft_printf_("%.%s  ", dir->s_form.usr_len, s_pwd->pw_name);
		else
			ft_printf_("%.%d  ", dir->s_form.usr_len, l->s_stat.st_uid);
	}
	if (!(*flags & F_G))
	{
		if ((s_grp = getgrgid(l->s_stat.st_gid)) != NULL)
			ft_printf_("%.%s  ", dir->s_form.grp_len, s_grp->gr_name);
		else
			ft_printf_("%.%d  ", dir->s_form.grp_len, l->s_stat.st_gid);
	}
	ft_printf_("%.%d", dir->s_form.size_len, l->s_stat.st_size);
	(*flags & F_U) ? (ft_printf_("%s ", l->t =
	ft_strsub(ctime(&l->s_stat.st_atime), 3, 13))) :
	ft_printf_("%s ", l->t = ft_strsub(ctime(&l->s_stat.st_mtime), 3, 13));
	ft_print_def(flags, l);
	free(l->t);
}

int		ft_prints(int *flags, t_dir *dir)
{
	t_info	*list;

	list = (*flags & F_R) ? dir->last : dir->list;
	if ((*flags & F_M))
		((*flags & F_REG)) ? ft_printf_("\n%s:\n", dir->root) :
			ft_printf_("%s:\n", dir->root);
	else if (*flags & F_RR)
		(*flags & F_P) ? ft_printf_("\n%s:\n", dir->root) :
			ft_printf_("%s:\n", dir->root);
	if (*flags & F_L && dir->cool && ((*flags & F_R) ? list->prev : list->next))
		ft_printf_("%s %d\n", "total", dir->total);
	F_SET(*flags, F_0, F_P);
	while (list && list->name && dir->cool)
	{
		if (!(*flags & F_A) && list->name[0] == '.')
		{
			list = (*flags & F_R) ? list->prev : list->next;
			continue;
		}
		(*flags & F_1) ? ft_print_def(flags, list) : 0;
		(*flags & F_L) ? ft_print_lst(flags, dir, list) : 0;
		list = (*flags & F_R) ? list->prev : list->next;
	}
	return (1);
}
