/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:15:43 by asepulve          #+#    #+#             */
/*   Updated: 2023/12/03 16:50:10 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"


char    *mod_precision_num(char *str, t_mod *mod)
{
    char *new;
    int i;
    int j;

    i = ft_strlen(str) - 1;
    j = mod->precision - 1;
    if (ft_strchr(str, '-'))
    {
        mod->precision++;
        j++;
    }
    new = ft_calloc(mod->precision + 1, 1);
    if (!new)
        return (NULL);
    while (i >= 0)
        new[j--] = str[i--];
    while (j >= 0)
        new[j--] = '0';
    if ((mod->conversion == 'd' || mod->conversion == 'i')
        && ft_strchr(str, '-'))
        swap_chars(ft_strchr(new, '-'), new);
    if (str)
        free(str);
    return (new);
}

char    *mod_precision(char *str, t_mod *mod)
{
    if (!ft_strchr(mod->flags, '.') || !ft_strchr("sdiuxX", mod->conversion))
        return (str);
    if (mod->conversion == 's')
    {
        if (ft_strlen(str) >= (size_t)mod->precision)
            str[mod->precision] = 0;
    }
    else if (ft_strlen(str) - !!ft_strchr(str, '-') < (size_t)mod->precision)
        str = mod_precision_num(str, mod);
    return (str);
}
