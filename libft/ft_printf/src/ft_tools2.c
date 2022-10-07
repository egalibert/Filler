/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:09:39 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/22 17:18:56 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_add_hash(t_flags *flags, char *str, unsigned long long num)
{
	if (flags->zero == 0 && flags->dot == -1 && flags->hash == 1 && num > 0)
	{
		if (flags->type == 'x')
			str = ft_strjoin_f2("0x", str);
		else
			str = ft_strjoin_f2("0X", str);
		flags->hash = 0;
	}
	return (str);
}

long double	ft_power(int power, long double base)
{
	int	i;
	int	number;

	number = 1.0;
	i = 0;
	while (i < power)
	{
		number *= base;
		i++;
	}
	return (number);
}

long double	ft_manage_f_mods(va_list *args, t_flags *flags)
{
	if (flags->mods == 5)
		return ((long double)va_arg(*args, long double));
	else
		return ((double)va_arg(*args, double));
}

long double	ft_rounder(long double num, t_flags *flags)
{
	long double	temp;

	if (num < 0)
	{
		num *= -1;
	}
	temp = num * ft_power(flags->dot, 10.0);
	if (temp - (long long)temp == 0.5)
	{
		if ((long long)temp % 2 != 1)
			num = temp / ft_power(flags->dot, 10.0);
		else
			num = ft_rounding(flags->dot, num);
	}
	else
		num = ft_rounding(flags->dot, num);
	return (num);
}

char	*ft_hex_hash_mod(t_flags *flags, char *str, \
		unsigned long long num, int len2)
{
	if (flags->hash == 1 && flags->dot == -1 && num > 0)
	{
		if (ft_strlen(str) - len2 >= 2 && flags->minus == 0)
		{
			str[0] = '0';
			if (flags->type == 'x')
				str[1] = 'x';
			if (flags->type == 'X')
				str[1] = 'X';
		}
		else
		{
			if (flags->type == 'x')
				str = ft_strjoin_f2("0x", str);
			if (flags->type == 'X')
				str = ft_strjoin_f2("0X", str);
		}
	}
	return (str);
}
