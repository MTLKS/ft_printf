/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:51:42 by maliew            #+#    #+#             */
/*   Updated: 2022/07/19 00:34:06 by maliew           ###   ########.fr       */
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
	if (!s)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(s);
	len = ft_strlen(str);
	if (flags->dt && flags->pr < len && s)
		len = flags->pr;
	else if (flags->dt && flags->pr < len && !s)
		len = 0;
	if (!flags->da && flags->wi)
		count += print_width(flags->wi - len, ' ');
	count += putstr_len(str, len);
	if (flags->da && flags->wi)
		count += print_width(flags->wi - len, ' ');
	free(str);
	return (count);
}

int	print_int(long n, t_flags *flags)
{
	int	count;
	int	neg;
	int	l;

	count = 0;
	get_neg(&n, &neg);
	l = get_len_base(n, 10) * !(flags->dt && !flags->pr && !n);
	if (!flags->da && (!flags->ze || flags->dt) && flags->wi)
		count += print_width(flags->wi - neg - get_max(flags->pr, l), ' ');
	if (neg)
		count += write(1, "-", 1);
	if (flags->pl && !neg)
		count += write(1, "+", 1);
	else if (flags->sp && !neg)
		count += write(1, " ", 1);
	if (flags->ze && !flags->dt && !flags->da && flags->wi)
		count += print_width(flags->wi - neg - l, '0');
	if (flags->dt)
		count += print_width(flags->pr - l, '0');
	if ((flags->dt && flags->pr) || (!flags->dt && !flags->pr) || n)
		print_base(n, "0123456789");
	if (flags->da && flags->wi)
		count += print_width(flags->wi - neg - get_max(flags->pr, l), ' ');
	return (count + l);
}

int	print_hex(long n, t_flags *flags, char *base, char *x)
{
	int	count;
	int	l;

	count = 0;
	l = get_len_base(n, 16) * !(flags->dt && !flags->pr && !n);
	if (!flags->da && (!flags->ze || flags->dt) && flags->wi)
		count += print_width(flags->wi - get_max(flags->pr, l) - flags->ha * 2,
				' ');
	if (flags->ha && n)
		count += write(1, x, 2);
	if (flags->ze && !flags->dt && !flags->da && flags->wi)
		count += print_width(flags->wi - l, '0');
	if (flags->dt)
		count += print_width(flags->pr - l, '0');
	if ((flags->dt && flags->pr) || (!flags->dt && !flags->pr) || n)
		print_base(n, base);
	if (flags->da && flags->wi)
		count += print_width(flags->wi - get_max(flags->pr, l) - flags->ha * 2,
				' ');
	return (count + l);
}

int	print_ptr(unsigned long n, t_flags *flags)
{
	int	count;
	int	l;

	count = 0;
	l = get_ulen_base(n, 16) * !(flags->dt && !flags->pr && !n);
	if (!flags->da && (!flags->ze || flags->dt) && flags->wi)
		count += print_width(flags->wi - get_max(flags->pr, l) - 2, ' ');
	count += write(1, "0x", 2);
	if (flags->ze && !flags->dt && !flags->da && flags->wi)
		count += print_width(flags->wi - l, '0');
	if (flags->dt)
		count += print_width(flags->pr - l, '0');
	if ((flags->dt && flags->pr) || (!flags->dt && !flags->pr) || n)
		print_base(n, "0123456789abcdef");
	if (flags->da && flags->wi)
		count += print_width(flags->wi - get_max(flags->pr, l) - 2, ' ');
	return (count + l);
}
