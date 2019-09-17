/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:34:08 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 09:48:18 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024
# if defined(__APPLE__) && defined(__MACH__)
#  define FT_OPEN_MAX 4864
# elif defined(__linux__)
#  define FT_OPEN_MAX 1024
# elif defined(__unix__)
#  define FT_OPEN_MAX 1024
# endif

int					get_next_line(const int fd, char **line);

#endif
