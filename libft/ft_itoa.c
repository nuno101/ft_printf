/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:43:34 by nlouro            #+#    #+#             */
/*   Updated: 2021/09/23 17:00:17 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	nn;
	int				len;
	char			*buffer;

	nn = n;
	len = ft_nbrlen(n);
	if (n < 0)
	{
		nn = -n;
		len++;
	}
	buffer = (char *) malloc(len + 1);
	if (buffer == 0)
		return (0);
	if (n < 0)
		buffer[0] = '-';
	buffer[len] = '\0';
	if (n == 0)
		buffer[0] = '0';
	while (len-- >= 0 && nn != 0)
	{
		buffer[len] = (nn % 10) + 48;
		nn = nn / 10;
	}
	return (buffer);
}
