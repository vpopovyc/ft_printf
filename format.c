/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:20:45 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/18 19:10:14 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *sv, ...)
{
	va_list		pc;
	t_printf	*pf;

	if ((pf = ft_s_printf_new()) == NULL)   //Create struct t_printf, check for erreur
	   return (-1);	
	va_start(pc, sv);
	while (*sv)
	{
		if (*sv == '%')                     //Get len of specifier and write it to struct(len_spec)
		{
			ft_s_spec(&pf, sv/*, &pc*/);        //First - save spec to struct; Second - print arg;  
			sv += pf->lspc + 1;             //Increse value in &sv, to skip all symbols of specifier 
		}
		else
		{
			write (1, sv, 1);
			++pf->lnpr;
			++sv;
		}
	}
	va_end(pc);
	return (pf->lnpr);
}
