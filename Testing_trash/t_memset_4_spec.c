/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_memset_4_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 20:51:53 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/17 16:30:01 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int			main(void)
{
	char	*sv = strdup("%#-+ 0"); 
	char	*spec;

	spec = (char*)malloc(sizeof(char) * 6);
	spec = memset((char*)spec, 42, 5);
	spec[6] = '\0';
	printf("spec: %s\n", spec);
	while (*(++sv))
	{
		(*sv == '#') ? spec[0] = '#': 0;
		(*sv == '-') ? spec[1] = '-': 0;
		(*sv == '+') ? spec[2] = '+': 0;
		(*sv == ' ') ? spec[3] = ' ': 0;
		(*sv == '0') ? spec[4] = '0': 0;
		printf("spec after: %s\n", spec);
	}
	return (0);
}
