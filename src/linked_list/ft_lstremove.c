/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:05:25 by galves-f          #+#    #+#             */
/*   Updated: 2024/03/13 15:12:19 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/libft.h"

void ft_lstremove(t_list **lst, t_list *node)
{
	t_list	*prev;
	t_list	*curr;

	if (!lst || !*lst || !node)
		return ;
	if (*lst == node)
	{
		*lst = node->next;
		return ;
	}
	prev = *lst;
	curr = prev->next;
	while (curr)
	{
		if (curr == node)
		{
			prev->next = curr->next;
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}
