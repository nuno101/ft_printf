#include <stdio.h>
#include "../ft_printf.c"

int	main()
{
	int n;
	unsigned int u;
	char c;
	//char *str[5];
	char str[] = "test";
	int r; //result
	int ftr; //ft_ result
	int len;

	n = 123;
	u = 123567890;
	c = 'c';

	r = printf("%%\n");
	ftr = ft_printf("%%\n");
	printf("r = %d and ftr = %d\n\n", r, ftr);


	r = printf("%2%\n");
	ftr = ft_printf("%2%\n");
	printf("r = %d and ftr = %d\n\n", r, ftr);

	r = printf("c: %c 123\n", c);
	ftr = ft_printf("c: %c 123\n", c);
	printf("r = %d and ftr = %d\n\n", r, ftr);

	r = printf("c: %3c 123\n", c);
	ftr = ft_printf("c: %3c 123\n", c);
	printf("r = %d and ftr = %d\n\n", r, ftr);

	len = _putnbr(n);
	r = printf("n: %d\n", n);
	ftr = ft_printf("n: %d\n", n);
	printf("len = %d, r = %d and ftr = %d\n\n", len, r, ftr);

	len = _putnbr(-n);
	r = printf("n: %d\n", -n);
	ftr = ft_printf("n: %d\n", -n);
	printf("len = %d, r = %d and ftr = %d\n\n", len, r, ftr);

	r = printf("i: %i 123\n", n);
	ftr = ft_printf("i: %i 123\n", n);
	printf("r = %d and ftr = %d\n\n", r, ftr);

	r = printf("u: %i 123\n", u);
	ftr = ft_printf("u: %i 123\n", u);
	printf("r = %d and ftr = %d\n\n", r, ftr);

	u = -1;
	r = printf("u: %u\n", u);
	ftr = ft_printf("u: %u\n", u);
	printf("r = %d and ftr = %d\n\n", r, ftr);

	u = -2;
	r = printf("u: %u 123\n", u);
	ftr = ft_printf("u: %u 123\n", u);
	printf("r = %d and ftr = %d\n\n", r, ftr);

    r = printf(" NULL %s NULL \n", NULL);
    ftr = ft_printf(" NULL %s NULL \n", NULL);
	printf("r = %d and ftr = %d\n\n", r, ftr);

	r = printf("hex: %x\n", u);
	ftr = ft_printf("hex: %x\n", u);
	printf("r = %d and ftr = %d\n\n", r, ftr);

	r = printf("HEX: %X 123\n", u);
	ftr = ft_printf("HEX: %X 123\n", u);
	printf("r = %d and ftr = %d\n\n", r, ftr);

	n = -210;
	r = printf("n: %d123\n", n);
	ftr = ft_printf("n: %d123\n", n);
	printf("r = %d and ftr = %d\n\n", r, ftr);

	r = printf("c: %c123\n", c);
	ftr = ft_printf("c: %c123\n", c);
	printf("r = %d and ftr = %d\n\n", r, ftr);

	r = printf("str: %s 123\n", str);
	ftr = ft_printf("str: %s 123\n", str);
	printf("r = %d and ftr = %d\n\n", r, ftr);

	r = printf("*str: %p 123\n", str);
	ftr = ft_printf("*str: %p 123\n", str);
	printf("r = %d and ftr = %d\n\n", r, ftr);

	return (0);
}
