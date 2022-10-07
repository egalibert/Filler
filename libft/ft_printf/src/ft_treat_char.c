/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:36:18 by egaliber          #+#    #+#             */
/*   Updated: 2022/09/21 19:24:53 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_width(t_flags *flags, char c)
{
	int	char_count;

	char_count = flags->width;
	if (flags->minus == 1)
	{
		ft_putchar(c);
		if (flags->width > 1)
			while (flags->width-- > 1)
				ft_putchar(' ');
		else
			char_count = 1;
	}
	else
	{
		while (flags->width-- > 1)
		{
			if (flags->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		ft_putchar(c);
	}
	return (char_count);
}

int	ft_treat_char(va_list *args, t_flags *flags)
{
	int		char_count;
	char	c;

	char_count = 0;
	if (flags->star > 0)
		ft_star(args, flags);
	c = va_arg(*args, int);
	if (flags->minus == 1 || flags->width > 1)
		char_count = check_width(flags, c);
	else
	{
		ft_putchar(c);
		char_count++;
	}
	return (char_count);
}
