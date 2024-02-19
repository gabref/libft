/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isword.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:31:34 by galves-f          #+#    #+#             */
/*   Updated: 2024/02/19 19:37:29 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isword(char *str, char *charset)
{
	int	i;
	int	j;
	int	size_str;
	int	size_charset;

	if (!str || !charset)
		return (0);
	size_str = ft_strlen(str);
	size_charset = ft_strlen(charset);
	if (size_str < size_charset)
		return (0);
	i = 0;
	j = 0;
	while (str[i] && charset[j] && str[i] == charset[j])
	{
		i++;
		j++;
	}
	if (j == size_charset)
		return (1);
	return (0);
}
