/*
** main_test.c : NOT part of the submission.
**
** For every test it runs the real printf and your ft_printf, captures what
** each one writes, then compares the OUTPUT and the RETURN VALUE.
**
** Compile (works with or without -Werror):
**   make
**   cc -Wall -Wextra -fno-builtin main_test.c -L. -lftprintf -o test
**
** Run:
**   ./test
**   valgrind --leak-check=full ./test
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

/* tests are intentionally "odd" for the compiler: silence those warnings */
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wformat-zero-length"
#pragma GCC diagnostic ignored "-Wformat-overflow"

#define BUFSZ 8192

static int	g_ok;
static int	g_ko;

static int	grab_start(int p[2])
{
	int	saved;

	fflush(stdout);
	saved = dup(1);
	pipe(p);
	dup2(p[1], 1);
	close(p[1]);
	return (saved);
}

static int	grab_end(int p[2], int saved, char *buf)
{
	int	n;

	fflush(stdout);
	dup2(saved, 1);
	close(saved);
	n = read(p[0], buf, BUFSZ - 1);
	if (n < 0)
		n = 0;
	close(p[0]);
	return (n);
}

static void	show(const char *b, int n)
{
	int	i;

	printf("|");
	i = 0;
	while (i < n)
	{
		if (b[i] == '\n')
			printf("\\n");
		else if (b[i] == '\0')
			printf("\\0");
		else
			printf("%c", b[i]);
		i++;
	}
	printf("|");
}

static void	check(const char *label, char *b1, int n1, int r1, char *b2,
				int n2, int r2)
{
	if (n1 == n2 && memcmp(b1, b2, n1) == 0 && r1 == r2)
	{
		g_ok++;
		printf("[OK] %s\n", label);
		return ;
	}
	g_ko++;
	printf("[KO] %s\n", label);
	printf("     expected: ");
	show(b1, n1);
	printf("  return: %d\n", r1);
	printf("     yours   : ");
	show(b2, n2);
	printf("  return: %d\n", r2);
}

#define T(...) do { \
	int p1[2]; int p2[2]; int s; int r1; int r2; int n1; int n2; \
	char b1[BUFSZ]; char b2[BUFSZ]; \
	s = grab_start(p1); r1 = printf(__VA_ARGS__); n1 = grab_end(p1, s, b1); \
	s = grab_start(p2); r2 = ft_printf(__VA_ARGS__); n2 = grab_end(p2, s, b2); \
	check(#__VA_ARGS__, b1, n1, r1, b2, n2, r2); \
} while (0)

int	main(void)
{
	int			x = 42;
	char		*nullstr = NULL;
	void		*null_ptr = NULL;
	char		buf[10] = "abc";

	printf("===== plain text =====\n");
	T("Hello World\n");
	T("");
	T("no conversion at all");
	T("tab\there\n");

	printf("===== %%c =====\n");
	T("%c", 'a');
	T("%c", ' ');
	T("%c", '0');
	T("%c", 0);
	T("%c%c%c", 'a', 'b', 'c');
	T("[%c]\n", 'Z');
	T("%c", 255);
	T("%c %c %c\n", '4', '2', '!');

	printf("===== %%s =====\n");
	T("%s", "hello");
	T("%s", "");
	T("%s", nullstr);
	T("[%s]\n", "world");
	T("%s %s", "hello", "world");
	T("a%sb%sc", "1", "2");
	T("%s", "a very long string to be sure nothing is cut or lost at the end of it 0123456789");

	printf("===== %%d and %%i =====\n");
	T("%d", 0);
	T("%d", 42);
	T("%d", -42);
	T("%d", 1);
	T("%d", -1);
	T("%d", 10);
	T("%d", 100);
	T("%d", INT_MAX);
	T("%d", INT_MIN);
	T("%i", 0);
	T("%i", 42);
	T("%i", -42);
	T("%i", INT_MAX);
	T("%i", INT_MIN);
	T("%d %i", 123, -456);
	T("%d\n", 2147483647);
	T("%d\n", -2147483647 - 1);

	printf("===== %%u =====\n");
	T("%u", 0);
	T("%u", 42);
	T("%u", UINT_MAX);
	T("%u", -1);
	T("%u", INT_MAX);
	T("%u", (unsigned int)INT_MIN);
	T("%u", 4294967295u);
	T("%u %u", 1, 2);

	printf("===== %%x and %%X =====\n");
	T("%x", 0);
	T("%x", 1);
	T("%x", 9);
	T("%x", 10);
	T("%x", 15);
	T("%x", 16);
	T("%x", 255);
	T("%x", 4096);
	T("%x", 48879);
	T("%x", UINT_MAX);
	T("%x", -1);
	T("%x", INT_MIN);
	T("%X", 0);
	T("%X", 255);
	T("%X", 48879);
	T("%X", UINT_MAX);
	T("%X", -1);
	T("%x %X", 3054, 3054);

	printf("===== %%p =====\n");
	T("%p", &x);
	T("%p", buf);
	T("%p", null_ptr);
	T("%p", (void *)1);
	T("%p", (void *)255);
	T("%p", (void *)0x7fffffffUL);
	T("%p", (void *)ULONG_MAX);
	T("%p", (void *)LONG_MIN);
	T("[%p] [%p]", &x, null_ptr);

	printf("===== %%%% =====\n");
	T("%%");
	T("%%%%");
	T("%%%%%%");
	T("100%%");
	T("100%%\n");
	T("%%c");
	T("%c%%%c", 'a', 'b');
	T("%d%%", 50);

	printf("===== mixed =====\n");
	T("%c %s %d %i %u %x %X %p %%\n", 'A', "str", -7, 7, 7u, 255, 255, &x);
	T("%s is %d years old and likes %c\n", "Mo", 20, 'C');
	T("%d%d%d%d\n", 1, 2, 3, 4);
	T("%x%X%x\n", 171, 171, 171);
	T("%s%s%s\n", "a", "b", "c");
	T("%c%c%c%c%c\n", 'h', 'e', 'l', 'l', 'o');
	T("Number: %d, Hex: %x, Ptr: %p\n", 255, 255, null_ptr);
	T("%%d prints %d, %%s prints %s\n", 42, "text");
	T("%u and %d and %i\n", UINT_MAX, INT_MIN, INT_MAX);
	T("%s", "%d");
	T("%s%%%s", "a", "b");

	printf("\n===== RESULT: %d OK / %d KO =====\n", g_ok, g_ko);
	return (g_ko != 0);
}
