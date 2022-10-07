/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:53:49 by egaliber          #+#    #+#             */
/*   Updated: 2021/12/18 13:58:46 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_start(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_get_end(const char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (i);
		i--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*res;

	if (!s)
		return (NULL);
	start = ft_get_start(s);
	end = ft_get_end(s);
	if (end == -1 || start == -1)
		return (ft_strnew(0));
	res = ft_strsub(s, start, end - start + 1);
	return (res);
}
