/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:03:27 by asepulve          #+#    #+#             */
/*   Updated: 2023/11/27 22:43:27 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

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

int			ft_printf(const char *format, ...);
#endif