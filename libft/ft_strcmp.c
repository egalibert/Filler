/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:54:58 by egaliber          #+#    #+#             */
/*   Updated: 2021/11/29 10:55:01 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (s1[a] != '\0' && s2[b] != '\0' && s1[a] == s2[b])
	{
		a++;
		b++;
	}
	return ((unsigned char)s1[a] - (unsigned char)s2[b]);
}
