#include "includes/libft.h"

void	ft_psn(char *s, unsigned int n)
{
	(s && *s) ? write(1, s, n) : 0;
}
