/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:09:39 by nlouro            #+#    #+#             */
/*   Updated: 2021/09/10 16:11:00 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	int		s1_len;
	int		s2_len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	buffer = (char *) malloc(s1_len + s2_len + 1);
	if (!buffer)
		return (NULL);
	i = -1;
	while (i++ < s1_len)
		*(buffer + i) = *(s1 + i);
	i = 0;
	while (i < s2_len)
	{
		*(buffer + s1_len + i) = *(s2 + i);
		i++;
	}
	*(buffer + s1_len + i) = '\0';
	return (buffer);
}
