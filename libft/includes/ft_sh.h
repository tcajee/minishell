/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:17:46 by mbaloyi           #+#    #+#             */
/*   Updated: 2019/09/17 17:55:33 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/stat.h>


# define IS_VAR(a) (a == '$')
# define IS_QOUTE(a) (a == '\'' || a == '\"')

# define RED    "\033[0;31m"
# define BLUE   "\033[0;34m"
# define GREEN  "\033[0;32m"
# define RESET  "\033[0m"

void	check_env_var(char *arg, char **env);
void	do_env(char **env);
void 	do_echo(char **arg, char **env);
void	do_exit(char **arg);
void	do_cd(char **arg, char **env);
void	do_setenv(char **arg, char ***env);
int		ft_strlen_double(char **str);
char	**ft_strcpy_double(char **arr);
void	ft_input(void);

int     exec_path(char *path, char **args, char **env);
int     check_path(char *bin, char **path);
int     find_path(char **argv, char **env, char **path);
int     get_path(char **argv, char **env);

// skorac
int		ft_tablen(char **tab);
char	**ft_tabdup(char **tab);
void	ft_tabfree(char **tab);
void	mini_echo(char **argv);
void	ft_putenv(char **env);
void	ft_setenv(char **env, char *name, char *data);
int		ft_tabsearch(char **tab, char *elem);
char	**ft_strqotsplit(const char *str);
void	ft_pushback(char **tab, int *len);
void	ft_unsetenv(char **env, char *arg);
char    *ft_newpath(char **tab);
char    *getvalue(char *var, char **env);
char    *replace_path(char *path, char **env);


#endif
