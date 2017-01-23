/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_making_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 14:11:32 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/23 20:40:08 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_iscl_group_1(char c)
{
	if (c == 'd' || c == 'i')
		return (1);
	return (0);
}

int		ft_iscl_group_2(char c)
{
	if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

void	ft_group1(t_printf **pf, va_list *pc)                                  // Ended here!
{
	if ((*pf)->size_spec == 0)
		(*pf)->text = ft_itoa_base(va_arg(*pc, int));
	else if ((*pf)->size_spec == 1)
		(*pf)->text = ft_itoa_base((signed char)va_arg(*pc, int));
	else if ((*pf)->size_spec == 2)
		(*pf)->text = ft_itoa_base((short)va_arg(*pc, int));
	else if ((*pf)->size_spec == 3)
		(*pf)->text = ft_itoa_base(va_arg(*pc, long));
	else if ((*pf)->size_spec == 4)
		(*pf)->text = ft_itoa_base(va_arg(*pc, long long));
	else if ((*pf)->size_spec == 5)
		(*pf)->text = ft_itoa_base(va_arg(*pc, intmax_t));
	else if ((*pf)->size_spec == 6)
		(*pf)->text = ft_itoa_base(va_arg(*pc, ssize_t));
}

void	ft_get_arg(t_printf **pf, va_list *pc)
{
	(ft_iscl_group_1((*pf)->cl)) ? ft_group1(pf, pc) : 0;
	
		 






}

void	ft_making_move(t_printf **pf, va_list *pc)
{
	










}
