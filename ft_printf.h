/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:21:16 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/23 20:42:42 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H
# include "libft/includes/libft.h"

typedef struct	s_printf
{
	char		*ft;
	char 		*spec;
	int			nf;
	int			lspc;
	int			lnpr;
	int			min_field;
	int			presc;
    int			size_spec;
	char		cl;
	char		*conv_flag;
	char		*text;
}				t_printf;
typedef
{
	



}
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
	now, you need to use all data that you saved to involve right output:
		- ok, you get group on conversions, step in to get right ascii output,
			save it into struct, move to prescizion and min_field && count printable chars
	and easiest one: end the fucking ft_printf :3;*/
