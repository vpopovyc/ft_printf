/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 19:50:31 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/25 21:50:55 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_group_output(t_printf **pf)
{
	ft_sosi_pisku(pf);
	ft_putstr((*pf)->ft);
    if ((*pf)->cf[1] == '-')
    {
		((*pf)->base != 10 && (*pf)->cf[0] == '#') ? ft_putstr(&(*pf)->hex) : 0;
		((*pf)->base == 16 && (*pf)->cf[0] == '#') ? ft_putstr(&(*pf)->sign) : 0;
		if (((*pf)->cf[2] == '+' || (*pf)->cf[3] == ' ') && (*pf)->base == 10)
			ft_putchar((*pf)->sign);
        ft_putstr((*pf)->prefix);
        ft_putstr((*pf)->tx);
        ft_putstr((*pf)->field);
    }
    else
	{
		if (((*pf)->cf[2] == '+' || (*pf)->cf[3] == ' ') && (*pf)->base == 10)
			ft_putstr(&(*pf)->sign);
        ft_putstr((*pf)->field);
		((*pf)->base != 10 && (*pf)->cf[0] == '#') ? ft_putchar((*pf)->hex) : 0;
		((*pf)->base == 16 && (*pf)->cf[0] == '#') ? ft_putchar((*pf)->sign) : 0;
        ft_putstr((*pf)->prefix);
        ft_putstr((*pf)->tx);
    }
}
/* ************************************************************************** */

static void			ft_group1_sign(t_printf **pf)
{
    ((*pf)->cf[3] == ' ' && (*pf)->tx[0] != '-') ? (*pf)->sign = ' ': 0;
    ((*pf)->cf[2] == '+' && (*pf)->tx[0] != '-') ? (*pf)->sign = '+': 0;
    ((*pf)->sign != 0) ? --(*pf)->min_field : 0;
}

void				ft_group_prefix(t_printf **pf)
{
    int		prx;
    char	*prefix;
   
    prx = (*pf)->ltx - (*pf)->presc;
    if (prx < 0)
        prx = -prx;
    else
        return ;
    prefix = ft_strnew(prx);
    ft_memset(prefix, '0', prx);
    (*pf)->prefix = ft_strnfjoin((*pf)->prefix, prefix, prx);
    (*pf)->ltx += prx;
}

void				ft_group_field(t_printf **pf)
{
    int		fld;
    char	*field;
    
    ft_group_prefix(pf);
    fld = (*pf)->ltx - (*pf)->min_field;
   	if (fld < 0)
        fld = -fld;
    else
        return ;
    field = ft_strnew(fld);
    if ((*pf)->cf[4] != '0' || (*pf)->presc != -1 || (*pf)->cf[1] == '-')
        ft_memset(field, ' ', fld);
    else
        ft_memset(field, '0', fld);
	(*pf)->field = ft_strnfjoin((*pf)->field, field, fld);
}
/* ************************************************************************** */

void				ft_group1(t_printf **pf, va_list *pc)
{
    if ((*pf)->sm == 0)
        (*pf)->tx = ft_sstoab(va_arg(*pc, int), 10);
    else if ((*pf)->sm == 1)
        (*pf)->tx = ft_sstoab((signed char)va_arg(*pc, int), 10);
    else if ((*pf)->sm == 2)
        (*pf)->tx = ft_sstoab((short)va_arg(*pc, int), 10);
    else if ((*pf)->sm == 3)
        (*pf)->tx = ft_sstoab(va_arg(*pc, long), 10);
    else if ((*pf)->sm == 4)
        (*pf)->tx = ft_sstoab(va_arg(*pc, long long), 10);
    else if ((*pf)->sm == 5)
        (*pf)->tx = ft_sstoab(va_arg(*pc, intmax_t), 10);
    else if ((*pf)->sm == 6)
        (*pf)->tx = ft_sstoab(va_arg(*pc, ssize_t), 10);
    (*pf)->ltx = ft_strlen((*pf)->tx);
	ft_group1_sign(pf);
    ft_group_field(pf);
    ft_group_output(pf);
}
