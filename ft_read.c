/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:02:30 by amazurok          #+#    #+#             */
/*   Updated: 2017/11/23 19:03:08 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read(char *file_name)
{
	int		i;
	int		fd;
	int		size;
	char	buf[1];
	char	*str;

	i = 0;
	size = 1;
	str = NULL;
	fd = open(file_name, O_RDONLY);
	(fd == -1) ? ft_error() : 0;
	while (read(fd, buf, 1) > 0)
	{
		if (!(str = ft_realloc(str, size++)))
			ft_error();
		str[i++] = buf[0];
	}
	read(fd, buf, 0) == -1 ? ft_usage() : 0;
	close(fd);
	if (!str)
		ft_error();
	str[i] = '\0';
	return (str);
}
