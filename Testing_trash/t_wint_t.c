#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <wchar.h>
#include <wctype.h>
#include <unistd.h>
#include <locale.h>
#include "ft_printf.h"

int		main(void)
{
//	wchar_t *s = L"";
//	wint_t c = 255;
//	wchar_t s[] = L"இ";

	setlocale(LC_ALL, "");
	
//	ft_putstr(s);
//	wint_t b = -1;
   	wchar_t *s = L"™¢";
	int	n = *(s + 1);
	int b = *(s);
	wint_t h = *(s + 1);
	int i = h;
//	int n = b;/
	write(1, &i, 1);
	printf("\nn: %i\nb: %i\n", n, b);

	return (printf("\n%i\n", printf("%lc", h)));
}
