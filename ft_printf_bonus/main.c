/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:03:04 by asepulve          #+#    #+#             */
/*   Updated: 2023/11/30 23:22:59 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			if (flags->str)
				free(flags->str);
			if (flags)
				free(flags);
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
	// ft_printf("%s\n", "2147483647");
	// ft_printf("%p\n", argv);
	ft_printf("%i\n", 10);
	// ft_printf("asdasdfasdf %d\n", -2147483648);
    return (0);
}