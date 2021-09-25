/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:10:49 by nlouro            #+#    #+#             */
/*   Updated: 2021/09/15 11:52:57 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{	
	unsigned int	s_len;
	unsigned int	i;
	char			*str;

	if (s == 0)
		return (0);
	i = 0;
	s_len = ft_strlen(s);
	str = (char *) malloc(s_len + 1);
	if (str == 0)
		return (NULL);
	while (i < s_len)
	{
		*(str + i) = f(i, *(s + i));
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
