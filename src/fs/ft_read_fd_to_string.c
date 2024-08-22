/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd_to_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:19:15 by galves-f          #+#    #+#             */
/*   Updated: 2024/08/22 13:57:53 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_read_fd_to_string(int fd)
{
	char	*fd_as_string;
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	fd_as_string = ft_strdup("");
	while (line != NULL)
	{
		tmp = fd_as_string;
		fd_as_string = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
		line = get_next_line(fd);
	}
	return (fd_as_string);
}
