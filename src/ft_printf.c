/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:03:47 by maliew            #+#    #+#             */
/*   Updated: 2022/07/17 20:06:52 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
