/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:51:42 by maliew            #+#    #+#             */
/*   Updated: 2022/07/17 20:37:11 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_putstr(char *s, int len)
{
	int	i;

	i = 0;
	while (i < len && s[i])
	{
		write(1, s + i, 1);
		i++;
	}
	return (i);
}

int	print_char(char c, t_flags *flags)
{
	int	count;

	count = 0;
	if (!flags->dash && flags->width)
		count += print_width(flags->width - 1, ' ');
	count += write(1, &c, 1);
	if (flags->dash && flags->width)
		count += print_width(flags->width - 1, ' ');
	return (count);
}

int	print_str(char *s, t_flags *flags)
{
	int		count;
	int		len;
	char	*str;

	count = 0;
	if (!s)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(s);
	len = ft_strlen(str);
	if (flags->dot && flags->precision < len)
		len = flags->precision;
	if (!flags->dash && flags->width)
		count += print_width(flags->width - len, ' ');
	count += ft_putstr(str, len);
	if (flags->dash && flags->width)
		count += print_width(flags->width - len, ' ');
	free(str);
	return (count);
}
