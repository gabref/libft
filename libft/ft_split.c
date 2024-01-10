/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:56:39 by galves-f          #+#    #+#             */
/*   Updated: 2024/01/10 12:44:27 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	if (*str && str[i++] != c)
		words++;
	while (str[i])
	{
		if (str[i] && str[i] != c && str[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**splitted;
	int		c_word;
	int		start_end[2];

	words = count_words((char *)s, c);
	splitted = (char **)malloc(sizeof(char *) * (words + 1));
	if (splitted == NULL)
		return (NULL);
	c_word = 0;
	start_end[0] = 0;
	start_end[1] = 0;
	while (c_word < words)
	{
		start_end[0] = start_end[1];
		while (s[start_end[0]] && s[start_end[0]] == c)
			start_end[0]++;
		start_end[1] = start_end[0] + 1;
		while (s[start_end[1]] && s[start_end[1]] != c)
			start_end[1]++;
		splitted[c_word++] = ft_substr((const char *)s, start_end[0], start_end[1] - start_end[0]);
	}
	*(splitted + c_word) = NULL;
	return (splitted);
}
