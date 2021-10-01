/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>       +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:43:32 by nlouro              #+#    #+#           */
/*   Updated: 2021/10/01 17:42:12 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/ft_isdigit.c"

#define UINT_MAX	4294967295
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
static int	_nbrlen(long int nb);
static int	_putnbr(int n);
static int	_putunbr(unsigned int n);
static int	_putptr(void *ptr);
static int	_putnbrhex(unsigned int n, char *base);
static int	_putpercent();

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
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		len = _putnbr(va_arg(*ap, int));
	else if (fmt[i] == 'u')
		len = _putunbr(va_arg(*ap, unsigned int));
	else if (fmt[i] == 'x')
		len = _putnbrhex(va_arg(*ap, int), "0123456789abcdef");
	else if (fmt[i] == 'X')
		len = _putnbrhex(va_arg(*ap, int), "0123456789ABCDEF");
	else if (fmt[i] == '%')
		len = _putpercent(0);
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
			while (ft_isdigit(fmt[i]))
				i++;
			len += _print_arg(fmt, &ap, i);
		}
		else
		{
			write(1, &fmt[i], 1);
			len++;
		}
		i++;
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

static int	_nbrlen(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
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
	return (_nbrlen(n));
}


static	int	_putunbr(unsigned int n)
{
	unsigned int	len;
	unsigned int	nb;
	char 			*base;

	len = 0;
	base = "0123456789";
	if (n < 0)
		n = UINT_MAX + n;
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
	//printf("\nDEBUG nb: %u len: %i", nb, _nbrlen(nb));
	return (_nbrlen(nb));
}

static	int	_putnbrhex(unsigned int n, char *base)
{
	unsigned int	i;

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

static int	_putpercent()
{
	write(1, "%", 1);
	return (1);
}
