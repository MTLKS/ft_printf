/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:03:47 by maliew            #+#    #+#             */
/*   Updated: 2022/07/13 20:01:05 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	parse_args(va_list args, char *format, int *i)
{
	t_flags	flags;

	
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;


	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			
		}
		else
		{
			ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	va_end(args);
}
