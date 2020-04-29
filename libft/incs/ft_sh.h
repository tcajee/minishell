/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 12:52:36 by tcajee            #+#    #+#             */
/*   Updated: 2020/04/27 15:32:16 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>

# define IS_SINGLE(a) (a == '\'')
# define IS_DOUBLE(a) (a == '\"')

// Cd
int     check_cd(char *dir);
void    exec_cd(char **argv, char **env);
void    parse_cd(char *path, char **env);

// Setenv
void    exec_putenv(char **env);
void    push_env(char **tab, int *len);
void    add_env(char **tab, char *elem, char *data);
int     replace_env(char **tab, char *elem, char *data);
void    exec_setenv(char *key, char *value, char **envv);

// Unsetenv
int     remove_env(char **tab, char *elem);
void    exec_unsetenv(char *arg, char **env);

// Exec
void    exec_line(char *line, char ***env);
void    exec_exit(char **argv, char **env);

// Echo
char    *ft_quotes(char *str);
void    parse_echo(char *input);
void    check_env_var(char *arg, char **env);
void    exec_echo(char **argv, char *line, char **env);

// Path
int     check_path(char *bin);
int     get_path(char **argv, char **env);
int     exec_path(char *path, char **args, char **env);
int     find_path(char **argv, char **env, char **path);

// Parsing
char    *parse_quotes(char *line);
char    *parse_line(char *line, char **env);
char    *parse_vars(char *temp, char *start, char **envv);

// Char Utils
char    *char_del(char *temp);
char    *strip_newline(char *old);
char    *char_add(char *temp, char add);

// Arr Utils
int     arr_len(char **array);
void    arr_del(char **array);
char    **arr_dup(char **envv);

#endif
