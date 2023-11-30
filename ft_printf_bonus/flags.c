/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:37:31 by asepulve          #+#    #+#             */
/*   Updated: 2023/11/30 23:17:47 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

/*
	Sets the precision and the width.
*/
static int	set_width_precision(t_flags *flags, int i)
{
	char	*c;

	if (ft_isdigit(flags->str[i]))
		flags->min_width = ft_atoi(&flags->str[i]);
	c = ft_strchr(&flags->str[i], '.');
	if (c)
		flags->precision = ft_atoi(&c[1]);
	return (1);
}

/*
	Sets the values for for the flags ['-','+',' ','#','0']
*/
static int	set_flags_values(t_flags *flags)
{
	int		i;

	i = 0;
	while(flags->str[i] && ft_strchr("-+ #0", flags->str[i]))
	{
		if (flags->str[i] == '-')
			flags->minus = 1;
		if (flags->str[i] == '+')
			flags->plus = 1;
		if (flags->str[i] == ' ')
			flags->space = 1;
		if (flags->str[i] == '#')
			flags->hash = 1;
		if (flags->str[i] == '0')
			flags->zero = 1;
		i++;
	}
	if (flags->str[i])
		set_width_precision(flags, i);
	return (1);
}

/*
	Starts the creation of the s_flags structure.
*/
t_flags	*set_flags(const char *specifier)
{
	t_flags *flags;
	int		i;
	char	*str;
	
	i = 0;
	while (specifier[i] && !ft_strchr("cspdiuxX%", specifier[i]))
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
	return (flags);
}
