/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:21:16 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/19 21:06:35 by vpopovyc         ###   ########.fr       */
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
	char		*conv_flag;        // Done! look t_memset_4_spec.c  
}				t_printf;
enum			size_spec               // Done! look t_enum.c
{
	beer, hh, h, l, ll, j, z
};
int				ft_sizespc(int c);
void			ft_s_spec(t_printf **pf, char *sv/*, va_list *pc*/);
int				ft_printf(char *sv, ...);
void			ft_get_flag(va_list *pc, char *sv);
t_printf		*ft_s_printf_new(void);
#endif


/*TO DO 
	*cleaning struct(remember about that)
	think about block system in printf (format + %) && reproduce that feature in ft_s_spec
	you need to test & fix 34 line in ft_s_printf.c (printf can prints not only alphabet in %% conversion)
	and easiest one: end the fucking ft_printf :3;*/







