/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwchoi <sunwchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:34:55 by sunwchoi          #+#    #+#             */
/*   Updated: 2022/12/13 13:34:56 by sunwchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_text	*read_file(int fd)
{
	t_text	*text;

	text = (t_text *)malloc(sizeof(t_text));
	read_element(fd, text);
	text->map = read_map(fd);
	return (text);
}
