/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_basel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:10:40 by asepulve          #+#    #+#             */
/*   Updated: 2022/11/19 17:07:38 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_basel(long long nbr, char *base)
{
	if (nbr < 0)
		return (ft_putchar('-') + ft_putnbr_basel(nbr * -1, base));
	if (nbr < (int)ft_strlen(base))
		return (ft_putchar(base[nbr]));
	else
		return (ft_putnbr_basel(nbr / ft_strlen(base), base)
			+ ft_putchar(base[nbr % ft_strlen(base)]));
	return (0);
}
