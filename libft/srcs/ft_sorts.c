/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/12 10:08:21 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_sort_clean(t_dir *dir)
{
	t_info	*list;
	t_info	*next;

	if (dir && dir->root)
	{
		list = dir->list;
		while (list)
		{
			next = list->next;
			if (list->name)
				free(list->name);
			if (list->path)
				free(list->path);
			free(list);
			list = next;
		}
		(dir->root) ? free(dir->root) : 0;
		free(dir);
	}
}

int		ft_sort_comp(int *flags, t_info *a, t_info *b)
{
	if (*flags & F_T)
	{
		if (a->s_stat.st_mtimespec.tv_sec == b->s_stat.st_mtimespec.tv_sec)
		{
			return (a->s_stat.st_mtimespec.tv_nsec
			!= b->s_stat.st_mtimespec.tv_nsec) ?
			(a->s_stat.st_mtimespec.tv_nsec < b->s_stat.st_mtimespec.tv_nsec) :
			(ft_strcmp(a->name, b->name));
		}
		else
			return (a->s_stat.st_mtime < b->s_stat.st_mtime);
	}
	else if ((*flags & F_U) && !(*flags & F_L))
	{
		if (a->s_stat.st_atimespec.tv_sec == b->s_stat.st_atimespec.tv_sec)
		{
			return (a->s_stat.st_atimespec.tv_nsec !=
			b->s_stat.st_atimespec.tv_nsec) ? (a->s_stat.st_atimespec.tv_nsec <
			b->s_stat.st_atimespec.tv_nsec) : (ft_strcmp(a->name, b->name));
		}
		else
			return (a->s_stat.st_atime < b->s_stat.st_atime);
	}
	return (ft_strcmp(a->name, b->name));
}

void	ft_sort_ins(int *flags, t_dir *dir, t_sort *s)
{
	while (s->l_size > 0 || (s->n_size > 0 && s->next))
	{
		if (s->l_size == 0 && s->n_size--)
		{
			s->temp = s->next;
			s->next = s->next->next;
		}
		else if ((s->n_size == 0 || !s->next) && s->l_size--)
		{
			s->temp = s->list;
			s->list = s->list->next;
		}
		else if (ft_sort_comp(flags, s->list, s->next) <= 0 && s->l_size--)
		{
			s->temp = s->list;
			s->list = s->list->next;
		}
		else if (s->n_size-- && !!(s->temp = s->next))
			s->next = s->next->next;
		(s->tail) ? s->tail->next = s->temp : NULL;
		!(s->tail) ? dir->list = s->temp : NULL;
		s->temp->prev = s->tail;
		s->tail = s->temp;
	}
}

void	ft_sort_merge(int *flags, t_dir *dir, t_sort *sort)
{
	int		i;

	while (sort->list)
	{
		i = 0;
		++sort->m_count;
		sort->next = sort->list;
		sort->l_size = 0;
		while (i < sort->i_size)
		{
			sort->l_size++;
			sort->next = sort->next->next;
			if (!sort->next)
				break ;
			i++;
		}
		sort->n_size = sort->i_size;
		ft_sort_ins(flags, dir, sort);
		sort->list = sort->next;
	}
}

void	ft_sorts(int *flags, t_dir *dir)
{
	t_sort	*sort;

	if (!(sort = (t_sort *)malloc(sizeof(t_sort))))
		return ;
	sort->i_size = 1;
	while (sort->i_size)
	{
		sort->list = dir->list;
		dir->list = NULL;
		sort->tail = NULL;
		sort->m_count = 0;
		ft_sort_merge(flags, dir, sort);
		if (sort->tail)
		{
			sort->tail->next = NULL;
			dir->last = sort->tail;
		}
		if (sort->m_count <= 1)
			break ;
		sort->i_size *= 2;
	}
	free(sort);
}
