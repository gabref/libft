/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 00:27:43 by galves-f          #+#    #+#             */
/*   Updated: 2024/03/04 00:30:31 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static char	*ft_allocate(char *str, int len, unsigned int n, unsigned int n_bak)
{
	if (n_bak == 0)
		len = 1;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	int				len;
	unsigned int	n_bak;

	n_bak = n;
	len = ft_nbrlen_base(n, 10);
	str = NULL;
	str = ft_allocate(str, len, n, n_bak);
	if (str == NULL)
		return (NULL);
	return (str);
}
