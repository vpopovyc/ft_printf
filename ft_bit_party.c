/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_party.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:28:41 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/01/28 17:37:09 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void         ft_group_other_sign(t_printf **pf) /* for all mistake conversions */
{
    (*pf)->ltx = 1;
    (*pf)->hex = 42;
}

static void         ft_string_sign(t_printf **pf)
{
    *((*pf)->tx + (*pf)->presc) = '\0';
    (*pf)->ltx = (int)ft_strlen((*pf)->tx);
    (*pf)->hex = 42;
}

static char         *ft_after_party(wchar_t c)
{
    unsigned char   *data;
    
    data = (unsigned char*)malloc(sizeof(data) * 5);
    data = (unsigned char*)ft_uct8(c, data, ft_wstrblen(c));
    return ((char*)data);
}

static void         ft_bit_party(t_printf **pf, wchar_t *s) /* wchar_t * s – string of wide chars */
{
    int         i;
    int         tmp;
    
    i = 0;
    tmp = ((*pf)->presc == -1) ? (int)ft_wstrmem(s) : ((*pf)->presc);
    while (s[i])
    {
        tmp -= ft_wstrblen(s[i]);
        if (tmp < 0)
            break;
        (*pf)->ltx = (*pf)->presc - tmp;
        ++i;
    }
    (*pf)->ws = (char**)malloc(sizeof(char*) * i + 1);
    *((*pf)->ws + i) = NULL;
    while (--i >= 0)
        *((*pf)->ws + i) = ft_after_party(s[i]);
    (*pf)->hex = 42;
    ((*pf)->presc == -1) ? (*pf)->ltx = (int)ft_wstrmem(s) : 0;
}


void                ft_group3(t_printf **pf, va_list *pc)
{
    if ((*pf)->cl == 's' && (*pf)->sm == 3)
    {
        (*pf)->wc = va_arg(*pc, wchar_t *);
        ft_bit_party(pf, (*pf)->wc);
    }
    else if ((*pf)->cl == 's')
    {
        (*pf)->tx = va_arg(*pc, char *);
        ft_string_sign(pf);
    }
    else
    {
        if ((*pf)->cl == 'c')
            (*pf)->c = va_arg(*pc, int);
        else
            (*pf)->c = (*pf)->cl;
        ft_group_other_sign(pf);
    }
    (*pf)->presc = -1;
    ft_group_field(pf);
}
