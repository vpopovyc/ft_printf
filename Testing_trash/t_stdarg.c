/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stdarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:44:52 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/11 15:03:06 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void	test(char *s, ...)
{
	va_list		ls;
	va_start(ls, s);
	if (!strcmp(s, "%d"))
	{
		int x = va_arg(ls, int);
		printf ("Decimal flag, printing: %d", x);
	}
	if (!strcmp(s, "%s"))
	{
		char *x = va_arg(ls, char *);
		printf ("String flag, printing: %s", x);
	}
	va_end(ls);
}
