/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:36:21 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/11 15:51:03 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <stdarg.h>
# include <sys/errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/time.h>

# include <sys/xattr.h>
# include <sys/ioctl.h>
# include <sys/acl.h>
# include <uuid/uuid.h>
# include <limits.h>

# define E_FLAGS -1
# define E_DIR -2
# define E_PERMS -4
# define E_PRINTS -8

# define F_SET(FLAGS, F_OFF, F_ON) FLAGS = (FLAGS & ~(F_OFF)) | (F_ON);

# define F_0 0

# define F_1 1
# define F_L 2
# define F_G 4
# define F_T 8
# define F_U 16
# define F_R 32
# define F_F 64
# define F_A 128

# define F_RR 256
# define F_D 512
# define F_FF 1024
# define F_P 8192
# define F_I 65536
# define F_M 131072
# define F_REG 262144
# define F_O 524288

# define F_AA 2048

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct			s_form
{
	size_t				grp_len;
	size_t				usr_len;
	size_t				link_len;
	size_t				size_len;
}						t_form;

typedef struct			s_info
{
	char				*name;
	char				*path;
	char				*t;
	t_stat				s_stat;
	struct s_info		*next;
	struct s_info		*prev;
}						t_info;

typedef struct			s_dir
{
	int					size;
	int					total;
	char				*root;
	int					cool;
	t_stat				s_stat;
	t_form				s_form;
	struct s_info		*list;
	struct s_info		*last;
}						t_dir;

typedef struct			s_sort
{
	t_info				*list;
	t_info				*next;
	t_info				*tail;
	t_info				*temp;
	int					i_size;
	int					l_size;
	int					n_size;
	int					m_count;
}						t_sort;

int						main(int argc, char **argv);
int						ft_ls_check(char *path);
char					*ft_ls_path(char *path, char *d_name);
void					ft_ls_file(int *flags, char **argv);

int						ft_flags(int *flags, char **argv);
int						ft_flag_check(int *flags, char flag);
int						ft_flag_check_(int *flags, char flag);

void					ft_dirs(int *flags, char *path);
t_dir					*ft_dir_new(char *path);
t_info					*ft_dir_add(t_info *list);
int						ft_dir_fill(int *flags, t_dir *dir, char *path);
void					ft_dir_form(int *flags, t_dir *dir);

void					ft_sorts(int *flags, t_dir *dir);
void					ft_sort_merge(int *flags, t_dir *dir, t_sort *sort);
void					ft_sort_ins(int *flags, t_dir *dir, t_sort *sort);
int						ft_sort_comp(int *flags, t_info *list, t_info *unsort);
void					ft_sort_clean(t_dir *dir);

int						ft_prints(int *flags, t_dir *dir);
void					ft_print_def(int *flags, t_info *dir);
void					ft_print_lst(int *flags, t_dir *dir, t_info *list);
void					ft_print_perm(int *flags, t_info *list);
void					ft_print_perms(char *permissions, t_stat *s_stat);

int						ft_errors(int *flags, char **error);
int						ft_error_flag(char *arg);
int						ft_error_perm(int *flags, char *path, t_dir *dir);
int						ft_error_dir(char *arg);
int						ft_error_print(int *flags, t_dir *dir);

#endif
