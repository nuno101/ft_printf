/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>       +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:43:32 by nlouro              #+#    #+#           */
/*   Updated: 2021/10/01 11:01:23 by nlouro           ###   ########.fr       */
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

static int	_putstr_fd(char *s, int fd);
static int	_putchar_fd(char c, int fd);
static int	_putnbr_fd(int n, int fd);
static int	_putptr_fd(void *ptr, int fd);
static int	_putnbrhex_fd(unsigned int n, char *base, int fd);

static	int	_print_arg(const char *fmt, va_list *ap, int i)
{
	int		len;

	len = 0;
	if (fmt[i] == 'c')
		len = _putchar_fd(va_arg(*ap, int), 1);
	else if (fmt[i] == 's')
		len = _putstr_fd(va_arg(*ap, char *), 1);
	else if (fmt[i] == 'p')
		len = _putptr_fd(va_arg(*ap, void *), 1);
	else if (fmt[i] == 'd' || fmt[i] == 'i' || fmt[i] == 'u')
		len = _putnbr_fd(va_arg(*ap, int), 1);
	else if (fmt[i] == 'x')
		len = _putnbrhex_fd(va_arg(*ap, int), "0123456789abcdef", 1);
	else if (fmt[i] == 'X')
		len = _putnbrhex_fd(va_arg(*ap, int), "0123456789ABCDEF", 1);
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
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%' && fmt[i + 1] != '%')
		{
			i++;
			len = _print_arg(fmt, &ap, i);
			i = i + len;
		}
		else
		{
			write(1, &fmt[i], 1);
			i++;
		}
	}
	va_end(ap);
	return (i);
}

static int	_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

static int	_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	write(fd, s, i);
	return (i);
}

static	int	_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	int				i;

	nb = n;
	i = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		nb = -n;
		i++;
	}
	if (nb >= 10)
	{
		_putnbr_fd(nb / 10, fd);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		nb = nb + 48;
		write(fd, &nb, 1);
		i++;
	}
	return (i);
}

static	int	_putnbrhex_fd(unsigned int n, char *base, int fd)
{
	unsigned	int	i;

	i = 0;
	if (n > 16)
	{
		_putnbrhex_fd(n / 16, base, fd);
		n = n % 16;
	}
	if (n < 16)
	{
		write(fd, &base[n], 1);
		i++;
	}
	return (i);
}

static	int	_putptr_fd(void *ptr, int fd)
{
	void	*p;

	p = (void *) ptr;
	write(fd, "0x", 2);
	write(fd, &p, 12);
	return (14);
}
