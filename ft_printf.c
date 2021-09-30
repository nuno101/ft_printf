/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nlouro@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:43:32 by nuno              #+#    #+#             */
/*   Updated: 2021/09/30 11:19:26 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
 * printf handling cspdiuxX%
%c print a single character.
%s print a string of characters.
%p The void * pointer argument is printed in hexadecimal. 
%d print a decimal (base 10) number.
%i print an integer in base 10.
%u print an unsigned decimal (base 10) number.
%x print a number in hexadecimal (base 16), with lowercase.
%X print a number in hexadecimal (base 16), with uppercase. 
%% print a percent sign.
 */

static	int print_arg(const char *fmt, va_list *ap, int i) 
{
	int		d;
	char	c;
    char	*s;


	printf("\nDEBUG i: %d\n", i);
	switch(fmt[i]) {
		case 's':                       /* string */
			s = va_arg(*ap, char *);
			printf("string %s\n", s);
			break;
		case 'd':                       /* int */
			d = va_arg(*ap, int);
			//printf("int %d\n", d);
			ft_putnbr_fd(d, 1);
			break;
		case 'c':                       /* char */
			/* Note: char is promoted to int. */
			c = va_arg(*ap, int);
			//printf("char %c\n", c);
			ft_putchar_fd(c, 1);
			break;
	}

	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		j;

	if (fmt == 0)
		return (0);
	i = 0;
	j = 0;
	va_start(ap, fmt);
	while (fmt[i + j] != '\0')
	{
		if (fmt[i + j] == '%')
		{
			//% character write(1, &fmt[i + j], 1);
			j = j + i + 1;
			i = 0;
			print_arg(fmt, &ap, j); 
		    j++;
		} else {
			write(1, &fmt[i + j], 1);
			i++;
		}
	}
	va_end(ap);
	return (0);
}
