/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:38:15 by asepulve          #+#    #+#             */
/*   Updated: 2023/12/01 13:57:02 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./ft_printf.h"

size_t	ft_putchar(char c)
{
	return ((size_t)write(1, &c, 1));
}

char	*ft_strjoin_free(char *s1, char *s2, char c)
{
	char	*joint;

	if (!s1 || !s2)
		return (NULL);
	joint = ft_strjoin(s1, s2);
	if ((c == 'l' && s1) || (c == 'b' && s1) )
		free(s1);
	if ((c == 'r' && s2) || (c == 'b' && s2))
		free(s2);
	return (joint);
}

void	print_mod(t_mod *mod)
{

	printf("str: [%s] conversion:[%c]\n", mod->str, mod->conversion);
	printf("flags: %s\n precision: %d\n min_width: %d\n ", mod->flags, mod->precision, mod->min_width);
	printf("\n-----------------------{{{}}}-----------------------\n");
}