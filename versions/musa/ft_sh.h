/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:17:46 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/09/13 11:17:48 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include "./libft/includes/ft_stdlib.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/stat.h>


/*
*  IS_Variables
*/

# define IS_VAR(a) (a == '$')
# define IS_QOUTE(a) (a == '\'' || a == '\"')

/*
*   COLOR
*/

# define RED    "\033[0;31m"
# define BLUE   "\033[0;34m"
# define GREEN  "\033[0;32m"
# define RESET  "\033[0m"

/*
*   Environment
*/

void	check_env_var(char *arg, char **env);
void	do_env(char **env);

/*
*   minishell Builtin
*/
void 	do_echo(char **arg, char **env);
void	do_exit(char **arg);
void	do_cd(char **arg, char **env);
void	do_setenv(char **arg, char ***env);


/*
*   Minishell Utils
*/
int		ft_strlen_double(char **str);
char	**ft_strcpy_double(char **arr);
void	ft_input(void);


#endif
