/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nlouro@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:43:32 by nuno              #+#    #+#             */
/*   Updated: 2021/09/30 12:31:48 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
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

static	int	print_arg(const char *fmt, va_list *ap, int i)
{
	int		d;
	int		len;
	char	c;
    char	*s;

	len = 0;
	switch(fmt[i]) {
		case 's':
			s = va_arg(*ap, char *);
			ft_putstr_fd(s, 1);
			len = 4;
			break;
		case 'd':
			d = va_arg(*ap, int);
			ft_putnbr_fd(d, 1);
			len = 1;
			break;
		case 'c':
			c = va_arg(*ap, int);
			ft_putchar_fd(c, 1);
			len = 1;
			break;
	}

	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		j;
	int		len;

	if (fmt == 0)
		return (0);
	i = 0;
	j = 0;
	va_start(ap, fmt);
	while (fmt[i + j] != '\0')
	{
		//printf("\nDEBUG i + j = %d", i + j);
		if (fmt[i + j] == '%')
		{
			//% character write(1, &fmt[i + j], 1);
			j = j + i + 1;
			i = 0;
			len = print_arg(fmt, &ap, j); 
			//printf("DEBUG j = %d, len = %d\n", j, len);
		    j = j + len;
			//j++;
		} else {
			write(1, &fmt[i + j], 1);
			i++;
		}
	}
	va_end(ap);
	return (0);
}
