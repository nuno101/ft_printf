/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:47:45 by nlouro            #+#    #+#             */
/*   Updated: 2021/09/23 16:53:58 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!haystack && !needle)
		return (NULL);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (*haystack && len > 0)
	{
		if (*haystack == *needle)
		{
			i = 0;
			while (haystack[i] == needle[i] && haystack[i] != '\0' && len > 0)
			{
				i++;
				len--;
			}
			if (i == (size_t)ft_strlen(needle))
				return ((char *)(haystack));
			len = len + i;
		}
		haystack++;
		len--;
	}
	return (NULL);
}
