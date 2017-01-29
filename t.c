/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 13:24:44 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/29 22:02:31 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_test(t_printf **pf)
{
	(*pf)->ws = (char**)malloc(sizeof(char*) * 3);
	*((*pf)->ws) = ft_strdup("lama\n");
	*((*pf)->ws + 1) = ft_strdup("papka\n");
	*((*pf)->ws + 2) = NULL;
//	printf("1: %s\n", *((*pf)->ws));
//	printf("2: %s\n", *((*pf)->ws + 1));
//	printf("3: %s\n", *((*pf)->ws + 2));
//	ft_pspp((*pf)->ws);
}

int		main(void)
{
	setlocale(LC_ALL, "");
	wchar_t *s = L"сукаты";
	size_t i = ft_wstrlen(s);
//	printf("len of ws: %zu\n", i);
//	printf("Bytes: %hhi\n", ft_wstrblen(*s));
	printf("%040.45ls\n", s);
//	printf("%0+#-40ls\n", s);

	size_t      ii;
	ssize_t     tmp;
	size_t		gf;
	t_printf	*pf;

	pf = (t_printf*)malloc(sizeof(t_printf));
	ft_test(&pf);
	gf = 0;
	ii = 0;
	tmp = 5;
	while (s[ii])
	{
		tmp -= ft_wstrblen(s[ii]);
		if (tmp < 0)
			break;
		gf = 5 - tmp;
		++ii;
    }
	printf("n symbols %zu\nn bytes %zu\n", ii, gf); 
	printf("n bytes: %zu\n", ft_wstrmem(s));
	return (0);
}
