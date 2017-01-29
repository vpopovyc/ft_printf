/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrmem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 21:56:26 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/29 22:00:37 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_wstrmem(wchar_t *s)
{
	size_t len;

	len = 0;
	while (*s != L'\0')
	{
		len += ft_wstrblen(*s);
		++s;
	}
	return (len);
}
