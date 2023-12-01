/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:03:04 by asepulve          #+#    #+#             */
/*   Updated: 2023/12/01 14:00:33 by asepulve         ###   ########.fr       */
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

// int	main(void)
// {
// 	// ft_printf("%p\n", -1);
// 	ft_printf("%+d\n", 10);
// 	// printf("%p\n", (void *) -1);
// 	printf("%+d\n", 10);
// 	return (0);
// }