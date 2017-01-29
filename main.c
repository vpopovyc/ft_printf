/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:39:36 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/29 21:43:30 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
    setlocale(LC_ALL, "");
    wchar_t *s = L"™™сукаты";
	printf("Bytes returned: %i\n", ft_printf("rama %ls\n", s));
    printf("Bytes returned: %i\n",    printf("rama %ls\n", s));

	return (0);
}
