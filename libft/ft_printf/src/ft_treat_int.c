/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:05:57 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/22 16:20:14 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_manage_int_wid(t_flags *flags, char *str, long long int num)
{
	int		len;
	char	*temp_str;
	int		a;

	a = 0;
	len = flags->width - ft_strlen(str);
	if (ft_iszerof(flags, num))
		len--;
	temp_str = ft_strnew(len);
	while (len--)
	{
		if (flags->zero == 1 && flags->dot == -1 && flags->minus == 0)
			temp_str[a++] = '0';
		else
			temp_str[a++] = ' ';
	}
	if (flags->minus == 1)
		str = ft_strjoin_f1(str, temp_str);
	else
		str = ft_strjoin_f2(temp_str, str);
	if (ft_iszerof(flags, num))
		str = ft_manage_int_sign(flags, str, num);
	free(temp_str);
	return (str);
}

char	*ft_manage_int_prec(t_flags *flags, char *str, long long int num, int a)
{
	int		i;
	char	*temp_str;

	i = flags->dot - ft_strlen(str);
	if (flags->plus == 1 || flags->space == 1 || num < 0)
		i++;
	temp_str = ft_strnew(i);
	if (num < 0)
	{
		temp_str[a++] = '-';
		flags->min_over = 1;
	}
	if (num >= 0)
	{
		if (flags->plus == 1 || flags->space == 1)
			temp_str[a++] = ft_char_sign(flags, *temp_str);
	}
	if (a == 1)
		i--;
	while (i--)
		temp_str[a++] = '0';
	str = ft_strjoin_f2(temp_str, str);
	free(temp_str);
	return (str);
}

char	*ft_manage_int_str(t_flags *flags, char *str, long long int num)
{
	int		len;
	int		a;

	a = 0;
	len = ft_strlen(str);
	if (flags->dot >= len)
		str = ft_manage_int_prec(flags, str, num, a);
	else if (flags->plus == 1 && flags->zero == 0 && num >= 0)
		str = ft_manage_int_sign(flags, str, num);
	else if (flags->space == 1 && flags->zero == 0 && num >= 0)
		str = ft_manage_int_sign(flags, str, num);
	else if (num < 0 && flags->zero == 0)
		str = ft_manage_int_sign(flags, str, num);
	if (num == 0)
		str = ft_manage_int_zero(flags, str);
	len = ft_strlen(str);
	if (flags->width > len)
		str = ft_manage_int_wid(flags, str, num);
	else if (ft_iszerof(flags, num) && flags->over == 0)
		str = ft_manage_int_sign(flags, str, num);
	return (str);
}

long long int	ft_manage_mods(va_list *args, t_flags *flags)
{
	if (flags->mods == 1)
		return ((long)va_arg(*args, long int));
	else if (flags->mods == 2)
		return (va_arg(*args, long long int));
	else if (flags->mods == 3)
		return ((short int)va_arg(*args, int));
	else if (flags->mods == 4)
		return ((char)va_arg(*args, int));
	else
		return ((int)va_arg(*args, int));
}

int	ft_treat_int(va_list *args, t_flags *flags)
{
	char			*str;
	long long int	number;
	int				char_count;

	char_count = 0;
	if (flags->dot != -1 && flags->star == 0)
		flags->zero = 0;
	if (flags->star > 0)
		ft_star(args, flags);
	number = ft_manage_mods(args, flags);
	str = ft_itoa_signed(number);
	str = ft_manage_int_str(flags, str, number);
	ft_putstr(str);
	char_count = ft_strlen(str);
	free(str);
	return (char_count);
}
