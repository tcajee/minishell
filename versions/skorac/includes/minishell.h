/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 08:32:16 by skorac            #+#    #+#             */
/*   Updated: 2018/09/27 13:55:42 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include "get_next_line.h"

int		get_next_line(const int fd, char **line);
int		ft_tablen(char **tab);
char	**ft_tabdup(char **tab);
void	ft_tabfree(char **tab);
void	mini_echo(char **argv);
void	ft_putenv(char **env);
void	ft_setenv(char **env, char *name, char *data);
int		ft_tabsearch(char **tab, char *elem);
char	**ft_strqotsplit(const char *str);
void	ft_unsetenv(char **tab, char *elem);
void	ft_pushback(char **tab, int *len);
#endif 
