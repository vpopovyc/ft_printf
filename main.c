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
    setlocale(LC_ALL, "");
    char c;
  //  wint_t  c = WEOF;
  //  int	    id = c;
  //  printf("%i\n", id);
//    write(1, &id, 1);
    // wchar_t *s = L"Антон пидор, привет Игорь";
    //"@moulitest: %.d %.0d", 0, 0
    
  /*  printf("\nBytes returned: %i\n", ft_printf("{% C}", L'a'));
    printf("\nBytes returned: %i\n",    printf("{% C}", L'a'));
*/
    printf("\nBytes returned: %i\n", ft_printf("%c%*d", 'c', INT_MAX - 1, 10));
    printf("\nBytes returned: %i\n",    printf("%c%*d", 'c', INT_MAX - 1, 10));

/*    printf("\nBytes returned: %i\n", ft_printf("%C", L'莨'));
    printf("\nBytes returned: %i\n",    printf("%C", L'莨'));
    

    printf("\nBytes returned: %i\n", ft_printf("%C", L'δ'));
    printf("\nBytes returned: %i\n",    printf("%C", L'δ'));
    
    printf("\nBytes returned: %i\n", ft_printf("%C", L'요'));
    printf("\nBytes returned: %i\n",    printf("%C", L'요'));
    
*/
	return (0);
}
