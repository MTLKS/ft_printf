/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:00:22 by maliew            #+#    #+#             */
/*   Updated: 2022/07/19 02:24:08 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

/*
	da	dash;
	ze	zero;
	dt	dot;
	ha	hash;
	sp	space;
	pl	plus;
	wi	width;
	pr	precision;
	sr	specifier;
*/
typedef struct s_flags
{
	int		da;
	int		ze;
	int		dt;
	int		ha;
	int		sp;
	int		pl;
	int		wi;
	int		pr;
	char	sr;
}	t_flags;

t_flags	*get_flags(char *string, int *i);

int		print_char(char c, t_flags *flags);
int		print_str(char *s, t_flags *flags);
int		print_int(long n, t_flags *flags);
int		print_hex(unsigned long n, t_flags *flags, char *base, int ptr);

int		print_width(int width, char c);
void	get_neg(long *n, int *neg);
int		get_max(int a, int b);
int		get_len_base(unsigned long n, int base_len);
void	print_base(unsigned long n, char *base);

int		print_args(va_list args, t_flags *flags);
int		ft_printf(const char *format, ...);

#endif