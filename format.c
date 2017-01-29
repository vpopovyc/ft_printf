/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:20:45 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/25 21:03:56 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static void	status(t_printf *s)
{
	printf("Format string:            %s\n", s->ft);
	printf("Lenght of format string:  %i\n", s->nf);
	printf("Specifier string:         %s\n", s->spec);
	printf("Lenght of specifier:      %i\n", s->lspc);
	printf("Conversion letter:        %c\n", s->cl);
	printf("Conversion flags:         %s\n", s->cf);
	printf("Minimal field:            %i\n", s->min_field);
	printf("Prescision:               %i\n", s->presc);
	printf("Size specifier:           %i\n", s->sm);
}
*/
static void		ft_flags(char *sv, t_printf **pf)
{
    char 	f;
    
    f = 1;
    while (*(++sv))
    {
        (*sv >= '1' && *sv <= '9' && f) ? f = 0 : 0;
        (*sv == '#') ? (*pf)->cf[0] = '#' : 0;
        (*sv == '-') ? (*pf)->cf[1] = '-' : 0;
        (*sv == '+') ? (*pf)->cf[2] = '+' : 0;
        (*sv == ' ') ? (*pf)->cf[3] = ' ' : 0;
        if (*sv == '0' && f)
        {
            (*pf)->cf[4] = '0';
            f = 1;
        }
        (!ft_isdigit(*sv)) ? f = 1 : 0;
    }
   	if (ft_isprintf_up_spec(*(--sv)))
	 {
	   	(*pf)->cl = ft_tolower(*sv);	
		(*pf)->sm = 3;
	 }
	else
	 	(*pf)->cl = *sv;
}

static void		ft_size_spec(char *sv, t_printf **pf)
{
    sequence 	spec;
    
    spec = beer;
    while (*(++sv))
    {
        (*sv == 'h' && h > spec) ? spec = h : 0;
        (*sv == 'l' && l > spec) ? spec = l : 0;
        (*sv == 'j' && j > spec) ? spec = j : 0;
        (*sv == 'z' && z > spec) ? spec = z : 0;
        (*sv == 'h' && *(sv + 1) == 'h' && hh > spec) ? spec = hh : 0;
        (*sv == 'l' && *(sv + 1) == 'l' && ll > spec) ? spec = ll : 0;
    }
    ((*pf)->sm < spec) ? (*pf)->sm = spec : 0;
    ((*pf)->cl == 'p') ? (*pf)->sm = z : 0;
    ((*pf)->cl == 'p') ? (*pf)->cf[0] = '#' : 0;
    ((*pf)->cl == 'o') ? (*pf)->base = 8 : 0;
    ((*pf)->cl == 'X') ? (*pf)->base = 16 : 0;
    ((*pf)->cl == 'x' || (*pf)->cl == 'p') ? (*pf)->base = 16 : 0;
}

static void		ft_minfld_presc(char *sv, t_printf **pf)
{
    char 	f;
    
    f = 1;
    while (*(++sv))
    {
        if ((*sv >= '1' && *sv <= '9') && f)
        {
            if (f == 1)
                (*pf)->min_field = (int)ft_atosize_t(sv);
            else if (f == 2)
                (*pf)->presc = (int)ft_atosize_t(sv);
            f = 0;
        }
        else if (*sv == '.')
            f = 2;
        else if (!(*sv >= '1' && *sv <= '9'))
            f = 1;
    }
}

void            ft_s_spec(t_printf **pf, char *sv)
{
    ft_s_printf_clr(pf);
    while (*(++sv))
    {
        ++(*pf)->lspc;
        if (ft_isascii(*sv) && !ft_isprintf_spec(*sv))
            break;
    }
    (*pf)->spec = ft_strnfjoin((*pf)->spec, sv - (*pf)->lspc, (*pf)->lspc + 1);
    ft_flags((*pf)->spec, pf);
    ft_size_spec((*pf)->spec, pf);
    ft_minfld_presc((*pf)->spec, pf);
/*  status(*pf); */
}

int             ft_printf(char *sv, ...)
{
	va_list		pc;
	t_printf	*pf;

	if ((pf = ft_s_printf_new()) == NULL)
	   return (-1);	
	va_start(pc, sv);
    ft_making_move(&pf, &pc, sv);
    (pf->cl == 0) ? ft_putstr(sv) : 0;
	va_end(pc);
	return (pf->lnpr);
}
