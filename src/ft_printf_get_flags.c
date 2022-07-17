/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:39:51 by maliew            #+#    #+#             */
/*   Updated: 2022/07/17 19:39:26 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	init_flags(t_flags *flags)
{
	flags->dash = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->plus = 0;
	flags->precision = 0;
	flags->space = 0;
	flags->specifier = 0;
	flags->width = 0;
	flags->zero = 0;
}

static void	parse_flags(t_flags *flags, char *string, int *i)
{
	while (ft_strchr("#0- +", string[*i]))
	{
		if (string[*i] == '#')
			flags->hash = 1;
		else if (string[*i] == '0')
			flags->zero = 1;
		else if (string[*i] == '-')
			flags->dash = 1;
		else if (string[*i] == ' ')
			flags->space = 1;
		else if (string[*i] == '+')
			flags->plus = 1;
		(*i)++;
	}
}

static void	parse_wp(t_flags *flags, char *string, int *i)
{
	while (ft_isdigit(string[*i]))
	{
		flags->width = flags->width * 10 + string[*i] - '0';
		(*i)++;
	}
	if (string[*i] == '.' && string[(*i) + 1])
	{
		(*i)++;
		flags->dot = 1;
		while (ft_isdigit(string[*i]))
		{
			flags->precision = flags->precision * 10 + string[*i] - '0';
			(*i)++;
		}
	}
}

t_flags	*get_flags(char *string, int *i)
{
	t_flags	*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (0);
	init_flags(flags);
	(*i)++;
	parse_flags(flags, string, i);
	parse_wp(flags, string, i);
	flags->specifier = string[*i];
	return (flags);
}
