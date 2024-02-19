/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:56:39 by galves-f          #+#    #+#             */
/*   Updated: 2024/02/19 19:36:39 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	count_words(char *str, char *charset)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	if (*str && ft_isword(&str[i++], charset) == 0)
		words++;
	while (str[i])
	{
		if (str[i] && ft_isword(&str[i], charset) == 0 && ft_isword(&str[i - 1],
				charset))
			words++;
		i++;
	}
	return (words);
}

static void	fill(const char *s, char *charset, char **splitted, int words)
{
	int	start;
	int	end;
	int	c_word;
	int	ss;
	int	sc;

	c_word = 0;
	start = 0;
	end = 0;
	ss = ft_strlen(s);
	sc = ft_strlen(charset);
	while (c_word < words)
	{
		start = end;
		while (start <= ss && s[start] && ft_isword((char *)&s[start], charset))
			start += sc;
		end = start + 1;
		while (end <= ss && s[end] && ft_isword((char *)&s[end], charset) == 0)
			end++;
		splitted[c_word++] = ft_substr(s, start, end - start);
	}
	*(splitted + c_word) = NULL;
}

char	**ft_split_word(char const *s, char *charset)
{
	int		words;
	char	**splitted;

	if (s == NULL)
		return (NULL);
	words = count_words((char *)s, charset);
	splitted = (char **)malloc(sizeof(char *) * (words + 1));
	if (splitted == NULL)
		return (NULL);
	fill(s, charset, splitted, words);
	return (splitted);
}
