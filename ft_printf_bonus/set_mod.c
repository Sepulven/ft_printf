/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:37:31 by asepulve          #+#    #+#             */
/*   Updated: 2023/12/01 12:53:56 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

/*
	Sets the precision and the width.
*/
static int	set_width_precision(t_mod *mod, int i)
{
	char	*c;

	if (ft_isdigit(mod->str[i]))
		mod->min_width = ft_atoi(&mod->str[i]);
	c = ft_strchr(&mod->str[i], '.');
	if (c)
		mod->precision = ft_atoi(&c[1]);
	return (1);
}

/*
	Sets the values for for the flags ['-','+',' ','#','0']
*/
static int	set_flags_values(t_mod *mod)
{
	int		i;

	i = 0;
	mod->flags = ft_strdup("");
	while(mod->str[i] && ft_strchr("-+ #0", mod->str[i]))
	{
		if (mod->str[i] == '-')
			ft_strjoin_free(mod->flags, "-");
		if (mod->str[i] == '+')
			ft_strjoin_free(mod->flags, "+");
		if (mod->str[i] == ' ')
			ft_strjoin_free(mod->flags, " ");
		if (mod->str[i] == '#')
			ft_strjoin_free(mod->flags, "#");
		if (mod->str[i] == '0')
			ft_strjoin_free(mod->flags, "0");
		i++;
	}
	if (mod->str[i])
		set_width_precision(mod, i);
	return (1);
}

/*
	Starts the creation of the s_flags structure.
*/
t_mod	*set_mod(const char *specifier)
{
	t_mod *mod;
	int		i;
	char	*str;
	
	i = 0;
	while (specifier[i] && !ft_strchr("cspdiuxX%", specifier[i]))
		i++;
	mod = ft_calloc(sizeof(t_mod), 1);
	str = ft_calloc(i + 1, 1);
	if (!mod || !str || !specifier[i])
		return (NULL);
	ft_strlcpy(str, specifier, i + 1);
	mod->str = str;
	mod->conversion = specifier[i];
	if (!set_flags_values(mod))
		return (NULL);
	return (mod);
}
