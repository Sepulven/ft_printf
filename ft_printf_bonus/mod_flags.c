/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:35:57 by asepulve          #+#    #+#             */
/*   Updated: 2023/12/03 19:16:06 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

char	*mod_plus(char *str, char c)
{
	char	*new;

	if (c != 'd' && c != 'i')
		return (str);
	if (str[0] == '-')
		return (str);
	new = ft_strjoin_free("+", str, 'r');
	return (new);
}

char	*mod_space(char *str, char c)
{
	char	*new;

	if (c != 'd' && c != 'i' && c != 's')
		return (str);
	if ((str[0] == '-') || ft_strchr(str, '-') || 
		(str[0] == '+') || !str[0] || (ft_isdigit(str[0]) && c == 's'))
		return (str);
	new = ft_strjoin_free(" ", str, 'r');
	return (new);
}

char	*mod_hash(char *str, char c)
{
	char	*new;

	if ((c != 'x' && c != 'X') || !ft_strncmp(str, "0", ft_strlen(str)))
		return (str);
	if (c == 'x')
		new = ft_strjoin_free("0x", str, 'r');
	if (c == 'X')
		new = ft_strjoin_free("0X", str, 'r');
	return (new);
}

char	*mod_flags(char *str, t_mod *mod)
{
	int		i;
	char	conversion;

	conversion = mod->conversion;
	i = 0;
	while (mod->flags[i])
	{
		if (mod->flags[i] == '+')
			str = mod_plus(str, conversion);
		if (mod->flags[i] == ' ')
			str = mod_space(str, conversion);
		if (mod->flags[i] == '#')
			str = mod_hash(str, conversion);
		i++;
	}
	return (str);
}
