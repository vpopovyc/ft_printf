/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tell_me_flag_baby.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:00:23 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/15 13:50:17 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_get_flag(va_list *pc, char *sv)
{
	if (*sv == 'c')
		ft_putchar((char)va_arg(*pc, int));
	else if (*sv == 'd' || *sv == 'i')
		ft_putnbr(va_arg(*pc, int));
	else if (*sv == 's')
		ft_putstr(va_arg(*pc, char *)); 
}	
