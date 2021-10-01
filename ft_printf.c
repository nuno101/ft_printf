/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>       +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:43:32 by nlouro              #+#    #+#           */
/*   Updated: 2021/10/01 12:09:27 by nlouro           ###   ########.fr       */
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

static int	_putstr(char *s);
static int	_putchar(char c);
static int	_putnbr(int n);
static int	_putptr(void *ptr);
static int	_putnbrhex(unsigned int n, char *base);

static	int	_print_arg(const char *fmt, va_list *ap, int i)
{
	int		len;

	len = 0;
	if (fmt[i] == 'c')
		len = _putchar(va_arg(*ap, int));
	else if (fmt[i] == 's')
		len = _putstr(va_arg(*ap, char *));
	else if (fmt[i] == 'p')
		len = _putptr(va_arg(*ap, void *));
	else if (fmt[i] == 'd' || fmt[i] == 'i' || fmt[i] == 'u')
		len = _putnbr(va_arg(*ap, int));
	else if (fmt[i] == 'x')
		len = _putnbrhex(va_arg(*ap, int), "0123456789abcdef");
	else if (fmt[i] == 'X')
		len = _putnbrhex(va_arg(*ap, int), "0123456789ABCDEF");
	return (len);
}

//printf("\nDEBUG i + j = %d", i + j);
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
			if (fmt[i] == '%')
			{
				write(1, &fmt[i], 1);
				len++;
			}
			else
			{
				len += _print_arg(fmt, &ap, i);
			}
		}
		else
		{
			write(1, &fmt[i], 1);
			i++;
			len++;
		}
	}
	va_end(ap);
	return (len);
}

static int	_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	_putstr(char *s)
{
	size_t	i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	write(1, s, i);
	return (i);
}

static	int	_putnbr(int n)
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
	return (i);
}

static	int	_putnbrhex(unsigned int n, char *base)
{
	unsigned	int	i;

	i = 0;
	if (n > 16)
	{
		_putnbrhex(n / 16, base);
		n = n % 16;
	}
	if (n < 16)
	{
		write(1, &base[n], 1);
		i++;
	}
	return (i);
}

static	int	_putptr(void *ptr)
{
	void	*p;

	p = (void *) ptr;
	write(1, "0x", 2);
	write(1, &p, 12);
	return (14);
}
