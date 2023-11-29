/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ull_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:10:59 by asepulve          #+#    #+#             */
/*   Updated: 2023/11/28 17:49:44 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

/*
    Print the biggest ingeter value possible, 
    if we have a negative value it must me treated before.
*/

static size_t	getlength(ull_t n)
{
	size_t	length;

	length = 1;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

static char	*convert(char *str, size_t sign, int n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 1;
	while (i++ < getlength(n) - 1)
		len = len * 10;
	i = 0;
	if (sign)
		str[i++] = '-';
	while (len > 0)
	{
		str[i++] = n / (len) + 48;
		n = n % (len);
		len = len / 10;
	}
	return (str);
}


char	*ull_converter(ull_t value)
{
	size_t	sign;
	char	*str;

	str = ft_calloc(getlength(value) + sign + 1, 1);
	if (!str)
		return (NULL);
	return (convert(str, sign, value));
}
