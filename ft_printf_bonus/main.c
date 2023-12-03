/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:03:04 by asepulve          #+#    #+#             */
/*   Updated: 2023/12/03 15:00:16 by asepulve         ###   ########.fr       */
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


int	main(void)
{
	int len1, len2;
	
	len1 = printf("[%-3c]", 0);
	printf("\nlen1-printf = %d\n", len1);
	printf("\n---------------------\\---------------------\n");
	len2 = ft_printf("[%-3c]", 0);
	printf("\nlen1-ft_printf = %d\n", len1);
	if (len1 != len2)
		printf("here\n");
	return (0);
}
