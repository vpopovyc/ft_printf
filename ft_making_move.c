/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_making_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 14:11:32 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/25 20:36:09 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int      ft_get_arg(t_printf **pf, va_list *pc)
{
    size_t      i;
    size_t      b;
    
    i = (*pf)->min_field + (*pf)->nf;
    b = (*pf)->presc + (*pf)->nf;
    if (b > (*pf)->mnpr || i > (*pf)->mnpr)
    {
        (*pf)->lnpr = -1;
        return(0);
    }
	(ft_iscl_group1((*pf)->cl)) ? ft_group1(pf, pc) : 0;
	(ft_iscl_group2((*pf)->cl)) ? ft_group2(pf, pc) : 0;
    (ft_iscl_group3((*pf)->cl)) ? ft_group3(pf, pc) : 0;
    if ((*pf)->lnpr == -1)
        return (0);
    (*pf)->mnpr -= (*pf)->lnpr;
    (*pf)->nf = 0;
    return (1);
}

void               ft_making_move(t_printf **pf, va_list *pc, char *sv)
{
    while (*sv)
    {
        if (*sv == '%')
        {
            ft_s_spec(pf, sv);
            (*pf)->ft = ft_strnfjoin((*pf)->ft, sv - (*pf)->nf, (*pf)->nf);
            if (!ft_get_arg(pf, pc))
                return ;
            sv += (*pf)->lspc + 1;
        }
        else
        {	
            ++(*pf)->nf;
            ++sv;
        }
    }
    if ((*pf)->nf != 0)
    {
        (*pf)->lnpr += (*pf)->nf;
        if (ft_check(pf))
            ft_psn(sv - (*pf)->nf, (*pf)->nf);
    }
}
