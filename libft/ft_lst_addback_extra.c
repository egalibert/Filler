/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addback_extra.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:18:51 by egaliber          #+#    #+#             */
/*   Updated: 2021/12/16 16:52:06 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_addback(t_list **head, t_list *new)
{
	t_list	*temp;

	if (!head || !new)
		return ;
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}
