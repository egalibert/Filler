/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:29:21 by egaliber          #+#    #+#             */
/*   Updated: 2021/11/11 13:12:59 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	a;

	a = 0;
	while (src[a] != '\0')
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = src[a];
	return (dst);
}
