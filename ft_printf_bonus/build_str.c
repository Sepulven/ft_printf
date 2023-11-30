/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:50:13 by asepulve          #+#    #+#             */
/*   Updated: 2023/11/30 23:19:06 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

char	*pointerconversion(va_list arg)
{
	long long	pointer;
	char		*hex_number;
	char		*address;

	pointer = va_arg(arg, unsigned long long);
	if (pointer == 0)
		return (ft_strdup("(nil)"));
	hex_number = converter(va_arg(arg, unsigned long long), "0123456789abcdef", 16);
	address = ft_strjoin("0x", hex_number);
	if (hex_number)
		free(hex_number);
	return (address);
}

char    *conversion(char convertor, va_list arg )
{
	// if (convertor == 'c')
	// {
		
	// }
	// 	return (ft_strdup(va_arg(arg, char)));
	if (convertor == 's')
		return (ft_strdup(va_arg(arg, char *)));
	if (convertor == 'p')
		return (pointerconversion(arg));
	if (convertor == 'd' || convertor == 'i')
		return (converter(va_arg(arg, int), "0123456789", 10));
	if (convertor == 'u')
		return (converter(va_arg(arg, unsigned int), "0123456789", 10));
	if (convertor == 'x')
		return (converter(va_arg(arg, unsigned int), "0123456789abcdef", 16));
	if (convertor == 'X')
		return (converter(va_arg(arg, unsigned int), "0123456789ABCDEF", 16));
	if (convertor == '%')
		return (ft_strdup("%d"));
	return (0);
}

int		build_str(t_flags *flags, va_list arg)
{
    char    *str;
    size_t  len;

    // Take the value from the arg. then turn it to a string;
    str = conversion(flags->conversion, arg);
    // Apply the specifiers, flags and then writes it;
    len = ft_strlen(str);
    write(1, str, len);
	if (str)
    	free(str);
    return (len);
}