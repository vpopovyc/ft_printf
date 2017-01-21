/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 14:11:32 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/21 21:01:55 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flags(char *sv, t_printf **pf)
{
	char 	f;

	f = 1;
	while (*(++sv))                                                     //cuz '%' first
	{
		(*sv >= '1' && *sv <= '9' && f) ? f = 0 : 0;
		(*sv == '#') ? (*pf)->conv_flag[0] = '#': 0;
		(*sv == '-') ? (*pf)->conv_flag[1] = '-': 0;
		(*sv == '+') ? (*pf)->conv_flag[2] = '+': 0;
		(*sv == ' ') ? (*pf)->conv_flag[3] = ' ': 0;
		if (*sv == '0' && f)
		{
			(*pf)->conv_flag[4] = '0';
			f = 1;
		}
		(!ft_isdigit(*sv)) ? f = 1 : 0;
	}
}

static void		ft_size_spec(char *sv, t_printf **pf)
{
	enum size_spec 	spec;

	spec = beer;                                                        // Beer is 0
	while (*(++sv))
	{
		(*sv == 'h' && h > spec) ? spec = h : 0;                        // h is 2 
		(*sv == 'l' && l > spec) ? spec = l : 0;						// l is 3
		(*sv == 'j' && j > spec) ? spec = j : 0;                        // j is 5
		(*sv == 'z' && z > spec) ? spec = z : 0;	                    // z is 6
		(*sv == 'h' && *(sv + 1) > spec && hh > spec) ? spec = hh : 0;  // hh is 1
		(*sv == 'l' && *(sv + 1) == 'l' && ll > spec) ? spec = ll : 0;	// ll is 4
	}
	(*pf)->size_spec = spec;                                            // Save specifier to struct
}

static void		ft_minfld_presc(char *sv, t_printf **pf)                        // Minimal field and prescision
{
	char 	f;

	f = 1;
	while (*(++sv))
	{
		if ((*sv >= '1' && *sv <= '9') && f)	
		{
			if (f == 1)
				(*pf)->min_field = (int)ft_atosize_t(sv);               // CASTING
			else if (f == 2)
				(*pf)->presc = (int)ft_atosize_t(sv);                   // VJUH VJUH      
			f = 0;                                                      // To prevent of rewriting that shit 
		}
		else if (*sv == '.')                                            // It's for prescision
			f = 2;
		else if (!(*sv >= '1' && *sv <= '9'))                            // It's for getting the latest values
			f = 1;
	}
}

static void		ft_conversion_letter(char *sv, t_printf **pf)
{
	while (*sv)
		++sv;
	(*pf)->cl = *(--sv);
}

void        ft_s_spec(t_printf **pf, char *sv/*, va_list *pc*/)
{
	ft_s_printf_clr(pf);                                                    // Clear struct, before using it
	while (*(++sv))
	{
		++(*pf)->lspc;
		if (ft_isalpha(*sv) && !ft_isprintf_spec(*sv))                      // If conversion letter - end cycle
			break;
	}
	(*pf)->spec = ft_strnfjoin((*pf)->spec, sv - (*pf)->lspc, (*pf)->lspc + 1); //Write specifier into struct
	ft_conversion_letter((*pf)->spec, pf);	
	ft_flags((*pf)->spec, pf);
	ft_size_spec((*pf)->spec, pf);
	ft_minfld_presc((*pf)->spec, pf);                                
}
