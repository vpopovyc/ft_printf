/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprintf_spec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 18:20:04 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/21 18:20:48 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_isprintf_spec(int c)
{
	if (ft_isdigit(c))
		return (1);
	else if (c == '%' || c == '+' || c == ' ' || c == '-')
		return (1);
	else if (c == 'j' || c == 'l' || c == 'h' || c == 'z')
		return (1);
	return (0);
}
