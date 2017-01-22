/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:21:16 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/21 21:04:01 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H
# include "libft/includes/libft.h"

typedef struct	s_printf
{
	char		*ft;
	int			nf;
	char 		*spec;
	int			lspc;
	int			lnpr;
	int			min_field;
	int			presc;
    int			size_spec;
	char		cl;
	char		*conv_flag;
}				t_printf;
typedef enum	size_spec
{
	beer, hh, h, l, ll, j, z
}               sequence;
/* main thing format.c */
int				ft_printf(char *sv, ...);
/* printf struct  ft_s_printf.c */
void			ft_s_printf_clr(t_printf **pf);
t_printf		*ft_s_printf_new(void);
#endif


/*TO DO 
	now, you need to use all data that you saved to involve right output
 
	and easiest one: end the fucking ft_printf :3;*/
