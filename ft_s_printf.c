/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 17:25:16 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/19 21:06:15 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     	 ft_sizespc(int c)
{
	if (c == 'j' || c == 'l' || c == 'h' || c == 'z')
		return (1);
	return (0);
}

void		ft_lstclr(t_printf **pf)
{
	ft_strclr((*pf)->spec);
	(*pf)->lspc = 0;
}

void		ft_s_spec(t_printf **pf, char *sv/*, va_list *pc*/)
{
	ft_lstclr(pf);                                                           // Clear struct, before using it
	while (*(++sv))
	{
		++(*pf)->lspc;
		if (ft_isalpha(*sv) && !ft_sizespc(*sv))                             // If conversion letter - end cycle
			break;
	}
	(*pf)->spec = ft_strnfjoin((*pf)->spec, sv - (*pf)->lspc, (*pf)->lspc); //Write specifier into struct 
	printf("Specificator after: %s\n", (*pf)->spec);
	//ft_po_polochkam_sqa(pf);
}

t_printf	*ft_s_printf_new(void)
{
	t_printf	*new;

	new = (t_printf*)malloc(sizeof(t_printf));
	new->lspc = 0;
	new->lnpr = 0;
	new->spec = ft_strnew(0);
	new->conv_flag = ft_strnew(5);                                           // You did mistake here
	return (new);
}
