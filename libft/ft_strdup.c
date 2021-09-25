/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:42:34 by nlouro            #+#    #+#             */
/*   Updated: 2021/09/09 15:00:07 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*buffer;

	len = ft_strlen(s1);
	buffer = malloc(len + 1);
	if (buffer == 0)
		return (NULL);
	i = 0;
	while (*(s1 + i) && i < len)
	{
		*(buffer + i) = *(s1 + i);
		i++;
	}
	*(buffer + i) = '\0';
	return (buffer);
}
