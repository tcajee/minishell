/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:36:21 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/19 11:01:30 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdio.h>
# include <stdarg.h>
# include <dirent.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/xattr.h>
# include <sys/ioctl.h>
# include <sys/acl.h>
# include <uuid/uuid.h>
# include <limits.h>

# define E_FLAGS	-1
# define E_DIRS		-2
# define E_PRINTS	-4
# define E_FILES	-8

# define B_IS(x , y) (x & y) ? 1 : 0
# define B_0(x , y) (x = x & ~y)
# define B_1(x , z) (x = x | z)

# define IS_DOT(x) (x[0] == '.' && x[1] == '\0') ? 1 : 0
# define IS_DDOT(x) (x[0] == '.' && x[1] == '.' && x[2] == '\0') ? 1 : 0

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;
typedef struct winsize	t_wins;

typedef struct			s_info
{
	int					total;
	char				*root;
	char				*path;
	char				*name;
	t_stat				s_stat;
}						t_info;

typedef struct			s_terms
{
	size_t				w_row;
	size_t				w_col;
}						t_terms;

typedef struct			s_format
{
	size_t				f_perm;
	size_t				f_link;
	size_t				f_user;
	size_t				f_group;
	size_t				f_size;
	size_t				f_time;
	size_t				f_name;
	char				*line[7];
}						t_format;

typedef enum			e_flags
{
	F_1 = 1,
	F_l = 2,
	F_g = 4,
	F_t = 8,
	F_u = 16,
	F_r = 32,
	F_f = 64,
	F_a = 128,
	F_M = 4096,
	F_G = 8192,
	F_d = 16384,
	F_R = 32768,
}						t_flags;

int						ft_print_f(char *format, ...);

int						ft_flags(t_flags *flags, char **argv);
int						ft_flag_check(t_flags *flags, char flag);
int						ft_lflag_check(t_flags *flags, char *option);
int						ft_flag_set(t_flags *flags, int flagc, ...);
void					ft_flag_print(t_flags *flags);

int						ft_dirs(t_flags *flags, char *argv);
int						ft_dir_info(char *path, t_info dirs[]);
char					*ft_dir_path(char *path, char *d_name);
int						ft_dir_check(char *path);

int						ft_sorts(int argc, char **argv);
int						ft_sort_lex(int argc, char **argv);
int						ft_sort_rev(int argc, char **argv);
int						ft_sort_mtime(int argc, char **argv);
int						ft_sort_atime(int argc, char **argv);

int						ft_prints(t_flags *flags, t_info dirs[]);
int						ft_print_def(t_flags *flags, t_info dir);
int						ft_print_lst(t_flags *flags, t_info dir);
void					ft_print_perm(t_stat *s_stat);

void					ft_print_time(t_stat s_stat, t_flags *flags);
void					print_time_str(time_t secs);

int						ft_errors(int code, char *error);
int						ft_error_flag(char *arg);
int						ft_error_print(char *arg);
int						ft_error_dir(char *arg);
int						ft_error_file(char *arg);

int						ft_cleans(int argc, char **argv);
#endif
