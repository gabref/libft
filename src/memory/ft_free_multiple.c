/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_multiple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 00:58:52 by galves-f          #+#    #+#             */
/*   Updated: 2024/03/04 01:00:57 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_free_multiple(int n, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, n);
	while (i < n)
	{
		free(va_arg(args, void *));
		i++;
	}
	va_end(args);
}
