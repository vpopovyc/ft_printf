/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 19:50:31 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/24 20:42:30 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_group1_output(t_printf **pf)
{
	ft_putstr((*pf)->ft);
    if ((*pf)->conv_flag[1] == '-')
    {
		if ((*pf)->conv_flag[2] == '+' || (*pf)->conv_flag[3] == ' ')
			ft_putchar((*pf)->sign);
        ft_putstr((*pf)->prefix);
        ft_putstr((*pf)->text);
        ft_putstr((*pf)->field);
    }
    else
    {
        ft_putstr((*pf)->field);
		if ((*pf)->conv_flag[2] == '+' || (*pf)->conv_flag[3] == ' ')
			ft_putchar((*pf)->sign);
        ft_putstr((*pf)->prefix);
        ft_putstr((*pf)->text);
    }
}
/* ************************************************************************** */

static void			ft_group1_sign(t_printf **pf)
{
    ((*pf)->conv_flag[3] == ' ' && (*pf)->text[0] != '-') ? (*pf)->sign = ' ': 0;
    ((*pf)->conv_flag[2] == '+' && (*pf)->text[0] != '-') ? (*pf)->sign = '+': 0;
    ((*pf)->sign != 0) ? --(*pf)->min_field : 0;
}

static void			ft_group1_prefix(t_printf **pf)
{
    int		prx;
    char	*prefix;
    
    prx = (*pf)->ltxt - (*pf)->presc;
    if (prx < 0)
        prx = -prx;
    else
        return ;
    prefix = ft_strnew(prx);
    ft_memset(prefix, '0', prx);
    (*pf)->prefix = ft_strnfjoin((*pf)->prefix, prefix, prx);
    (*pf)->ltxt += prx;
}

static void			ft_group1_field(t_printf **pf)
{
    int		fld;
    char	*field;
    
    ft_group1_prefix(pf);
    ft_group1_sign(pf);
    fld = (*pf)->ltxt - (*pf)->min_field;
   	if (fld < 0)
        fld = -fld;
    else
        return ;
    field = ft_strnew(fld);
    if ((*pf)->conv_flag[4] != '0' || (*pf)->presc != -1 || (*pf)->conv_flag[1] == '-')
        ft_memset(field, ' ', fld);
    else
        ft_memset(field, '0', fld);
	(*pf)->field = ft_strnfjoin((*pf)->field, field, fld);
}

void	ft_group1(t_printf **pf, va_list *pc)
{
    if ((*pf)->size_spec == 0)
        (*pf)->text = ft_ssize_t_toa_base(va_arg(*pc, int), 10);
    else if ((*pf)->size_spec == 1)
        (*pf)->text = ft_ssize_t_toa_base((signed char)va_arg(*pc, int), 10);
    else if ((*pf)->size_spec == 2)
        (*pf)->text = ft_ssize_t_toa_base((short)va_arg(*pc, int), 10);
    else if ((*pf)->size_spec == 3)
        (*pf)->text = ft_ssize_t_toa_base(va_arg(*pc, long), 10);
    else if ((*pf)->size_spec == 4)
        (*pf)->text = ft_ssize_t_toa_base(va_arg(*pc, long long), 10);
    else if ((*pf)->size_spec == 5)
        (*pf)->text = ft_ssize_t_toa_base(va_arg(*pc, intmax_t), 10);
    else if ((*pf)->size_spec == 6)
        (*pf)->text = ft_ssize_t_toa_base(va_arg(*pc, ssize_t), 10);
    (*pf)->ltxt = ft_strlen((*pf)->text);
    ft_group1_field(pf);
    ft_group1_output(pf);
}
