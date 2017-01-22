/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 17:25:16 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/21 20:37:08 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_s_printf_clr(t_printf **pf)
{
	(*pf)->cl = 0;
	(*pf)->lspc = 0;
	(*pf)->presc = 0;
	(*pf)->min_field = 0;
	(*pf)->size_spec = 0;
	ft_strclr((*pf)->ft);
	ft_strclr((*pf)->spec);
	ft_memset((*pf)->conv_flag, '*', 5);
}

t_printf	*ft_s_printf_new(void)
{
	t_printf	*new;

	new = (t_printf*)malloc(sizeof(t_printf));
	new->cl = 0;
	new->nf = 0;
	new->lspc = 0;
	new->lnpr = 0;
	new->size_spec = 0;
	new->ft = ft_strnew(0);
	new->spec = ft_strnew(0);
	new->conv_flag = ft_strnew(5);
	ft_memset(new->conv_flag, '*', 5);
	return (new);
}
