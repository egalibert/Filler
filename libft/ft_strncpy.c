/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:18:09 by egaliber          #+#    #+#             */
/*   Updated: 2021/12/15 12:51:28 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	a;

	a = 0;
	while (src[a] != '\0' && a < n)
	{
		dst[a] = src[a];
		a++;
	}
	while (a < n)
	{
		dst[a] = '\0';
		a++;
	}
	return (dst);
}
