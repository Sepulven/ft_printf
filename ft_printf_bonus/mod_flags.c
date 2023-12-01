/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:35:57 by asepulve          #+#    #+#             */
/*   Updated: 2023/12/01 13:22:08 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

char    *mod_flags(char *str, t_mod *mod)
{
    int i;

    i = 0;
    (void)mod;
    while (mod->flags[i])
    {
        // if (mod->flags[i] == '+')
            
        i++;
    }
    return (str);
}
