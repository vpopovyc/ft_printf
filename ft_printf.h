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
	char		*ft;
	char 		*spec;
	int			nf;
	int			lspc;
    int         mnpr;                        // max numbers being printed
	int 		lnpr;                        // output of numbers being printed
	int			min_field;
	int			presc;
    char		sm;                             // Size modifier
	char		cl;                             // Conversion letter
	char		*cf;                            // Conversion flag
	/*  making_move.c                 */
	char		*tx;                     // For group 1-2
	int			ltx;
	char		prefix;                  // Prescision
    int         prx;
    char		field;
    int         fld;
    char		sign;                      // for + or ' ' or 0
	char		hex;                       // for x or  X
	char		base;                      // For unsigned conversions
    /* bit party */
    int         c;                        // For all conversions exept s, ls
    char        **ws;                     // For ls
    wchar_t     *wc;
}				t_printf;
typedef enum	size_spec
{
	beer, hh, h, l, ll, j, z
}               sequence;
/* format.c */
void            ft_s_spec(t_printf **pf, char *sv);
int				ft_printf(char *sv, ...);
/* ft_s_printf.c */
void			ft_s_printf_clr(t_printf **pf);
t_printf		*ft_s_printf_new(void);
/* making_move.c */
void            ft_making_move(t_printf **pf, va_list *pc, char *sv);
/* group_onetwo.c */
void    		ft_group1(t_printf **pf, va_list *pc);
void			ft_group2(t_printf **pf, va_list *pc);
void            ft_group3(t_printf **pf, va_list *pc);
/* group_united.c */
size_t          ft_check(t_printf **pf);
void			ft_group_output(t_printf **pf);
void			ft_group_prefix(t_printf **pf);
void			ft_group_field(t_printf **pf);
#endif


/*TO DO 
	now, you need to use all data that you saved to involve right output:
		- ok, group1(d, D, i) – DONE!
		- ok, (o, O, u, U, x, X) – DONE!
		- done, (s, c, S, C)
		- TEST (s, c, S, C)
		- !IMPORTANT! ft_puppies_killa
        - Dont forget about new fts in libft
        - NICEEEEEEEEEEEE!!@#!@#@!
	and easiest one: end the fucking ft_printf :3;*/
