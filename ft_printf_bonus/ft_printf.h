/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:03:27 by asepulve          #+#    #+#             */
/*   Updated: 2023/12/03 19:23:03 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 1

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


// %[$][flags][width][.precision][length modifier] order
typedef struct s_mod
{
	char	*str;
	char	*flags;
	int		precision;
	int		min_width;
	char	conversion;
}	t_mod;

typedef unsigned long long	t_ull;

/*main.c*/
int		ft_printf(const char *format, ...);

/*utils.c*/
size_t	ft_putchar(char c);
char	*ft_strjoin_free(char *s1, char *s2, char c);

/*set_mod.c*/
t_mod	*set_mod(const char *specifier);

/*converter.c*/
char	*converter(long long n, const char *base, int base_len);
char	*converter_ull(t_ull n, const char *base, int base_len);

/*build_str.c*/
int		build_str(t_mod *flags, va_list arg);

/*mod_flags.c*/
char	*mod_flags(char *str, t_mod *mod);

/*mod_width.c*/
void	swap_chars(char *s1, char *s2);
char	*mod_zero(char *str, t_mod *mod);
char	*mod_width(char *str, t_mod *mod);

/*mod_precision.c*/
char	*mod_precision(char *str, t_mod *mod);

/*ft_strjoin.c*/
char	*ft_strjoin(char const *s1, char const *s2);

/*ft_isdigit.c*/
int		ft_isdigit(int c);

/*ft_strchr.c*/
char	*ft_strchr(const char *s, int c);

/*ft_strdup.c*/
char	*ft_strdup(const char *s);

/*ft_strlen.c*/
size_t	ft_strlen(const char *str);

/*ft_calloc.c*/
void	*ft_calloc(size_t nmemb, size_t size);

/*ft_atoi.c*/
int		ft_atoi(const char *nptr);

/*ft_strlcpy.c*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/*ft_strncmp.c*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
