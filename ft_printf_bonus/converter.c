/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:10:59 by asepulve          #+#    #+#             */
/*   Updated: 2023/12/03 19:22:37 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	get_length(long long n, int base_length)
{
	int	length;

	length = 1;
	if (n < 0)
		n *= -1;
	while (n > base_length - 1)
	{
		n = n / base_length;
		length++;
	}
	return (length);
}

char	*converter(long long n, const char *base, int base_len)
{
	int		i;
	char	*str;
	int		n_len;

	n_len = get_length(n, base_len);
	str = ft_calloc(n_len + 1 + (n < 0), 1);
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		n *= -1;
		str[i++] = '-';
	}
	i = n_len + (str[0] == '-');
	while (i > 0 + (str[0] == '-'))
	{
		str[i - 1] = base[n % base_len];
		n = n / base_len;
		i--;
	}
	return (str);
}

static int	get_length_ull(t_ull n, int base_length)
{
	int	length;

	length = 1;
	while (n > (t_ull)base_length - 1)
	{
		n = n / base_length;
		length++;
	}
	return (length);
}

char	*converter_ull(unsigned long long n, const char *base, int base_len)
{
	int		i;
	char	*str;
	int		n_len;

	n_len = get_length_ull(n, base_len);
	str = ft_calloc(n_len + 1, 1);
	if (!str)
		return (NULL);
	i = n_len;
	while (i > 0)
	{
		str[i - 1] = base[n % base_len];
		n = n / base_len;
		i--;
	}
	return (str);
}
