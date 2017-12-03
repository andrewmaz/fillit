/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:57:45 by amazurok          #+#    #+#             */
/*   Updated: 2017/11/21 18:19:05 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_create_frame(size_t size)
{
	size_t	i;
	char	**frame;

	frame = (char**)malloc(sizeof(char*) * (size + 1));
	i = 0;
	while (i < size)
	{
		frame[i] = ft_strnew(size);
		ft_memset(frame[i], '.', size);
		i++;
	}
	frame[i] = NULL;
	return (frame);
}

void		ft_free_frame(char **frame)
{
	size_t i;

	i = 0;
	if (!frame)
		return ;
	while (frame[i])
		free(frame[i++]);
	free(frame);
}

int			fcheck(char **f, t_list *elem, int x, int y)
{
	int i;

	i = -1;
	while (++i < NUM_HASH)
		if (f[elem->y[i] + y][elem->x[i] + x] != '.')
			return (FALSE);
	return (TRUE);
}

int			fsize(t_list *elem, int x, int y, size_t s)
{
	int i;

	i = -1;
	while (++i < NUM_HASH)
		if (elem->y[i] + y >= (int)s || elem->x[i] + x >= (int)s)
			return (FALSE);
	return (TRUE);
}

void		ft_write_elem(char **frame, t_list *elem, int x, int y)
{
	int i;

	i = -1;
	while (++i < NUM_HASH)
		frame[elem->y[i] + y][elem->x[i] + x] = elem->sym;
}
