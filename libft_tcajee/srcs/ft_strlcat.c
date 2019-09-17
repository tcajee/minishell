/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 09:16:53 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 09:43:10 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	catlen;

	catlen = 0;
	i = -1;
	dstlen = ft_strlen(dst);
	catlen = dstlen;
	if (dstsize < dstlen)
		catlen = dstsize;
	catlen += ft_strlen(src);
	while (src[++i] && dstlen + i < dstsize - 1 && dstsize > 0)
		dst[dstlen + i] = src[i];
	dst[dstlen + i] = '\0';
	return (catlen);
}
