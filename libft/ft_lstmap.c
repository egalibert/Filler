/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:02:01 by elliotgalib       #+#    #+#             */
/*   Updated: 2021/12/15 12:46:07 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	recurse(t_list *lst, t_list *(*f)(t_list *elem), t_list **new)
{
	if (lst)
	{
		*new = f(lst);
		recurse(lst->next, f, &((*new)->next));
	}
	else
		*new = NULL;
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = NULL;
	recurse(lst, f, &new);
	return (new);
}
