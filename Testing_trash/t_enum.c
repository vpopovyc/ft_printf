/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_enum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:15:51 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/18 18:39:10 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdio.h>

int		main(void)
{
	enum	size_spec 	 spec;
	char 			*s = strdup("hl");
	char 			*res = strdup("**");
	int 	i;

	spec = pravoslavniy_nyl;
	s++;
	(*s == 'l' && spec < l) ? i = l: spec;
	printf("%zd\n", i);	
}
