/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 08:32:16 by skorac            #+#    #+#             */
/*   Updated: 2019/09/17 17:16:33 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
