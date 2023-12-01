/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:35:57 by asepulve          #+#    #+#             */
/*   Updated: 2023/12/01 13:54:55 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

char    *mod_plus(char *str, char conversion)
{
    char    *new;

    if (conversion != 'd' && conversion != 'i')
        return (str);
    if (ft_strchr(str, '-'))
        return (str);
    // This may lead to errors if we put the sign at the start of the string.
    new = ft_strjoin_free("+", str, 'r');
    return (new);
}

char    *mod_flags(char *str, t_mod *mod)
{
    int     i;
    char    conversion;

    conversion = mod->conversion;
    i = 0;
    while (mod->flags[i])
    {
        if (mod->flags[i] == '+')
            str = mod_plus(str, conversion);
        // if (mod->flags[i] == '-')
        //     str = mod_minus(str, conversion);
        i++;
    }
    return (str);
}
