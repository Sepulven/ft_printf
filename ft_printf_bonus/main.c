/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:03:04 by asepulve          #+#    #+#             */
/*   Updated: 2023/11/28 17:04:38 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

size_t	ft_putchar(char c)
{
	return ((size_t)write(1, &c, 1));
}

void	print_flags(t_flags *flags)
{
	int	*arr;

	arr = (int *)&flags->minus;
	(void)arr;
	printf("str: [%s] conversion:[%c]\n", flags->str, flags->conversion);
	printf("\
	minus: %d \n \
	zero: %d \n \
	precision: %d \n \
	min_width: %d \n \
	hash: %d \n \
	plus: %d \n \
	space: %d \n \
	", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6]);
	printf("\n-----------------------{{{}}}-----------------------\n");
}

int	set_width_precision(t_flags *flags, int i)
{
	char	*c;

	if (ft_isdigit(flags->str[i]))
		flags->min_width = ft_atoi(&flags->str[i]);
	c = ft_strchr(&flags->str[i], '.');
	if (c)
		flags->precision = ft_atoi(&c[1]);
	return (1);
}

int	set_flags_values(t_flags *flags)
{
	int		i;
	char	c;
	i = 0;
	c = flags->str[i];
	while(ft_strchr("-+ #0", c))
	{
		if (c == '-')
			flags->minus = 1;
		if (c == '+')
			flags->plus = 1;
		if (c == ' ')
			flags->space = 1;
		if (c == '#')
			flags->hash = 1;
		if (c == '0')
			flags->zero = 1;
		i++;
		c = flags->str[i];
	}
	if (flags->str[i])
		set_width_precision(flags, i);
	return (1);
}

t_flags	*set_flags(const char *specifier)
{
	t_flags *flags;
	int		i;
	char	*str;
	
	i = 0;
	while (!ft_strchr("cspdiuxX%", specifier[i]))
		i++;
	flags = ft_calloc(sizeof(t_flags), 1);
	str = ft_calloc(i + 1, 1);
	if (!flags || !str || !specifier[i])
		return (NULL);
	ft_strlcpy(str, specifier, i + 1);
	flags->str = str;
	flags->conversion = specifier[i];
	if (!set_flags_values(flags))
		return (NULL);
	print_flags(flags);
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
			flags = set_flags(&format[i+1]);
            if (!flags) // if it is only the % sign with nothing in front of it.
                printf("no flags\n");
            //str = create_str(flags, value); // value is the current position of the pointer
            i += ft_strlen(flags->str) + 2; // Jumps the amount of char. the size of the flags + the conversion character
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
	ft_printf("%05d % 0199.2c %-200.d");
	ft_printf("%0.10x %07% \n");
	ft_printf("% 10001X\n");
	ft_printf("% 0p\n");
	ft_printf("% 0p %% \n");


    return (0);	
}