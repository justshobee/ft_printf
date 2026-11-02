#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	 int n1 = ft_printf("abd%k\n");
	 int n2 = printf("abd%k\n");
	printf("n1 = %d, n2 = %d\n", n1, n2);
}
