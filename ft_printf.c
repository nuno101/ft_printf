/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>       +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:43:32 by nlouro              #+#    #+#           */
/*   Updated: 2021/10/08 14:03:07 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * printf partial re-implementation:
 * %c print a single character.
 * %s print a string of characters.
 * %p The void * pointer argument is printed in hexadecimal. 
 * %d print a decimal (base 10) number.
 * %i print an integer in base 10.
 * %u print an unsigned decimal (base 10) number.
 * %x print a number in hexadecimal (base 16), with lowercase.
 * %X print a number in hexadecimal (base 16), with uppercase. 
 * %% print a percent sign.
 */

static	int	_print_arg(const char *fmt, va_list *ap, int i)
{
	int		len;

	len = 0;
	if (fmt[i] == 'c')
		len = _putchar(va_arg(*ap, int));
	else if (fmt[i] == 's')
		len = _putstr(va_arg(*ap, char *));
	else if (fmt[i] == 'p')
	{
		write(1, "0x", 2);
		len = 2 + _putlnbrhex((long) va_arg(*ap, void *), "0123456789abcdef");
	}
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		len = _putnbr(va_arg(*ap, int));
	else if (fmt[i] == 'u')
		len = _putunbr(va_arg(*ap, unsigned int));
	else if (fmt[i] == 'x')
		len = _putnbrhex(va_arg(*ap, int), "0123456789abcdef");
	else if (fmt[i] == 'X')
		len = _putnbrhex(va_arg(*ap, int), "0123456789ABCDEF");
	else if (fmt[i] == '%')
		len = _putpercent();
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		len;

	if (fmt == 0)
		return (0);
	i = 0;
	len = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			while (fmt[i] >= '0' && fmt[i] <= '9')
				i++;
			len += _print_arg(fmt, &ap, i);
		}
		else
			len += _putchar(fmt[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

int	_nbrlen(long nb, int base)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

int	_putnbrhex(unsigned int n, char *base)
{
	unsigned int	nb;
	unsigned int	i;

	nb = n;
	i = 0;
	if (n >= 16)
	{
		_putnbrhex(n / 16, base);
		n = n % 16;
	}
	if (n < 16)
	{
		write(1, &base[n], 1);
		i++;
	}
	return (_nbrlen(nb, 16));
}

int	_putlnbrhex(unsigned long n, char *base)
{
	unsigned int	i;

	i = 0;
	if (n >= 16)
	{
		i = _putlnbrhex(n / 16, base);
		n = n % 16;
	}
	if (n < 16)
	{
		write(1, &base[n], 1);
		i++;
	}
	return (i);
}
