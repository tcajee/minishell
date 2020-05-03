/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 16:13:36 by tcajee            #+#    #+#             */
/*   Updated: 2020/04/27 16:14:52 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

char    **arr_dup(char **array)
{
    int     i;
    int     len;
    char    **new_array;

    new_array = NULL;
    if (array)
    {
        i = -1;
        len = arr_len(array);

        if (!(new_array = (char**)malloc(sizeof(char *) * (len + 1))))
            return (NULL);
        while (++i < len)
            new_array[i] = ft_strdup(array[i]);
        new_array[i] = NULL;
        return (new_array);
    }
    return (NULL);
}

int     arr_len(char **array)
{
    int len;

    len = 0;
    while (array && array[len])
        len++;
    return (len);
}

void  arr_del(char **array)
{
    int i;

    i = 0;
    while (array && array[i])
        free(array[i++]);
    (array) ? free(array) : NULL;
    array = NULL;
}
