/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:16:24 by asepulve          #+#    #+#             */
/*   Updated: 2023/12/03 15:47:03 by asepulve         ###   ########.fr       */
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
    if (str_len == 0 && mod->conversion == 'c') // Edge Case
        new[0] = 0;
    if (str)
        free(str);
    return (new);
}

void swap_chars(char *s1, char *s2)
{
    char    temp;

    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
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
    if ((mod->conversion == 'd' || mod->conversion == 'i')
        && ft_strchr(str, '-'))
        swap_chars(ft_strchr(new, '-'), new);
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
    if ((mod->conversion == 'c' && ft_strlen(str) == 0)
        && ft_strlen(str) + 1 >= (size_t)mod->min_width)
            return (str);
    if (ft_strchr(mod->flags, '-'))
        str = mod_minus(str, mod);
    else if (mod->flags[0] == '0')
        str = mod_zero(str, mod);
    else
        str = mod_pad(str, mod);
    return (str);
}
