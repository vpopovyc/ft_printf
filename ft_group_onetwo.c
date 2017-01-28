/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group_onetwo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:52:40 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/25 21:38:44 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_group1_sign(t_printf **pf)
{
    (*pf)->ltx = (int)ft_strlen((*pf)->tx);
    ((*pf)->cf[3] == ' ' && (*pf)->tx[0] != '-') ? (*pf)->sign = ' ': 0;
    ((*pf)->cf[2] == '+' && (*pf)->tx[0] != '-') ? (*pf)->sign = '+': 0;
    ((*pf)->sign != 0) ? --(*pf)->min_field : 0;
    ((*pf)->sign != 0) ? ++(*pf)->lnpr : 0;
}

static	void	ft_group2_sign(t_printf **pf)
{
    (*pf)->ltx = (int)ft_strlen((*pf)->tx);
    if ((*pf)->cf[0] == '#' && (*pf)->base != 10)
    {
        if ((*pf)->base == 8)
        {
            --(*pf)->presc;
            --(*pf)->min_field;
            ++(*pf)->lnpr;
        }
        else if ((*pf)->base == 16)
        {
            (*pf)->min_field -= 2;
            (*pf)->lnpr += 2;
            (*pf)->hex = ((*pf)->cl == 'x' || (*pf)->cl == 'p') ? 'x' : 'X';
        }
        (*pf)->sign = '0';
    }
    ((*pf)->cl == 'x' || (*pf)->cl == 'p') ? ft_loweralize((*pf)->tx) : 0;
    
}

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
    ft_group1_sign(pf);
    ft_group_field(pf);
}



void			ft_group2(t_printf **pf, va_list *pc)
{
	char	bs;

	bs = (*pf)->base;
	if ((*pf)->sm == 0)
		(*pf)->tx = ft_stoab(va_arg(*pc, unsigned int), bs);
	else if ((*pf)->sm == 1)
		(*pf)->tx = ft_stoab((unsigned char)va_arg(*pc, unsigned int), bs);
	else if ((*pf)->sm == 2)
		(*pf)->tx = ft_stoab((unsigned short)va_arg(*pc, unsigned int), bs);
	else if ((*pf)->sm == 3)
		(*pf)->tx = ft_stoab(va_arg(*pc, unsigned long), bs);
	else if ((*pf)->sm == 4)
		(*pf)->tx = ft_stoab(va_arg(*pc, unsigned long long), bs);
	else if ((*pf)->sm == 5)
		(*pf)->tx = ft_stoab(va_arg(*pc, uintmax_t), bs);
	else if ((*pf)->sm == 6)
		(*pf)->tx = ft_stoab(va_arg(*pc, size_t), bs);
	ft_group2_sign(pf);
	ft_group_field(pf);
}
