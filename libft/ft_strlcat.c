/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 15:45:05 by nlouro            #+#    #+#             */
/*   Updated: 2021/09/15 11:51:34 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dst_len = (size_t) ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (dstsize < dst_len)
		return (src_len + dstsize);
	while ((dst_len + i < dstsize) && *(src + i) != '\0')
	{
		*(dst + dst_len + i) = *(src + i);
		i++;
	}
	if (dst_len < dstsize && dst_len + i == dstsize)
		*(dst + dst_len + i - 1) = '\0';
	else
		*(dst + dst_len + i) = '\0';
	return (dst_len + src_len);
}
