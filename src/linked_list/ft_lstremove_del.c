/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:13:13 by galves-f          #+#    #+#             */
/*   Updated: 2024/03/13 15:14:17 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/libft.h"

void ft_lstremove_del(t_list **lst, t_list *node, void (*del)(void*))
{
	t_list	*prev;
	t_list	*curr;

	if (!lst || !*lst || !node)
		return ;
	prev = NULL;
	curr = *lst;
	while (curr)
	{
		if (curr == node)
		{
			if (prev)
				prev->next = curr->next;
			else
				*lst = curr->next;
			ft_lstdelone(curr, del);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}
