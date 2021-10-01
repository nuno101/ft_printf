/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:33:49 by nlouro            #+#    #+#             */
/*   Updated: 2021/09/10 18:20:35 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = ft_strlen(s1);
	while (ft_strchr(set, *(s1 + i)) && i < j)
		i++;
	while (ft_strchr(set, *(s1 + j)) && j > i)
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
