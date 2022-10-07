/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:00:30 by egaliber          #+#    #+#             */
/*   Updated: 2021/12/15 13:14:30 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline const char	*ft_skip(char const *s, char c)
{
	while (*s != '\0' && *s == c)
		s++;
	return (s);
}

static inline size_t	ft_len_word(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static inline size_t	ft_all_words(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	while (*s != '\0')
	{
		s = ft_skip(s, c);
		n = ft_len_word(s, c);
		if (n == 0)
			return (i);
		i++;
		s += n;
	}
	return (i);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**arrstr;
	size_t	i;
	size_t	n;
	size_t	m;

	if (s == NULL)
		return (NULL);
	i = 0;
	n = ft_all_words(s, c);
	arrstr = (char **)ft_memalloc((n + 1) * sizeof(char *));
	if (arrstr == NULL)
		return (NULL);
	while (i < n)
	{
		s = ft_skip(s, c);
		m = ft_len_word(s, c);
		arrstr[i] = ft_strnew(m);
		if (arrstr == NULL)
			return (NULL);
		arrstr[i] = ft_strncpy(arrstr[i], s, m);
		s += m;
		i++;
	}
	return (arrstr);
}
