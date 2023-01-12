/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:17:51 by asepulve          #+#    #+#             */
/*   Updated: 2022/11/19 00:18:33 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long long	ft_strlen(const char *str)
{
	long long	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
