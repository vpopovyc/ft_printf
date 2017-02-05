/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_min_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:12:43 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/19 20:47:42 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	char *s = strdup("%-010.12-1s");
	int		 d = 0;
	int		 p = 0;
	char     f = 1;

    
    while (*(++sv))
    {
        if ((*sv >= '1' && *sv <= '9') && f)
        {
            f == 1 ? (*pf)->min_field = (int)ft_atosize_t(sv) : 0;
            f == 2 ? (*pf)->presc = (int)ft_atosize_t(sv) : 0;
            f == 3 ? (*pf)->min_field = va_arg(*pc, int) : 0;
            f == 4 ? (*pf)->presc = va_arg(*pc, int) : 0;
            f = 0;
        }
        else if (*sv == '.' && *(sv + 1) == '*')
            f = 4;
        else if (*sv == '.')
            f = 2;
        else if (*sv == '*' && *(sv - 1) != '.')
            f = 3;
        else if (!(*sv >= '1' && *sv <= '9'))
            f = 1;
    }
	printf("d: %i\np: %i\n", d, p);
	return (0);
}
/*
 * size_t           		int
 * 0000 0100 0      |	0000 0100 0
 * 0100 0000 1		| 	0100 0000 1
 * 0000 0010 2		|	0000 0010 2
 * 1000 0000 3		|	1000 0000 3
 *                  |
 * 1000 0100 4      |   Mi     
 * 0000 0000 5		|		ssi
 * 0010 0100 6 		|          ng,
 * 0000 0001 7		|	suqa
*/
