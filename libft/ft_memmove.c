/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:31:27 by nlouro            #+#    #+#             */
/*   Updated: 2021/09/10 10:42:33 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ptr_d;
	char	*ptr_s;

	i = 0;
	ptr_d = (char *)dst;
	ptr_s = (char *)src;
	if (ptr_s < ptr_d)
	{
		while (len > 0)
		{
			len--;
			*(ptr_d + len) = *(ptr_s + len);
		}
	}
	else if (ptr_s > ptr_d)
	{
		while (i < len)
		{
			*(ptr_d + i) = *(ptr_s + i);
			i++;
		}
	}
	return (dst);
}
