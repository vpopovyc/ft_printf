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

ssize_t                  ft_check(t_printf **pf)
{
    if ((*pf)->lnpr + (*pf)->nf + (*pf)->ltx > (*pf)->mnpr)
        return ((*pf)->lnpr = -1);
    return (1);
}




static void			ft_group1_sign(t_printf **pf)
{
    (*pf)->ltx = (int)ft_strlen((*pf)->tx);
    ((*pf)->cf[3] == ' ' && (*pf)->tx[0] != '-') ? (*pf)->sign = ' ' : 0;
    ((*pf)->cf[2] == '+' && (*pf)->tx[0] != '-') ? (*pf)->sign = '+' : 0;
    ((*pf)->tx[0] == '-') ? (*pf)->sign = '-' : 0;
    ((*pf)->tx[0] == '-') ? (*pf)->presc += 1 : 0;
    ((*pf)->tx[0] == '-') ? (*pf)->tx += 1 : 0;
    ((*pf)->sign == ' ' || (*pf)->sign == '+') ? --(*pf)->min_field : 0;
    ((*pf)->sign == ' ' || (*pf)->sign == '+') ? ++(*pf)->lnpr : 0;
    if (*((*pf)->tx) == '0')
    {
        if (*((*pf)->spec + (*pf)->lspc - 1) == '.' && (*pf)->presc == -1)
        {
            (*pf)->ltx = 0;
            (*pf)->cf[4] = '*';
        }
        else if (*((*pf)->spec + (*pf)->lspc - 1) == '0' && (*pf)->presc == -1)
        {
            (*pf)->ltx = 0;
            (*pf)->cf[4] = '*';
        }
    };
}

static  void    ft_shit(t_printf **pf)
{
    if ((*((*pf)->tx) == '0' && (*pf)->lspc >= 2))
    {
        if (*((*pf)->spec + (*pf)->lspc - 1) == '.' && (*pf)->presc <= 0)
        {
            (*pf)->ltx = 0;
            (*pf)->cf[4] = '*';
        }
        else if (*((*pf)->spec + (*pf)->lspc - 1) == '0')
        {
            (*pf)->ltx = 0;
            (*pf)->cf[4] = '*';
        }
        else if ((*pf)->cf[0] == '#')
            (*pf)->ltx = 0;
        else if (*((*pf)->spec + (*pf)->lspc - 1) == '+')
            (*pf)->ltx = 1;
    }
}

static	void	ft_group2_sign(t_printf **pf)
{
    (*pf)->ltx = (int)ft_strlen((*pf)->tx);
    if (((*pf)->cf[0] == '#' && (*pf)->base != 10))
    {
        ((*pf)->base == 8 && *((*pf)->tx) != '0') ? --(*pf)->presc : 0;
        ((*pf)->base == 8 && *((*pf)->tx) != '0') ? --(*pf)->min_field : 0;
        ((*pf)->base == 8 ) ? ++(*pf)->lnpr : 0;
        ((*pf)->base == 8 ) ? (*pf)->sign = '0' : 0;
        if ((*pf)->base == 16 && (*((*pf)->tx) != '0' || (*pf)->cl == 'p'))
        {   
            (*pf)->min_field -= 2;
            (*pf)->lnpr += 2;
            (*pf)->hex = ((*pf)->cl == 'x' || (*pf)->cl == 'p') ? 'x' : 'X';
            (*pf)->sign = '0';
        }
    }
    ((*pf)->cl == 'x' || (*pf)->cl == 'p') ? ft_loweralize((*pf)->tx) : 0;
    if ((*((*pf)->tx) == '0' && (*pf)->lspc >= 2) && (*pf)->sm == 0)
        if (*((*pf)->spec + (*pf)->lspc - 1) == '.' || (*pf)->presc <= 0)
        {
            (*pf)->ltx = 0;
            (*((*pf)->spec + (*pf)->lspc - 1) == '#') ? (*pf)->ltx = 1 : 0;
            (*pf)->cf[4] = '*';
        }
    ((*pf)->cl == 'o') ? ft_shit(pf) : 0;
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
    ft_group_one_output(pf);
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
    ((*pf)->cl == 'p') ? (*pf)->sm = 0 : 0;
	ft_group2_sign(pf);
	ft_group_field(pf);
    ft_group_two_output(pf);
}
