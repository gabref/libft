/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_is_between_char.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:56:39 by galves-f          #+#    #+#             */
/*   Updated: 2024/08/23 13:38:32 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_is_between_char(char *input, char *sub_input, char c)
{
	int	i;

	i = 0;
	while (input[i] && input[i] != c)
		i++;
	if (input[i] != c)
		return (false);
	while (input[i] && &input[i] != sub_input)
		i++;
	if (&input[i] != sub_input)
		return (false);
	while (input[i] && input[i] != c)
		i++;
	if (input[i] != c)
		return (false);
	return (true);
}
