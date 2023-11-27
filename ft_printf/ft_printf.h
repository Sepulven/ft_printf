/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:09:26 by asepulve          #+#    #+#             */
/*   Updated: 2022/11/19 17:07:23 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int			ft_printf(const char *format, ...);
size_t		ft_strlen(const char *str);
size_t		ft_putnbr_basel(long long nbr, char *base);
size_t		ft_putnbrull_basel(unsigned long long nbr, char *base);
size_t		ft_putstr(char *s);
size_t		ft_putchar(char c);

#endif