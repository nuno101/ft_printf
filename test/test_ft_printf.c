#include <stdio.h>
#include "../libftprintf.h"

int	main()
{
	int n;
	char c;
	//char *str[5];
	char str[] = "test";

	n = 12;
	c = 'c';
	*str = "test";

	printf("  _printing n: %d\n", n);
	ft_printf("ft_printing n: %d\n", n);
	printf("  _printing c: %c\n", c);
	ft_printf("ft_printing c: %c\n", c);
	printf("\n");
	return (0);
	printf("Printing str: %s\n", str);

	return (0);
}
