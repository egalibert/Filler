/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 01:21:58 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/21 14:40:44 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init_flags(t_flags *flags)
{
	flags->dot = -1;
	flags->minus = 0;
	flags->type = 0;
	flags->width = 0;
	flags->zero = 0;
	flags->plus = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->mods = 0;
	flags->over = 0;
	flags->min_over = 0;
	flags->base = 10;
	flags->star = 0;
}

int	ft_treat_save(const char *save, va_list *args, t_flags *flags)
{
	int			i;
	int			char_count;
	char		*str;
	int			x;

	x = 0;
	i = 1;
	str = ft_strnew(100);
	char_count = 0;
	ft_init_flags(flags);
	while (save[i] && !form_spec(save[i]))
	{
		if (is_flag(save[i]))
			str[x++] = save[i];
		i++;
	}
	if (ft_strcmp(str, "") != 0)
		ft_flag_parse(str, flags);
	else
		free(str);
	flags->type = save[i];
	char_count = ft_treatment(args, flags);
	return (char_count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			char_count;
	int			i;
	t_flags		*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	i = -1;
	char_count = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (form_spec(format[i + 1]) || is_flag(format[i + 1]))
				char_count += ft_treat_save(&format[i++], &args, flags);
			while (is_flag(format[i]))
				i++;
		}
		else
			char_count += ft_putchar2(format[i]);
	}
	free(flags);
	va_end(args);
	return (char_count);
}
