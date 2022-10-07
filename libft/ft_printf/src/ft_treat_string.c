/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:10:43 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/22 13:24:35 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*check_width_str(t_flags *flags, char *print_str, int char_count)
{
	char	*str;
	int		i;

	if (flags->width >= char_count)
		i = (flags->width);
	str = ft_strnew(flags->width);
	if (!str)
		return (NULL);
	i = 0;
	while (flags->width-- > char_count)
	{
		if (flags->zero == 1)
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	if (flags->minus == 1)
		print_str = ft_strjoin_f1(print_str, str);
	else
		print_str = ft_strjoin_f2(str, print_str);
	free(str);
	return (print_str);
}

char	*ft_manage_str_prec(t_flags *flags, int str_len, char *print_str)
{
	int		char_count;
	char	*temp_str;

	if (flags->dot <= str_len)
		temp_str = ft_strsub(print_str, 0, flags->dot);
	else
		temp_str = ft_strsub(print_str, 0, str_len);
	char_count = ft_strlen(temp_str);
	free(print_str);
	temp_str = check_width_str(flags, temp_str, char_count);
	return (temp_str);
}

int	ft_treat_string(va_list *args, t_flags *flags)
{
	int		char_count;
	char	*str;
	char	*print_str;

	if (flags->star > 0)
		ft_star(args, flags);
	if (flags->dot < -1)
		flags->dot *= -1;
	str = va_arg(*args, char *);
	if (!str)
		print_str = ft_strdup("(null)");
	else
		print_str = ft_strdup(str);
	char_count = ft_strlen(print_str);
	if (flags->dot != -1 || flags->width != 0 || flags->minus != 0)
	{
		if (flags->dot != -1)
			print_str = ft_manage_str_prec(flags, char_count, print_str);
		else
			print_str = check_width_str(flags, print_str, char_count);
	}
	char_count = ft_strlen(print_str);
	ft_putstr(print_str);
	ft_strdel(&print_str);
	return (char_count);
}
