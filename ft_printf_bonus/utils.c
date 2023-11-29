/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:38:15 by asepulve          #+#    #+#             */
/*   Updated: 2023/11/28 17:39:07 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./ft_printf.h"

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