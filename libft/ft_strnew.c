/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:55:31 by egaliber          #+#    #+#             */
/*   Updated: 2022/09/24 14:23:05 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*t;

	t = (char *)malloc(sizeof(*t) * (size + 1));
	if (!t)
		return (NULL);
	ft_memset(t, '\0', size + 1);
	return (t);
}
