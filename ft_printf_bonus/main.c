/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:03:04 by asepulve          #+#    #+#             */
/*   Updated: 2023/11/28 17:52:15 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	arg_prt;
    t_flags *flags;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(arg_prt, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			flags = set_flags(&format[i+1]);
            if (!flags) // if it is only the % sign with nothing in front of it.
                printf("no flags\n");
			len += build_str(flags, arg_prt);
            i += ft_strlen(flags->str) + 2; // Jumps the amount of char. the size of the flags + the conversion character
		}
		else
			len += ft_putchar(format[i++]);
	}
	va_end(arg_prt);
	return (len);
}

int main(int argc, char *argv[])
{
    (void)argc;
	(void)argv;
	ft_printf("%05d % 0199.2c %-200.d");
	ft_printf("%0.10x %07% \n");
	ft_printf("% 10001X\n");
	ft_printf("% 0p\n");
	ft_printf("% 0p %% \n");

    return (0);	
}