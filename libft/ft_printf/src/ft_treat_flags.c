/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:23:02 by elliotgalib       #+#    #+#             */
/*   Updated: 2022/09/22 17:27:38 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parse_mods(char *str, t_flags *flags)
{
	int	i;

	i = 0;
	while (!ft_check_mods(str[i]))
		i++;
	if (str[i] == 'L')
		flags->mods = 5;
	if (str[i] == 'l')
	{
		flags->mods = 1;
		if (str[i + 1] == 'l')
			flags->mods = 2;
	}
	if (str[i] == 'h')
	{
		flags->mods = 3;
		if (str[i + 1] == 'h')
			flags->mods = 4;
	}	
}

void	ft_parse_precision(char *str, t_flags *flags)
{
	char	*num_str;
	int		i;
	int		n;

	i = 0;
	n = 0;
	flags->dot = 0;
	num_str = ft_strnew(20);
	while (str[i] != '.')
		i++;
	i++;
	if (str[i] == '*')
	{
		ft_manage_star(flags);
		i++;
	}
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			num_str[n++] = str[i++];
		flags->dot = ft_atoi(num_str);
	}
	ft_strdel(&num_str);
	if (ft_check_mods(str[i]))
		ft_parse_mods(str, flags);
}

void	ft_parse_width(char *str, t_flags *flags, int n)
{
	char	*num_str;
	int		i;

	i = 0;
	num_str = ft_strnew(20);
	while (str[i] == '-' || str[i] == '+' || str[i] == '#' || str[i] == ' '
		|| str[i] == '0')
		i++;
	if (str[i] == '*')
	{
		flags->star = 1;
		i++;
	}
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			num_str[n++] = str[i++];
		flags->width = ft_atoi(num_str);
	}
	ft_strdel(&num_str);
	if (str[i] == '.')
		ft_parse_precision(str, flags);
	else if (ft_check_mods(str[i]))
		ft_parse_mods(str, flags);
	free(str);
}

void	ft_reset_flags(t_flags *flags)
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
	flags->star = 0;
}

void	ft_flag_parse(char *str, t_flags *flags)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	ft_reset_flags(flags);
	while (str[i] == '-' || str[i] == '+' || str[i] == '#' || str[i] == ' '
		|| str[i] == '0')
	{
		if (str[i] == '-')
			flags->minus = 1;
		if (str[i] == '+')
			flags->plus = 1;
		if (str[i] == '#')
			flags->hash = 1;
		if (str[i] == ' ')
			flags->space = 1;
		if (str[i] == '0')
			flags->zero = 1;
		i++;
	}
	ft_parse_width(str, flags, n);
}
