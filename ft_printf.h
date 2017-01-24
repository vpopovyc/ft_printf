/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:21:16 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/24 20:46:52 by vpopovyc         ###   ########.fr       */
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
	/*  making_move.c                 */
	char		*text;
	int			ltxt;
	char		*prefix;                   // Prescision
	char		*field;
	char		sign;
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
/* making move */
void			ft_making_move(t_printf **pf, va_list *pc);
/* group1.c */
void    		ft_group1(t_printf **pf, va_list *pc);
#endif


/*TO DO 
	now, you need to use all data that you saved to involve right output:
		- ok, group1(d, D, i) – DONE!
		- think about how to make next group(o, O, u, U, x, X)
		- !IMPORTANT! you need to check your ft that clears yours struct
		- NICEEEEEEEEEEEE!!@#!@#@!
	and easiest one: end the fucking ft_printf :3;*/
