/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:29:57 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 09:43:08 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	*ft_memalloc(size_t size)
{
	void *new;

	if (!(new = (void *)malloc(size * sizeof(char))))
		return (NULL);
	return (ft_memset(new, 0, size));
}
