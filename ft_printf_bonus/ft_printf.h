/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:03:27 by asepulve          #+#    #+#             */
/*   Updated: 2023/12/03 16:04:34 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H 1

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

// # define DEC_BASE "0123456789";
// # define HEX_S_BASE "0123456789abcdef";
// # define HEX_U_BASE "0123456789ABCDEF";

// %[$][flags][width][.precision][length modifier] order
typedef struct s_mod
{
    char    *str; /*holds the specifiers and the flags*/
    char    *flags;
    int     precision; /*Precision is the number of digits to be printed after the decimal*/
    int     min_width; /*tells the minimum width of the string*/
    char    conversion; /*tells the datatype*/
} t_mod;

/*
typedef struct s_flags
{
    char    *str; holds the specifiers and the flags
    char    conversion; tells the datatype
    int     minus; left alignment, the output is left-justified
    int     zero; zero should be used for the character of padding
    int     precision; Precision is the number of digits to be printed after the decimal
    int     min_width; tells the minimum width of the string
     
     everything above should work with all conversions
     
    int     hash; hash convert the value to an alternet form
    int     plus; specify that the value should always be shown
    int     space; Adds an extra space to align number in tables, add a space for positive values and the minus sign in negative one
} t_flags;
*/

typedef unsigned long long ull_t;

/*main.c*/
int			ft_printf(const char *format, ...);

/*utils.c*/
size_t	ft_putchar(char c);
void	print_flags(t_mod *flags);
char	*ft_strjoin_free(char *s1, char *s2, char c);

/*set_mod.c*/
t_mod	*set_mod(const char *specifier);

/*converter.c*/
char	*converter(long long n, const char *base, int base_len);
char	*converter_ull(ull_t n, const char *base, int base_len);

/*build_str.c*/
int     build_str(t_mod *flags, va_list arg);

/*mod_flags.c*/
char    *mod_flags(char *str, t_mod *mod);

/*mod_width.c*/
void    swap_chars(char *s1, char *s2);
char    *mod_zero(char *str, t_mod *mod);
char    *mod_width(char *str, t_mod *mod);

/*mod_precision.c*/
char    *mod_precision(char *str, t_mod *mod);

#endif
