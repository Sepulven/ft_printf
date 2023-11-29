/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:03:27 by asepulve          #+#    #+#             */
/*   Updated: 2023/11/28 17:58:19 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define DECIMAL "0123456789";
# define HEX_SMALL "0123456789abcdef";
# define HEX_UPPER "0123456789ABCDEF";

// %[$][flags][width][.precision][length modifier] order
typedef struct s_flags
{
    char    *str; /*holds the specifiers and the flags*/
    char    conversion; /*tells the datatype*/
    int     minus; /*left alignment, the output is left-justified*/
    int     zero; /*zero should be used for the character of padding*/
    int     precision; /*Precision is the number of digits to be printed after the decimal*/
    int     min_width; /*tells the minimum width of the string*/
    /*-- everything above should work with all conversions --*/
    int     hash; /*hash convert the value to an alternet form*/
    int     plus; /*specify that the value should always be shown*/
    int     space; /*Adds an extra space to align number in tables, add a space for positive values and the minus sign in negative one*/
} t_flags;

typedef unsigned long long ull_t;

/*main.c*/
int			ft_printf(const char *format, ...);

/*utils.c*/
size_t	ft_putchar(char c);
void	print_flags(t_flags *flags);

/*flags.c*/
t_flags	*set_flags(const char *specifier);

/*ull_converter.c*/
char	*ull_converter();

/*build_str.c*/
#endif