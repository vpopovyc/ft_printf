#include "ft_printf.h"
#define CAST(cl, size_spec) ft_cast((cl), (size_spec))

void	ft_cast(char cl, int size_spec)
{	
	#undef CAST
	#define CAST {int}
}

int main(void)
{
	size_t	i = INT_MAX;

	int 	d = CAST(42, 2) i;
	return(printf("%i\n", i));
}
