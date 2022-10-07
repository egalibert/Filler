/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:24:20 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/21 19:26:00 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_manage_ptr_wid(t_flags *flags, char *str)
{
	int		len;
	char	*temp_str;
	int		a;

	a = 0;
	len = flags->width - ft_strlen(str);
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
	free(temp_str);
	return (str);
}

char	*ft_manage_ptr_pre(t_flags *flags, char *str)
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

char	*ft_manage_ptr_str(t_flags *flags, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (flags->dot > len)
		str = ft_manage_ptr_pre(flags, str);
	if (flags->dot == 0 && ft_strequ(str, "0"))
	{
		free(str);
		str = ft_strdup("");
	}
	if (flags->type == 'p')
		str = ft_strjoin_f2("0x", str);
	len = ft_strlen(str);
	if (flags->dot == -1 && flags->zero == 1 && flags->minus != 1)
		str[1] = '0';
	if (flags->width >= len)
		str = ft_manage_ptr_wid(flags, str);
	if (flags->dot == -1 && flags->zero == 1 && flags->minus != 1)
		str[1] = 'x';
	return (str);
}

int	ft_treat_pointer(va_list *args, t_flags *flags)
{
	char	*str;
	void	*number;
	int		char_count;

	char_count = 0;
	if (flags->star > 0)
		ft_star(args, flags);
	number = va_arg(*args, void *);
	flags->base = 16;
	str = ft_itoa_uns((unsigned long long)number, flags);
	str = ft_manage_ptr_str(flags, str);
	ft_putstr(str);
	char_count = ft_strlen(str);
	free(str);
	return (char_count);
}
