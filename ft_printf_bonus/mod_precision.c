/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:15:43 by asepulve          #+#    #+#             */
/*   Updated: 2023/12/03 15:21:55 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

char    *mod_precision(char *str, t_mod *mod)
{
    if (!ft_strchr("sdiuxX", mod->conversion))
        return (str);
    
    return (str);
}
