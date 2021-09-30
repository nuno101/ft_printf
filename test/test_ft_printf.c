#include <stdio.h>
#include "../ft_printf.c"

int	main()
{
	int n;
	unsigned int u;
	char c;
	//char *str[5];
	char str[] = "test";

	n = 123;
	u = 123567890;
	c = 'c';

	printf("  _printing c: %c 123\n", c);
	ft_printf("ft_printing c: %c 123\n", c);

	printf("  _printing n: %d 123\n", n);
	ft_printf("ft_printing n: %d 123\n", n);

	printf("  _printing i: %i 123\n", n);
	ft_printf("ft_printing i: %i 123\n", n);

	printf("  _printing u: %i 123\n", u);
	ft_printf("ft_printing u: %i 123\n", u);


	printf("  _printing hex: %x 123\n", u);
	ft_printf("ft_printing hex: %x 123\n", u);


	printf("  _printing HEX: %X 123\n", u);
	ft_printf("ft_printing HEX: %X 123\n", u);

	n = -210;
	printf("  _printing n: %d123\n", n);
	ft_printf("ft_printing n: %d123\n", n);

	printf("  _printing c: %c123\n", c);
	ft_printf("ft_printing c: %c123\n", c);

	printf("  _printing str: %s 123\n", str);
	ft_printf("ftprinting str: %s 123\n", str);

	printf("  _printing *str: %p 123\n", str);
	ft_printf("ftprinting *str: %p 123\n", str);

	return (0);
}
