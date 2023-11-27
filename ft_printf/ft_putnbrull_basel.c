/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrull_basel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:06:30 by asepulve          #+#    #+#             */
/*   Updated: 2022/11/19 17:12:13 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbrull_basel(unsigned long long nbr, char *base)
{
	if (nbr < (unsigned long long)ft_strlen(base))
		return (ft_putchar(base[nbr]));
	else
		return (ft_putnbrull_basel(nbr / ft_strlen(base), base)
			+ ft_putchar(base[nbr % ft_strlen(base)]));
	return (0);
}
