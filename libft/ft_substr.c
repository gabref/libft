/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:17:45 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/08 15:28:05 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*newstr;
	int				i;
	int				size;
	unsigned int	original_size;

	if (s == NULL)
		return (NULL);
	original_size = ft_strlen(s);
	if (start >= original_size)
		return (ft_strdup(""));
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	size = (int)len;
	while (s[start] && size-- > 0)
		newstr[i++] = s[start++];
	newstr[i] = '\0';
	return (newstr);
}
