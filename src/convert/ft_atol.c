/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 00:54:59 by galves-f          #+#    #+#             */
/*   Updated: 2024/03/04 00:55:08 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

long	ft_atol(const char *str)
{
	int			i;
	long long	n;
	int			s;

	i = 0;
	n = 0;
	s = 1;
	while (((str[i] >= '\011') && (str[i] <= '\015')) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			s = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((n * 10 + (str[i] - '0')) / 10 != n && s == -1)
			return (0);
		else if ((n * 10 + (str[i] - '0')) / 10 != n)
			return (0);
		n = n * 10 + str[i] - '0';
		i++;
	}
	return ((long)(n * s));
}
