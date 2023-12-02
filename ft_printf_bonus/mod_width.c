/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:16:24 by asepulve          #+#    #+#             */
/*   Updated: 2023/12/02 18:43:20 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

char    *mod_minus(char *str, t_mod *mod)
{
    char *new;
    int str_len;
    int j;

    str_len = ft_strlen(str);
    j = 0;
    new = ft_calloc(mod->min_width + 1, 1);
    if (!new)
        return (NULL);
    while (j < str_len)
    {
        new[j] = str[j];
        j++;
    }
    while (j < mod->min_width)
        new[j++] = ' ';
    if (str)
        free(str);
    return (new);
}

char    *mod_zero(char *str, t_mod *mod)
{
    char *new;
    int i;
    int j;

    i = ft_strlen(str) - 1;
    j = mod->min_width - 1;
    new = ft_calloc(mod->min_width + 1, 1);
    if (!new)
        return (NULL);
    while (i >= 0)
        new[j--] = str[i--];
    while (j >= 0)
        new[j--] = '0';
    if (str)
        free(str);
    return (new);
}

char    *mod_pad(char *str, t_mod *mod)
{
    char *new;
    int i;
    int j;

    i = ft_strlen(str) - 1;
    j = mod->min_width - 1;
    new = ft_calloc(mod->min_width + 1, 1);
    if (!new)
        return (NULL);
    while (i >= 0)
        new[j--] = str[i--];
    while (j >= 0)
        new[j--] = ' ';
    if (str)
        free(str);
    return (new);
}


char    *mod_width(char *str, t_mod *mod)
{
    if (ft_strlen(str) >= (size_t)mod->min_width)
        return (str);
    if (ft_strchr(mod->flags, '-'))
        str = mod_minus(str, mod);
    else if (mod->flags[0] == '0')
        str = mod_zero(str, mod);
    else
        str = mod_pad(str, mod);
    return (str);
}
