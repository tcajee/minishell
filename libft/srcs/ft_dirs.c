/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:23:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/11 15:40:05 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

t_info	*ft_dir_add(t_info *last)
{
	t_info	*new;

	if (!(new = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	new->name = NULL;
	new->path = NULL;
	new->next = NULL;
	last->next = new;
	new->prev = last;
	return (new);
}

t_dir	*ft_dir_new(char *path)
{
	t_dir	*new;

	if (!(new = (t_dir *)malloc(sizeof(t_dir))))
		return (NULL);
	new->root = ft_strdup(path);
	if (!(new->list = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	new->list->name = NULL;
	new->list->path = NULL;
	new->list->next = NULL;
	new->list->prev = NULL;
	new->s_form.grp_len = 0;
	new->cool = 1;
	new->s_form.usr_len = 0;
	new->s_form.size_len = 0;
	new->s_form.link_len = 0;
	new->total = 0;
	new->size = 0;
	new->last = NULL;
	return (new);
}

void	ft_dir_form(int *flags, t_dir *dir)
{
	t_info		*last;
	t_passwd	*s_pwd;
	t_group		*s_grp;

	last = dir->last;
	if (ft_intlen(last->s_stat.st_nlink) > dir->s_form.link_len)
		dir->s_form.link_len = ft_intlen(last->s_stat.st_nlink);
	if (!(*flags & F_O))
	{
		if ((s_pwd = getpwuid(last->s_stat.st_uid)) != NULL
			&& ft_strlen(s_pwd->pw_name) > dir->s_form.usr_len)
			dir->s_form.usr_len = ft_strlen(s_pwd->pw_name);
		else if (ft_intlen(last->s_stat.st_uid) > dir->s_form.usr_len)
			dir->s_form.usr_len = ft_intlen(last->s_stat.st_uid);
	}
	if (!(*flags & F_G))
	{
		if ((s_grp = getgrgid(last->s_stat.st_gid)) != NULL
			&& ft_strlen(s_grp->gr_name) > dir->s_form.grp_len)
			dir->s_form.grp_len = ft_strlen(s_grp->gr_name);
		else if (ft_intlen(last->s_stat.st_gid) > dir->s_form.grp_len)
			dir->s_form.grp_len = ft_intlen(last->s_stat.st_gid);
	}
	if (ft_intlen(last->s_stat.st_size) > dir->s_form.size_len)
		dir->s_form.size_len = ft_intlen(last->s_stat.st_size);
}

int		ft_dir_fill(int *flags, t_dir *dir, char *path)
{
	t_dirent	*s_dir;
	DIR			*dirent;
	t_info		*list;

	if ((dirent = opendir(path)) == NULL)
		return (ft_error_perm(flags, path, dir));
	list = dir->list;
	while ((s_dir = readdir(dirent)) != NULL)
	{
		(!list) ? list = ft_dir_add(dir->last) : 0;
		dir->last = list;
		list->name = ft_strdup(s_dir->d_name);
		list->path = ft_ls_path(path, s_dir->d_name);
		((lstat(list->path, &list->s_stat)) == -1) ? dir->cool = 0 : 0;
		if (*flags & F_A && list->name[0] == '.')
			dir->total += list->s_stat.st_blocks;
		else if (!(list->name[0] == '.'))
			dir->total += list->s_stat.st_blocks;
		(*flags & F_L) ? ft_dir_form(flags, dir) : NULL;
		list = list->next;
	}
	closedir(dirent);
	(!(*flags & F_F)) ? ft_sorts(flags, dir) : NULL;
	ft_prints(flags, dir);
	return (1);
}

void	ft_dirs(int *flags, char *path)
{
	t_dir	*dir;
	t_info	*l;

	if (!(dir = ft_dir_new(path)))
		return ;
	if (!(ft_dir_fill(flags, dir, path)))
		return ;
	if (*flags & F_RR)
	{
		l = (*flags & F_R) ? dir->last : dir->list;
		while (l)
		{
			if (((l->name[0] == '.' && l->name[1] == '\0') || ((
				l->name[0] == '.' && l->name[2] == '\0') && l->name[1]
				== '.')) || (!(*flags & F_A) && l->name[0] == '.'))
			{
				l = (*flags & F_R) ? l->prev : l->next;
				continue;
			}
			else if (ft_ls_check(l->path) == 2 || ft_ls_check(l->path) == 5)
				ft_dirs(flags, l->path);
			l = (*flags & F_R) ? l->prev : l->next;
		}
	}
	ft_sort_clean(dir);
}
