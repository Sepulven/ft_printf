/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:03:04 by asepulve          #+#    #+#             */
/*   Updated: 2023/12/01 16:30:07 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg_prt;
    t_mod *mod;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(arg_prt, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			mod = set_mod(&format[i+1]);
            if (!mod) // if it is only the % sign with nothing in front of it.
                printf("no mod\n");
			len += build_str(mod, arg_prt);
            i += ft_strlen(mod->str) + 2; // Jumps the amount of char. the size of the mod + the conversion character
			if (mod->str)
				free(mod->str);
			if (mod->flags)
				free(mod->flags);
			if (mod)
				free(mod);
		}
		else
			len += ft_putchar(format[i++]);
	}
	va_end(arg_prt);
	return (len);
}

/*
int	main(void)
{
	// int	len;

	printf("%#x\n", 0);
	// printf(" %#x ", -1);
	// printf(" %#x ", 1);
	// printf(" %#x ", 9);
	// printf(" %#x ", 10);
	// printf(" %#x ", 11);
	// printf(" %#x ", 15);
	// printf(" %#x ", 16);
	// printf(" %#x ", 17);
	// printf(" %#x ", 99);
	// printf(" %#x ", 100);
	// printf(" %#x ", 101);
	// printf(" %#x ", -9);
	// printf(" %#x ", -10);
	// printf(" %#x ", -11);
	// printf(" %#x ", -14);
	// printf(" %#x ", -15);
	// printf(" %#x ", -16);
	// printf(" %#x ", -99);
	// printf(" %#x ", -100);
	// printf(" %#x ", -101);

	// ft_printf("%#x\n", 0);
	// ft_printf(" %#x ", -1);
	// ft_printf(" %#x ", 1);
	// ft_printf(" %#x ", 9);
	// ft_printf(" %#x ", 10);
	// ft_printf(" %#x ", 11);
	// ft_printf(" %#x ", 15);
	// ft_printf(" %#x ", 16);
	// ft_printf(" %#x ", 17);
	// ft_printf(" %#x ", 99);
	// ft_printf(" %#x ", 100);
	// ft_printf(" %#x ", 101);
	// ft_printf(" %#x ", -9);
	// ft_printf(" %#x ", -10);
	// ft_printf(" %#x ", -11);
	// ft_printf(" %#x ", -14);
	// ft_printf(" %#x ", -15);
	// ft_printf(" %#x ", -16);
	// ft_printf(" %#x ", -99);
	// ft_printf(" %#x ", -100);
	// ft_printf(" %#x ", -101);

	// printf("\n");
	// printf("%d\n", len);
	
	// printf("------------- 2 ---------------\n");
	// ft_printf("[% s]\n", "-");
	// printf("[% s]\n", "-");

	return (0);
}
*/