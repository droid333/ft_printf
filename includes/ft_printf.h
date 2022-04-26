/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 02:37:18 by slucas            #+#    #+#             */
/*   Updated: 2022/04/26 07:44:23 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# include <stdlib.h>
# include <stdio.h>

# include "../libft/libft.h"

# define FLAGS "-0.+ #"
# define SET "cspdiuxX%"

int	ft_printf(const char *fmt, ...);

#endif
