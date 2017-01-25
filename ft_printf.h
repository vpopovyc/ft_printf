/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:21:16 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/25 21:56:03 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H
# include "libft/includes/libft.h"

typedef struct	s_printf
{
	size_t		piska;
	char		*ft;
	char 		*spec;
	int			nf;
	int			lspc;
	int			lnpr;                        // Toje chto i piska
	int			min_field;
	int			presc;
    char		sm;                             // Size modifier
	char		cl;                             // Conversion letter
	char		*cf;                            // Conversion flag
	/*  making_move.c                 */
	char		*tx;
	int			ltx;
	char		*prefix;                   // Prescision
	char		*field;
	char		sign;                      // for + or ' ' or 0
	char		hex;                       // for x or  X
	char		base;                      // For unsigned conversions
}				t_printf;
typedef enum	size_spec
{
	beer, hh, h, l, ll, j, z
}               sequence;
void			ft_sosi_pisku(t_printf **pf);
/* main thing format.c */
int				ft_printf(char *sv, ...);
/* printf struct  ft_s_printf.c */
void			ft_s_printf_clr(t_printf **pf);
t_printf		*ft_s_printf_new(void);
/* making move */
void			ft_group_output(t_printf **pf);
void			ft_group_prefix(t_printf **pf);
void			ft_group_field(t_printf **pf);
void			ft_making_move(t_printf **pf, va_list *pc);
/* group1.c */
void    		ft_group1(t_printf **pf, va_list *pc);
void			ft_group2(t_printf **pf, va_list *pc);
#endif


/*TO DO 
	now, you need to use all data that you saved to involve right output:
		- ok, group1(d, D, i) – DONE!
		- ok, (o, O, u, U, x, X) – DONE!
		- now, (s, c, S, C, p) - and mandatory part is over
		- look how u write format string(it's not so good, obviously, it's very bad – like shit)
		- !IMPORTANT! you need to CHECK - CHECK your ft that clears yours struct
		- NICEEEEEEEEEEEE!!@#!@#@!
	and easiest one: end the fucking ft_printf :3;*/
