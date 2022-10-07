/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:52:19 by egaliber          #+#    #+#             */
/*   Updated: 2022/09/24 14:43:03 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*num_conv(char *str, long long int number, int len)
{
	while (number > 0)
	{
		str[len--] = '0' + (number % 10);
		number = number / 10;
	}
	return (str);
}

int	ft_len(long long int n)
{
	int	len;

	len = 0;
	if (n == -9223372036854775807 - 1)
	{
		len = 19;
		return (len);
	}
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa_signed(long long int n)
{
	char				*str;
	int					len;
	long long int		number;

	len = ft_len(n);
	if (n == -9223372036854775807 - 1)
		return (str = ft_strdup("9223372036854775808"));
	str = ft_strnew(len);
	if (!(str))
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	number = n;
	if (n < 0)
		number *= -1;
	str = num_conv(str, number, len);
	return (str);
}
