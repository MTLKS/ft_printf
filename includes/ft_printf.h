/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:00:22 by maliew            #+#    #+#             */
/*   Updated: 2022/07/17 20:24:54 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	int		dash;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		precision;
	char	specifier;
}	t_flags;

t_flags	*get_flags(char *string, int *i);

int		print_args(va_list args, t_flags *flags);
int		print_char(char c, t_flags *flags);
int		print_str(char *s, t_flags *flags);

int		print_width(int width, char c);

int		ft_printf(const char *format, ...);

#endif