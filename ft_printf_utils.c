/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>       +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:43:32 by nlouro              #+#    #+#           */
/*   Updated: 2021/10/08 13:45:47 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FT_UINT_MAX	4294967295

int	_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	_putstr(char *s)
{
	size_t	i;

	if (s == 0)
	{
		_putstr("(null)");
		return (6);
	}
	i = 0;
	while (s[i] != '\0')
		i++;
	write(1, s, i);
	return (i);
}

int	_putnbr(int n)
{
	unsigned int	nb;
	int				i;

	nb = n;
	i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		nb = -n;
		i++;
	}
	if (nb >= 10)
	{
		_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		nb = nb + 48;
		write(1, &nb, 1);
		i++;
	}
	return (_nbrlen(n, 10));
}

int	_putunbr(unsigned int n)
{
	unsigned int	len;
	unsigned int	nb;
	char			*base;

	len = 0;
	base = "0123456789";
	if (n < 0)
		n = FT_UINT_MAX + n;
	nb = n;
	if (n >= 10)
	{
		_putunbr(n / 10);
		n = n % 10;
	}
	if (n < 10)
	{
		write(1, &base[n], 1);
		len++;
	}
	return (_nbrlen(nb, 10));
}

int	_putpercent(void)
{
	write(1, "%", 1);
	return (1);
}
