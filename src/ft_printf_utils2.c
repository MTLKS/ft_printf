/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:57:25 by maliew            #+#    #+#             */
/*   Updated: 2022/07/19 00:34:03 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	putstr_len(char *s, int len)
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
