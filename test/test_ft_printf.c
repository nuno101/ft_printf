#include <stdio.h>
#include "../libftprintf.h"

int	main()
{
	int n;
	char c;
	//char *str[5];
	char str[] = "test";

	n = 123;
	c = 'c';
	//*str = "test";
	//
	printf("  _printing c: %c123\n", c);
	ft_printf("ft_printing c: %c123\n", c);

	printf("  _printing n: %d123\n", n);
	ft_printf("ft_printing n: %d123\n", n);

	n = 210;
	printf("  _printing n: %d123\n", n);
	ft_printf("ft_printing n: %d123\n", n);

	printf("  _printing c: %c123\n", c);
	ft_printf("ft_printing c: %c123\n", c);

	printf("\n");
	printf("  _printing str: %s123\n", str);
	ft_printf("ftprinting str: %s123\n", str);

	return (0);
}
