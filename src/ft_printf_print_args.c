/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:34:28 by maliew            #+#    #+#             */
/*   Updated: 2022/07/17 20:24:28 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_args(va_list args, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->specifier == 'c')
		count += print_char(va_arg(args, int), flags);
	else if (flags->specifier == 's')
		count += print_str(va_arg(args, char *), flags);
	return (count);
}
