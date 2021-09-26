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
	//*str = "test";

	printf("Printing n: %d\n", n);
	ft_printf("Printing n: %d\n", n);

	printf("Printing c: %c\n", c);
	printf("Printing str: %s\n", str);

	return (0);
}
