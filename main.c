#include "ft_printf.h"

int	main(void)
{
	int	count;

	count = ft_printf("Hello %s, you are %d years old (0x%x)\n", "Mo", 20, 255);
	ft_printf("%d characters were printed\n", count);
	return (0);
}
