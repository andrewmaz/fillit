/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:36:54 by oshvorak          #+#    #+#             */
/*   Updated: 2017/11/21 18:02:14 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_fill(char **frame, size_t size, t_list *elem)
{
	int		xy[2];

	xy[0] = 0;
	xy[1] = 0;
	frame = ft_frame_fill(frame, elem, xy, size);
	return (frame);
}

char			**ft_create_tetris(size_t size, t_list *elem)
{
	char	**frame;
	t_list	*head;

	head = elem;
	frame = NULL;
	while (!frame)
	{
		if (frame)
			ft_free_frame(frame);
		frame = ft_create_frame(size);
		frame = ft_fill(frame, size, head);
		size++;
	}
	return (frame);
}
