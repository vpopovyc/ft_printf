#include "includes/libft.h"

void	ft_pssn(char s, unsigned int n)
{
	unsigned int	nb;

	nb = n + 1;
	while (--nb && s)
		write(1, &s, 1);	
}
