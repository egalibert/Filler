/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:14:23 by egaliber          #+#    #+#             */
/*   Updated: 2021/11/16 11:03:53 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*save_s1;
	char	*save_s2;

	save_s1 = (char *)s1;
	save_s2 = (char *)s2;
	while (n != 0 && (unsigned char)*save_s1 == (unsigned char)*save_s2)
	{
		n--;
		save_s1++;
		save_s2++;
	}
	if (n == 0)
		return (0);
	else
		return ((unsigned char)*save_s1 - (unsigned char)*save_s2);
}
