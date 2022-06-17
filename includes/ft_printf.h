/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 02:37:18 by slucas            #+#    #+#             */
/*   Updated: 2022/06/17 06:42:37 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

# define BASE "0123456789abcdef"
# define BASE_X "0123456789ABCDEF"

int		ft_putchar(char c);
void	ft_check_fmt(const char *c, va_list *ap, int *length);
void	ft_print_char(va_list *ap, int *length);
void	ft_print_str(va_list *ap, int *length);
void	ft_print_ptr(va_list *ap, int *length);
void	ft_print_nbr(va_list *ap, int *length);
void	ft_print_u_nbr(va_list *ap, int *length);
void	ft_print_hex(va_list *ap, int *length, const char c);
int		ft_printf(const char *fmt, ...);

#endif
