/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:20:13 by asepulve          #+#    #+#             */
/*   Updated: 2023/12/01 12:08:57 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pointerconversion(va_list arg)
{
	long long	pointer;

	pointer = va_arg(arg, unsigned long long);
	if (pointer == 0)
		return (ft_putstr("(nil)"));
	else
		return (ft_putstr("0x")
			+ ft_putnbrull_basel(pointer, "0123456789abcdef"));
	return (0);
}

size_t	conversion(char convertor, va_list arg )
{
	if (convertor == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (convertor == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (convertor == 'p')
		return (pointerconversion(arg));
	if (convertor == 'd' || convertor == 'i')
		return (ft_putnbr_basel(va_arg(arg, int), "0123456789"));
	if (convertor == 'u')
		return (ft_putnbr_basel(va_arg(arg, unsigned int), "0123456789"));
	if (convertor == 'x')
		return (ft_putnbr_basel(va_arg(arg, unsigned int), "0123456789abcdef"));
	if (convertor == 'X')
		return (ft_putnbr_basel(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	if (convertor == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_prt;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(arg_prt, format);
	while (format[i])
	{
		if (format[i] == '%')
		{	
			len = len + conversion(format[i + 1], arg_prt);
			i += 2;
		}
		else
			len += ft_putchar(format[i++]);
	}
	va_end(arg_prt);
	return (len);
}
