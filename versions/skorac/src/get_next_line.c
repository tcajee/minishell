/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorac <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 08:38:37 by skorac            #+#    #+#             */
/*   Updated: 2018/09/24 08:47:26 by skorac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


static char		*readed(const int fd, char *buff, int *ret)
{
	char			*tmp2;
	static char		temp[BUFF_SIZE];

	if (BUFF_SIZE < 0)
		return (NULL);
	*ret = read(fd, temp, BUFF_SIZE);
	temp[*ret] = '\0';
	tmp2 = buff;
	if (!(buff = ft_strjoin(buff, temp)))
		return (NULL);
	ft_memdel((void*)&tmp2);
	return (buff);
}

static int		ended(char **line, char **buff)
{
	char	*copy;

	copy = ft_strdup(*buff);
	if (!(*line = copy))
		return (-1);
	ft_memset(*buff, 0, ft_strlen(copy));
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			*str;
	static char		*buffed = "";

	ret = 1;
	if (fd < 0 || !line || BUFF_SIZE < 0 ||
			(*buffed == '\0' && (!(buffed = ft_strnew(0)))))
		return (-1);
	while (ret > 0)
	{
		if ((str = ft_strchr(buffed, '\n')))
		{
			*str = '\0';
			if (!(*line = ft_strdup(buffed)))
				return (-1);
			ft_memmove(buffed, str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
		if (!(buffed = readed(fd, buffed, &ret)))
			return (-1);
	}
	ft_memdel((void *)&str);
	if (ret == 0 && ft_strlen(buffed))
		ret = ended(&(*line), &(buffed));
	return (ret);
}
