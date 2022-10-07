/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:24:20 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/21 19:25:36 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_manage_oct_hash(t_flags *flags, char *str, \
		unsigned long long int num)
{
	if (num == 0 && flags->dot == 0 && flags->hash == 1)
	{
		free(str);
		str = ft_strdup("0");
	}
	if (num == 0 && flags->dot == 1 && flags->hash == 1)
	{
		free(str);
		str = ft_strdup("0");
	}
	if (num == 0 && flags->minus == 1 && flags->hash == 1)
	{
		free(str);
		str = ft_strdup("0");
		flags->over = 1;
	}
	return (str);
}

char	*ft_manage_oct_wid(t_flags *flags, char *str)
{
	int		len;
	char	*temp_str;
	int		a;

	a = 0;
	len = flags->width - ft_strlen(str);
	temp_str = ft_strnew(len);
	while (len--)
	{
		if (flags->zero == 1 && flags->dot == -1 && flags->minus == 0 \
			&& flags->over != 1)
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

char	*ft_manage_oct_pre(t_flags *flags, char *str)
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

char	*ft_manage_oct_str(t_flags *flags, char *str, \
		unsigned long long int num)
{
	int	len;

	if (flags->hash == 1 && num != 0)
		str = ft_strjoin_f2("0", str);
	len = ft_strlen(str);
	if (flags->dot > len)
		str = ft_manage_oct_pre(flags, str);
	if (num == 0 && flags->dot == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	str = ft_manage_oct_hash(flags, str, num);
	len = ft_strlen(str);
	if (flags->width >= len)
		str = ft_manage_oct_wid(flags, str);
	return (str);
}

int	ft_treat_oct(va_list *args, t_flags *flags)
{
	char						*str;
	unsigned long long int		number;
	int							char_count;

	char_count = 0;
	if (flags->star > 0)
		ft_star(args, flags);
	number = ft_manage_u_mods(args, flags);
	flags->base = 8;
	str = ft_itoa_uns(number, flags);
	str = ft_manage_oct_str(flags, str, number);
	ft_putstr(str);
	char_count = ft_strlen(str);
	free(str);
	return (char_count);
}
