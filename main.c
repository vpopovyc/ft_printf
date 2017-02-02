/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:39:36 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/29 22:11:25 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
   // setlocale(LC_ALL, "");"%0+5d", 42 "@moulitest: %5.d %5.0d", 0, 0
   // wchar_t *s = L"Антон пидор, привет Игорь"; "@moulitest: %.d %.0d", 0, 0
    
    
    printf("\nBytes returned: %i\n", ft_printf("{%S}", NULL));
    printf("\nBytes returned: %i\n",    printf("{%S}", NULL));
    
//    printf("\nBytes returned: %i\n", ft_printf("%c", 0));
//    printf("\nBytes returned: %i\n",    printf("%c", 0));

//    printf("\nBytes returned: %i\n", ft_printf("@moulitest: %.10d", -42));
//    printf("\nBytes returned: %i\n",    printf("@moulitest: %.10d", -42));
    
    
//    printf("\nBytes returned: %i\n", ft_printf("%d", -1));
//    printf("\nBytes returned: %i\n",    printf("%d", -1));
    
//    printf("\nBytes returned: %i\n", ft_printf("%5d", -42));
//    printf("\nBytes returned: %i\n",    printf("%5d", -42));
    
	return (0);
}
