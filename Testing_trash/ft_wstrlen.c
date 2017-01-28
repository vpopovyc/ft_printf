/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:37:32 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/28 17:54:48 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


size_t		ft_wstrlen(wchar_t *s)
{
	size_t len;

	len = 0;
	while(*s != L'\0')
	{
		++len;
		++s;
	}
	return (len);
}

int		main(void)
{
	setlocale(LC_ALL, "");
	wchar_t *s = L"™¡™";

	printf("len: %zu\n, sizeof %zu\n", ft_wstrlen(s), sizeof(s + 1));
	return (0);
}
