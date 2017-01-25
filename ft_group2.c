/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:52:40 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/25 21:38:44 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sosi_pisku(t_printf **pf)
{
	(*pf)->piska += ft_strlen((*pf)->tx);
	(*pf)->piska += ft_strlen((*pf)->prefix);
	(*pf)->piska += ft_strlen((*pf)->field);
	(*pf)->piska += ft_strlen(&(*pf)->sign);
	(*pf)->piska += ft_strlen(&(*pf)->hex);

	if ((*pf)->piska > INT_MAX)
	{
		ft_putstr("-1");
		exit(-1);
	}
}

static	void	ft_group2_sign(t_printf **pf)               // (*pf)->base need to be 10
{
	((*pf)->base == 8) ? (*pf)->hex = '0' : 0;
	((*pf)->base == 8 && (*pf)->cf[0] == '#') ? --(*pf)->presc : 0;
	((*pf)->base == 8 && (*pf)->cf[0] == '#') ? --(*pf)->min_field : 0;
	((*pf)->base == 16 && (*pf)->cf[0] == '#') ? (*pf)->min_field -= 2 : 0;
	((*pf)->base == 16) ? (*pf)->sign = 'X' : 0;
	((*pf)->base == 16) ? (*pf)->hex = '0' : 0;
	((*pf)->cl == 'x') ? ft_loweralize((*pf)->tx) : 0;
	((*pf)->cl == 'x') ? ft_loweralize(&(*pf)->sign) : 0;
	(*pf)->ltx = ft_strlen((*pf)->tx);
}

void			ft_group2(t_printf **pf, va_list *pc)
{
	char	bs;

	((*pf)->cl == 'o' || (*pf)->cl == 'O') ? (*pf)->base = 8 : 0;
	((*pf)->cl == 'x' || (*pf)->cl == 'X') ? (*pf)->base = 16 : 0;
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
	ft_group_output(pf);
}
