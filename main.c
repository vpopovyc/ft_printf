/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:39:36 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/02/02 21:22:45 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
    char c;
    setlocale(LC_ALL, "");
    // wchar_t *s = L"Антон пидор, привет Игорь";
    //"@moulitest: %.d %.0d", 0, 0
    
    printf("\nBytes returned: %i\n", ft_printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플'));
    printf("\nBytes returned: %i\n",    printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플'));
 
    printf("\nBytes returned: %i\n", ft_printf("%S%D%c", L"暖炉", LONG_MAX, 'c'));
    printf("\nBytes returned: %i\n",    printf("%S%D%c", L"暖炉", LONG_MAX, 'c'));

/*    printf("\nBytes returned: %i\n", ft_printf("{%010i}", 42));
    printf("\nBytes returned: %i\n",    printf("{%010i}", 42));
    
    
    printf("\nBytes returned: %i\n", ft_printf("{%010u}", 42));
    printf("\nBytes returned: %i\n",    printf("{%010u}", 42));
    
    printf("\nBytes returned: %i\n", ft_printf("@moulitest: %5.o %5.0o", 0, 0));
    printf("\nBytes returned: %i\n",    printf("@moulitest: %5.o %5.0o", 0, 0));
    

	*/return (0);
}
