/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:15:05 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/15 14:01:54 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_uns_base(char *str, unsigned long long int num, int len, \
t_flags *flags)
{
	char	*num_alph;
	int		i;

	i = 0;
	if (flags->type == 'X')
		num_alph = "0123456789ABCDEF";
	else
		num_alph = "0123456789abcdef";
	while (num >= flags->base)
	{
		i = num % flags->base;
		str[len--] = num_alph[i];
		num = num / flags->base;
	}
	i = num % flags->base;
	str[len] = num_alph[i];
	return (str);
}

int	ft_len_uns(unsigned long long int n, t_flags *flags)
{
	int	len;

	len = 1;
	while (n / flags->base > 0)
	{
		len++;
		n = n / flags->base;
	}
	return (len);
}

char	*ft_itoa_uns(unsigned long long int num, t_flags *flags)
{
	char	*str;
	int		len;

	if (flags->base < 2 || flags->base > 16)
		return (NULL);
	len = ft_len_uns(num, flags);
	str = ft_strnew(len);
	if (!(str))
		return (NULL);
	str[len--] = '\0';
	str = ft_uns_base(str, num, len, flags);
	return (str);
}
