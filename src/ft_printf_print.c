/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:51:42 by maliew            #+#    #+#             */
/*   Updated: 2022/07/19 21:48:25 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_char(char c, t_flags *flags)
{
	int	count;

	count = 0;
	if (!flags->da && flags->wi)
		count += print_width(flags->wi - 1, ' ');
	count += write(1, &c, 1);
	if (flags->da && flags->wi)
		count += print_width(flags->wi - 1, ' ');
	return (count);
}

int	print_str(char *s, t_flags *flags)
{
	int		count;
	int		len;
	char	*str;

	count = 0;
	if (s)
		len = ft_strlen(s);
	else
		len = 6;
	if (flags->dt && (flags->pr < len))
		len = flags->pr;
	if (s)
		str = ft_substr(s, 0, len);
	else
		str = ft_substr("(null)", 0, len);
	if (!flags->da && flags->wi)
		count += print_width(flags->wi - len, ' ');
	ft_putstr_fd(str, 1);
	if (flags->da && flags->wi)
		count += print_width(flags->wi - len, ' ');
	free(str);
	return (count + len);
}

int	print_int(long n, t_flags *flags)
{
	int	count;
	int	neg;
	int	len;

	count = 0;
	get_neg(&n, &neg);
	len = get_len_base(n, 10) * !(flags->dt && !flags->pr && !n);
	if (!flags->da && (!flags->ze || flags->dt) && flags->wi)
		count += print_width(flags->wi - neg - get_max(flags->pr, len), ' ');
	if (neg)
		count += write(1, "-", 1);
	else if (flags->pl)
		count += write(1, "+", 1);
	else if (flags->sp)
		count += write(1, " ", 1);
	if (flags->ze && !flags->dt && !flags->da && flags->wi)
		count += print_width(flags->wi - neg - len, '0');
	if (flags->dt)
		count += print_width(flags->pr - len, '0');
	if (!(flags->dt && !flags->pr && !n))
		print_base(n, "0123456789");
	if (flags->da && flags->wi)
		count += print_width(flags->wi - neg - get_max(flags->pr, len), ' ');
	return (count + len);
}

int	print_hex(unsigned long n, t_flags *flags, char *base, int ptr)
{
	int	count;
	int	len;

	count = 0;
	len = get_len_base(n, 16) * !(flags->dt && !flags->pr && !n);
	if (!flags->da && (!flags->ze || flags->dt) && flags->wi)
		count += print_width(
				flags->wi - get_max(flags->pr, len) - (flags->ha || ptr) * 2,
				' ');
	if ((flags->ha && n) || ptr)
		count += write(1, base, 2);
	if (flags->ze && !flags->dt && !flags->da && flags->wi)
		count += print_width(flags->wi - len, '0');
	if (flags->dt)
		count += print_width(flags->pr - len, '0');
	if (!(flags->dt && !flags->pr && !n))
		print_base(n, base + 2);
	if (flags->da && flags->wi)
		count += print_width(
				flags->wi - get_max(flags->pr, len) - (flags->ha || ptr) * 2,
				' ');
	return (count + len);
}
