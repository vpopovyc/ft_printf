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
	char 		*spec;             // Storage for specifier
	int			lspc;              // Lenght of specifier
	int			lnpr;              // Lenght of symbols being printed
	int			min_field;         // Done! look t_min_field.c
	int			presc;             // Done!
	int			size_spec;	       // Done! hh, h, l, ll, j, z
	char		cl;              // Conversion letter
	char		*conv_flag;        // Done! look t_memset_4_spec.c  
}				t_printf;
enum			size_spec               // Done! look t_enum.c
{
	beer, hh, h, l, ll, j, z
};
/* ft_c_spec.c         */
void			ft_s_spec(t_printf **pf, char *sv/*, va_list *pc*/);
/* main thing format.c */
int				ft_printf(char *sv, ...);
/* printf struct  ft_s_printf.c */
void			ft_s_printf_clr(t_printf **pf);
t_printf		*ft_s_printf_new(void);
#endif


/*TO DO 
	*cleaning struct(remember about that)
	think about block system in printf (format + %) && reproduce that feature in ft_s_spec
	you need to test & fix 34 line in ft_s_printf.c (printf can prints not only alphabet in %% conversion)
	>>45>> not isassii && ! is_printf_spec
	and easiest one: end the fucking ft_printf :3;*/
