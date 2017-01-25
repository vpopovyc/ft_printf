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

static void		ft_get_arg(t_printf **pf, va_list *pc)
{
	(ft_iscl_group1((*pf)->cl)) ? ft_group1(pf, pc) : 0;
	(ft_iscl_group2((*pf)->cl)) ? ft_group2(pf, pc) : 0;
}

void			ft_making_move(t_printf **pf, va_list *pc)
{
	ft_get_arg(pf, pc);
	(*pf)->nf = 0;
}
