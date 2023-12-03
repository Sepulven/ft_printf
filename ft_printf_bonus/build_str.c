/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:50:13 by asepulve          #+#    #+#             */
/*   Updated: 2023/12/03 15:46:02 by asepulve         ###   ########.fr       */
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
	hex_number = converter_ull(pointer, "0123456789abcdef", 16);
	address = ft_strjoin("0x", hex_number);
	if (hex_number)
		free(hex_number);
	return (address);
}

char	*charcase(char c)
{
	char	*str;

	str = ft_calloc(2, 1);
	if (!str)
		return (NULL);
	str[0] = c;
	//Attention, it may lead to errors in the bonus.
	return (str);
}

char	*strcase(char *str)
{
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

char    *conversion(char convertor, va_list arg )
{
	if (convertor == 'c')
		return(charcase(va_arg(arg, int)));
	if (convertor == 's')
		return (strcase(va_arg(arg, char *)));
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
		return (ft_strdup("%"));
	return (0);
}

int		build_str(t_mod *mod, va_list arg)
{
    char    *str;
    size_t  len;
	
	len = 0;
    str = conversion(mod->conversion, arg);
	if (mod->conversion == 'c' && ft_strlen(str) == 0)
		len++;
	str = mod_flags(str, mod);
	str = mod_width(str, mod);
	str = mod_precision(str, mod);
	len += ft_strlen(&str[len]);
	write(1, str, len);
	if (str)
    	free(str);
    return (len);
}

