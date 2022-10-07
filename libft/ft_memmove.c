/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:47:16 by egaliber          #+#    #+#             */
/*   Updated: 2021/12/15 12:48:25 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	size_t			o;
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	o = 0;
	i = 0;
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	while (i < len)
	{
		if (dst == src + i)
			o = i;
		i++;
	}
	if (o == 0)
		return (ft_memcpy(dst, src, len));
	i = 0;
	while (i < len)
	{
		*(tmp_dst + len - 1 - i) = *(tmp_src + len - 1 - i);
		i++;
	}
	return (dst);
}
