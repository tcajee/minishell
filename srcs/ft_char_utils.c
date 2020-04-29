/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 12:52:36 by tcajee            #+#    #+#             */
/*   Updated: 2020/04/27 12:52:36 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

char    *strip_newline(char *old)
{
    char    *end;
    char    *new;
    int     i;

    i = 0;
    new = ft_strnew(ft_strlen(old) + 1);
    while (old[i] && old[i] != '\n')
    {
        new [i] = old[i];
        i++;
    }
    new[i] = '\0';
    end = ft_strrchr(new, '\n');
    if (end)
        *end = '\0';
    free(old);
    return (new);
}

char    *char_del(char *old)
{
    int   i;
    char  *new;

    i = -1;
    new = ft_strnew(ft_strlen(old));
    while (old && old[++i])
        new[i] = old[i];
    new[--i] = '\0';
    return (new);
}

char    *char_add(char *old, char add)
{
    int   i;
    char  *new;

    i = -1;
    new = ft_strnew(ft_strlen(old) + 1);
    while (old && old[++i])
        new[i] = old[i];
    new[i++] = add;
    new[i] = '\0';
    return (new);
}
