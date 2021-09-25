/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nlouro@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:43:32 by nuno              #+#    #+#             */
/*   Updated: 2021/09/26 00:36:01 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

int	ft_printf(const char *, ...)
{
	va_list ap, ap2;
	int d;
	char c, *s;

	va_start(ap, fmt);
	va_copy(ap2, ap);
	while (*fmt)
		switch(*fmt++) {
			case 's':                       /* string */
				s = va_arg(ap, char *);
				printf("string %s\n", s);
				break;
			case 'd':                       /* int */
				d = va_arg(ap, int);
				printf("int %d\n", d);
				break;
			case 'c':                       /* char */
				/* Note: char is promoted to int. */
				c = va_arg(ap, int);
				printf("char %c\n", c);
				break;
		}
	va_end(ap);

	/* use ap2 to iterate over the arguments again */

	va_end(ap2);

	return (0);
}
