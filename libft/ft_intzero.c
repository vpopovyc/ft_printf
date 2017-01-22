/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 21:29:27 by vpopovyc          #+#    #+#             */
/*   Updated: 2016/12/08 21:29:42 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_intzero(int ar[], int f, size_t n)
{
	size_t	i;

	i = 1;
	ar[0] = f;
	while (i < n)
	{
		ar[i] = 0;
		i++;
	}
}