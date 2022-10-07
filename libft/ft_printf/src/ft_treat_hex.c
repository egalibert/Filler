/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:24:20 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/22 13:24:19 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*hex_hash(t_flags *flags, char *str, unsigned long long num, int len2)
{
	if (flags->width > len2 + 2 && flags->dot == -1 && flags->zero == 1 \
		&& flags->minus == 0 && num > 0 && flags->hash == 1)
	{
		str[0] = '0';
		if (flags->type == 'x')
			str[1] = 'x';
		if (flags->type == 'X')
			str[1] = 'X';
		flags->hash = 0;
	}
	str = ft_hex_hash_mod(flags, str, num, len2);
	return (str);
}

char	*ft_manage_hex_wid(t_flags *flags, char *str, \
		unsigned long long int num)
{
	int		len;
	char	*temp_str;
	int		a;

	a = 0;
	len = flags->width - ft_strlen(str);
	if (flags->zero == 0 && flags->dot == -1 && flags->hash == 1 && num > 0)
		len -= 2;
	temp_str = ft_strnew(len);
	while (len--)
	{
		if (flags->zero == 1 && flags->dot == -1 && flags->minus == 0)
			temp_str[a++] = '0';
		else
			temp_str[a++] = ' ';
	}
	str = ft_add_hash(flags, str, num);
	if (flags->minus == 1)
		str = ft_strjoin_f1(str, temp_str);
	else
		str = ft_strjoin_f2(temp_str, str);
	free(temp_str);
	return (str);
}

char	*ft_manage_hex_pre(t_flags *flags, char *str)
{
	int		i;
	int		a;
	char	*temp_str;

	a = 0;
	i = flags->dot - ft_strlen(str);
	temp_str = ft_strnew(i);
	while (i--)
		temp_str[a++] = '0';
	str = ft_strjoin_f2(temp_str, str);
	free(temp_str);
	return (str);
}

char	*ft_manage_hex_str(t_flags *flags, char *str, \
		unsigned long long int num)
{
	int		len;
	int		len2;

	len2 = ft_strlen(str);
	len = ft_strlen(str);
	if (flags->dot > len)
		str = ft_manage_hex_pre(flags, str);
	if (num == 0 && flags->dot == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	if (flags->hash == 1 && num > 0 && flags->dot != -1)
	{
		if (flags->type == 'x')
			str = ft_strjoin_f2("0x", str);
		if (flags->type == 'X')
			str = ft_strjoin_f2("0X", str);
		flags->hash = 0;
	}
	len = ft_strlen(str);
	if (flags->width >= len)
		str = ft_manage_hex_wid(flags, str, num);
	str = hex_hash(flags, str, num, len2);
	return (str);
}

int	ft_treat_hex(va_list *args, t_flags *flags)
{
	char					*str;
	unsigned long long int	number;
	int						char_count;

	char_count = 0;
	if (flags->minus == 1)
		flags->zero = 0;
	if (flags->star > 0)
		ft_star(args, flags);
	number = ft_manage_u_mods(args, flags);
	flags->base = 16;
	str = ft_itoa_uns(number, flags);
	str = ft_manage_hex_str(flags, str, number);
	ft_putstr(str);
	char_count = ft_strlen(str);
	free(str);
	return (char_count);
}
