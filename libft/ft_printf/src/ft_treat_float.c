/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:26:03 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/22 13:58:53 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_manage_f_wid(t_flags *flags, char *str, int is_neg)
{
	int		len;
	char	*temp_str;
	int		a;

	a = 0;
	len = flags->width - ft_strlen(str);
	temp_str = ft_strnew(len);
	if (flags->plus == 1 || flags->space == 1 || is_neg == 1)
		len--;
	str = ft_add_minus(str, flags, is_neg);
	while (len--)
	{
		if (flags->zero == 1 && flags->dot != -1 && flags->minus == 0)
			temp_str[a++] = '0';
		else
			temp_str[a++] = ' ';
	}
	if (flags->minus == 1)
		str = ft_strjoin_f1(str, temp_str);
	else
		str = ft_strjoin_f2(temp_str, str);
	free(temp_str);
	return (str);
}

char	*ft_manage_f_str(t_flags *flags, char *str, long double number, \
		int is_neg)
{
	int	len;

	len = ft_strlen(str);
	if (flags->width > len)
		str = ft_manage_f_wid(flags, str, is_neg);
	if (is_neg == 1 && flags->min_over == 0)
	{
		str = ft_strjoin_f2("-", str);
	}
	if (number >= 0 && (flags->plus == 1 || flags->space == 1))
	{
		if (flags->plus == 1 && is_neg == 0)
			str = ft_strjoin_f2("+", str);
		else if (flags->space == 1 && is_neg == 0)
			str = ft_strjoin_f2(" ", str);
	}
	if (flags->hash == 1 && flags->dot == 0)
		str = ft_strjoin_f1(str, ".");
	return (str);
}

char	*ft_add_float_part(long double f_num, char *str, int precision)
{
	long double	num;
	int			i;

	num = f_num - (long long)f_num;
	str = ft_strnew(precision + 1);
	if (!str)
		return (0);
	i = 1;
	str[0] = '.';
	while (precision-- > 0)
	{
		num *= 10.0;
		str[i++] = (long long)num + '0';
		num = num - (long long)num;
	}
	return (str);
}

char	*ft_ftoa(long double num, char *str, int precision)
{
	char	*float_part;

	float_part = NULL;
	str = ft_itoa_signed((long long)num);
	if (precision != 0)
		float_part = ft_add_float_part(num, float_part, precision);
	else
		float_part = ft_strdup("");
	str = ft_strjoin_f1(str, float_part);
	free(float_part);
	return (str);
}

int	ft_treat_float(va_list *args, t_flags *flags)
{
	char		*str;
	long double	number;
	int			char_count;
	int			is_neg;

	is_neg = 0;
	str = NULL;
	char_count = 0;
	number = ft_manage_f_mods(args, flags);
	if (flags->dot == -1)
		flags->dot = 6;
	if (1 / number > 0)
		is_neg = 0;
	else
		is_neg = 1;
	number = ft_rounder(number, flags);
	str = ft_ftoa(number, str, flags->dot);
	str = ft_manage_f_str(flags, str, number, is_neg);
	ft_putstr(str);
	char_count = ft_strlen(str);
	free(str);
	return (char_count);
}
