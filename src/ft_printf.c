/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:03:47 by maliew            #+#    #+#             */
/*   Updated: 2022/07/19 01:54:15 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_args(va_list args, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->sr == 'c')
		count += print_char(va_arg(args, int), flags);
	else if (flags->sr == 's')
		count += print_str(va_arg(args, char *), flags);
	else if (flags->sr == 'i' || flags->sr == 'd')
		count += print_int(va_arg(args, int), flags);
	else if (flags->sr == 'u')
		count += print_int(va_arg(args, unsigned int), flags);
	else if (flags->sr == 'x')
		count += print_hex(va_arg(args, unsigned int), flags,
				"0x0123456789abcdef", 0);
	else if (flags->sr == 'X')
		count += print_hex(va_arg(args, unsigned int), flags,
				"0X0123456789ABCDEF", 0);
	else if (flags->sr == 'p')
		count += print_hex(va_arg(args, unsigned long), flags,
				"0x0123456789abcdef", 1);
	else if (flags->sr == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	*flags;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			flags = get_flags((char *)format, &i);
			if (!flags)
				return (0);
			count += print_args(args, flags);
			free(flags);
		}
		else
			count += write(1, format + i, 1);
		i++;
	}
	va_end(args);
	return (count);
}
