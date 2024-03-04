/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 00:33:26 by galves-f          #+#    #+#             */
/*   Updated: 2024/03/04 00:33:51 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_pow(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	else if (power > 1)
	{
		power--;
		nb *= ft_pow(nb, power);
	}
	return (nb);
}
