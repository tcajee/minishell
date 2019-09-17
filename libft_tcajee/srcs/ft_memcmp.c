/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 08:31:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 09:43:09 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s1_h;
	unsigned char *s2_h;

	s1_h = (unsigned char *)s1;
	s2_h = (unsigned char *)s2;
	while (n--)
	{
		if (*s1_h++ != *s2_h++)
			return (*(s1_h - 1) - *(s2_h - 1));
	}
	return (0);
}
