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

static void     ft_fout(t_printf **pf)
{
	ft_psn((*pf)->ft, (*pf)->nf);
    if ((*pf)->cf[1] == '-')
    {
        ft_psn(&(*pf)->sign, 1);
        ft_pssn((*pf)->prefix, (*pf)->prx);
        ft_putstr(*((*pf)->ws));
        (*pf)->cf[0] == '#' || (*pf)->presc != 0 ? ft_psn(&(*pf)->hex, 1) : 0;
        ft_putstr(*((*pf)->ws) + 1);
        ft_pssn((*pf)->field, (*pf)->fld);
    }
    else
    {
        ((*pf)->sign != 0 && (*pf)->field == '0') ? ft_psn(&(*pf)->sign, 1) : 0;
        ft_pssn((*pf)->field, (*pf)->fld);
        ((*pf)->sign != 0 && (*pf)->field != '0') ? ft_psn(&(*pf)->sign, 1) : 0;
        ft_pssn((*pf)->prefix, (*pf)->prx);
        ft_putstr(*((*pf)->ws));
        (*pf)->cf[0] == '#' || (*pf)->presc != 0 ? ft_psn(&(*pf)->hex, 1) : 0;
        ft_putstr(*((*pf)->ws + 1));
    }
    (*pf)->lnpr += (*pf)->nf + (*pf)->ltx;
}

static void     ft_get_sides(t_printf **pf, double d_tmp)
{
    size_t      right;
    size_t      left;
    
    right = ft_getd_rs(d_tmp);
    left = ft_getd_ls(d_tmp, (*pf)->presc + 1);
    left = (left % 10 < 5) ? left / 10 : (left / 10) + 1;
    (*pf)->hex = '.';
    (*pf)->ws = (char**)malloc(sizeof(char) * 3);
    *((*pf)->ws) = ft_stoab(right, 10);
    *((*pf)->ws + 1) = ft_stoab(left, 10);
    *((*pf)->ws + 2) = NULL;
    (*pf)->ltx += (int)ft_strlen(*((*pf)->ws));
    (*pf)->ltx += (int)ft_strlen(*((*pf)->ws + 1)) + 1;
    ft_group_field(pf);
    ft_fout(pf);
}

void            ft_group4(t_printf **pf, va_list *pc)
{
    double      d_tmp;
    
    d_tmp = 0.0;
    if ((*pf)->cl == 'f')
        d_tmp = va_arg(*pc, double);
    d_tmp < 0.0 ? (*pf)->sign = '-' : 0;
    d_tmp < 0.0 ? ++(*pf)->ltx : 0;
    d_tmp < 0.0 ? d_tmp = -d_tmp : 0;
    (*pf)->presc == -1 ? (*pf)->presc = 6 : 0;
    ft_get_sides(pf, d_tmp);
}

static int      ft_get_arg(t_printf **pf, va_list *pc)
{
    ssize_t      i;
    ssize_t      b;
    
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
    (ft_iscl_group4((*pf)->cl)) ? ft_group4(pf, pc) : 0;
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
            ft_s_spec(pf, sv, pc);
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
