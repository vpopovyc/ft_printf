#include "includes/libft.h"
#include <stdio.h>

int		main(void)
{
	char 	*b;
	char	*tmp;

	b = ft_strdup("Lama");
	printf("b: %p\n", b);
	tmp = b;
	printf("tmp: %p\n", tmp);
	b = ft_strnfjoin(b, "Suchek", ft_strlen("Suchek"));
	printf("%s\n", b);
	printf("%p\n", b);
	//free(tmp);
	return (0);
}
