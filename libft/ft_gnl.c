/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:31:42 by sehjang           #+#    #+#             */
/*   Updated: 2022/12/13 14:22:28 by sunwchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*new;

	buf = (char *)malloc(10000000);
	new = buf;
	while (read(fd, new, 1) > 0 && *new++ != '\n')
		;
	if (new > buf)
		*new = 0;
	else
	{
		free(buf);
		return (NULL);
	}
	new = ft_strdup(buf);
	free(buf);
	return (new);
}
