/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:03:36 by asepulve          #+#    #+#             */
/*   Updated: 2023/12/03 18:50:37 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len_s;
	char	*str;

	i = 0;
	len_s = ft_strlen(s);
	str = (char *)malloc(len_s + 1);
	if (!str)
		return (NULL);
	while (i < len_s)
	{
		str[i] = (char)s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
