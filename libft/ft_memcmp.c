/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:41:53 by nlouro            #+#    #+#             */
/*   Updated: 2021/08/26 14:29:06 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*s1c;
	char	*s2c;

	if (n == 0)
		return (0);
	s1c = (char *)s1;
	s2c = (char *)s2;
	while (*s1c == *s2c && n > 1)
	{
		s1c++;
		s2c++;
		n--;
	}
	return ((unsigned char)*s1c - (unsigned char)*s2c);
}
