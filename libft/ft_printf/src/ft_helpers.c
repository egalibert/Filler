/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:42:37 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/15 12:57:09 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_zero_precision(t_flags *flags, char *str)
{
	char	*temp;

	free(str);
	if (flags->plus == 1)
	{
		temp = ft_strdup("+");
		flags->over = 1;
	}
	else if (flags->space == 1)
	{
		temp = ft_strdup(" ");
		flags->over = 1;
	}
	else
		temp = ft_strdup("");
	return (temp);
}

char	*ft_manage_int_zero(t_flags *flags, char *str)
{
	if (flags->dot == 0)
	{
		str = ft_zero_precision(flags, str);
		return (str);
	}
	if (flags->plus == 1 && flags->width <= 1 && flags->dot == -1 \
		&& flags->over == 0)
	{
		str = ft_strjoin_f2("+", str);
		flags->over = 1;
	}
	else if (flags->space == 1 && flags->width <= 1 && flags->dot == -1 && \
			flags->over == 0)
	{
		str = ft_strjoin_f2(" ", str);
		flags->over = 1;
	}
	return (str);
}

char	*ft_manage_int_sign(t_flags *flags, char *str, long long int num)
{	
	if (flags->plus == 1 && num >= 0 && flags->over == 0)
	{
		str = ft_strjoin_f2("+", str);
		flags->over = 1;
	}
	else if (flags->space == 1 && num >= 0 && flags->over == 0)
	{
		str = ft_strjoin_f2(" ", str);
		flags->over = 1;
	}
	else if (num < 0 && flags->min_over == 0)
		str = ft_strjoin_f2("-", str);
	return (str);
}

int	ft_iszerof(t_flags *flags, long long int num)
{
	if (flags->zero == 1)
	{
		if (flags->plus == 1 || flags->space == 1 || num < 0)
			return (1);
	}
	return (0);
}

char	ft_char_sign(t_flags *flags, char sign)
{
	if (flags->plus == 1)
	{
		sign = '+';
		flags->over = 1;
	}
	else
	{
		sign = ' ';
		flags->over = 1;
	}
	return (sign);
}
