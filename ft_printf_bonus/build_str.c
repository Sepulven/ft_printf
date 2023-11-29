/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:50:13 by asepulve          #+#    #+#             */
/*   Updated: 2023/11/28 18:57:16 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

char    *conversion(char convertor, va_list arg )
{
	if (convertor == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (convertor == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (convertor == 'p')
		return (pointerconversion(arg));
	if (convertor == 'd' || convertor == 'i')
		return (ft_putnbr_basel(va_arg(arg, int), DECIMAL));
	if (convertor == 'u')
		return (ft_putnbr_basel(va_arg(arg, unsigned int), DECIMAL));
	if (convertor == 'x')
		return (ft_putnbr_basel(va_arg(arg, unsigned int), HEX_SMALL));
	if (convertor == 'X')
		return (ft_putnbr_basel(va_arg(arg, unsigned int), HEX_UPPER));
	if (convertor == '%')
		return (ft_putchar('%'));
	return (0);
}

char    *build_str(t_flags *flags, va_list arg)
{
    char    *str;
    size_t  len;

    // Take the value from the arg. then turn it to a string;
    str = conversion(flags->conversion, arg);


    // Apply the specifiers, flags and then writes it;
    len = ft_strlen(str);
    write(1, str, len);
    free(str);
    return (len);
}