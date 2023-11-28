/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:03:04 by asepulve          #+#    #+#             */
/*   Updated: 2023/11/28 00:08:05 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

size_t	ft_putchar(char c)
{
	return ((size_t)write(1, &c, 1));
}

t_flags	*get_flags(const char *conversion)
{
	t_flags *flags;
	int		i;
	char	*str;

	i = 0;
	while (!ft_strchr("cspdiuxX%", conversion[i]))
		i++;
	str = ft_calloc(i + 1, 1);
	flags = ft_calloc(sizeof(t_flags *), 1);
	if (!flags || !str || !conversion[i])
		return (NULL);
	ft_strlcat(str, conversion, i + 1);
	flags->str = str;
	flags->conversion = conversion[i];
	printf("[%s] [%c]\n", flags->str, flags->conversion);
	return (flags);
}



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
			flags = get_flags(&format[i+1]);
            if (!flags) // if it is only the % sign with nothing in front of it.
                printf("no flags\n");
            //str = create_str(flags, value); // value is the current position of the pointer
            i += ft_strlen(flags->str) + 1; // Jumps the amount of char. the size of the flags + the conversion character
            //write(1, &str, ft_strlen(str));
		}
		else
			i++;
		// else
		// 	len += ft_putchar(format[i++]);
	}
	va_end(arg_prt);
	return (len);
}

int main(int argc, char *argv[])
{
    (void)argc;
	(void)argv;
	ft_printf("%05d");
	ft_printf("%0.10x\n");
	ft_printf("% 10001X\n");
	ft_printf("% 0p\n");
    return (0);
}