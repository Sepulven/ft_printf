/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:03:04 by asepulve          #+#    #+#             */
/*   Updated: 2023/11/27 22:52:13 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg_prt;
	int		i;
	int		len;
    t_flags *flags;

	len = 0;
	i = 0;
	va_start(arg_prt, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			*flags = get_flags();
            if (!flags) // if it is only the % sign with nothing in front of it.
                // do something
            str = create_str(flags, value); // value is the current position of the pointer
            i += ft_strlen(flags.str) + 1; // Jumps the amount of char. the size of the flags + the conversion character
            write(1, &str, ft_strlen(str));
		}
		else
			len += ft_putchar(format[i++]);
	}
	va_end(arg_prt);
	return (len);
}

int main(int argc, char *argv[])
{
    
    return (0);
}