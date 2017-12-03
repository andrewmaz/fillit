/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:41:37 by amazurok          #+#    #+#             */
/*   Updated: 2017/11/21 18:01:12 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		max_xy(int *cor)
{
	int i;
	int max;

	i = 1;
	max = 0;
	while (i < NUM_HASH)
	{
		if (cor[i] > cor[max])
			max = i;
		i++;
	}
	return (max);
}

static void		ft_free_elem(char **p, char c)
{
	int i;
	int j;

	i = -1;
	while (p[++i])
	{
		j = -1;
		while (p[i][++j])
			if (p[i][j] == c)
				p[i][j] = '.';
	}
}

static t_list	*ft_listback(char **frame, t_list *elem, t_list *head)
{
	ft_free_elem(frame, elem->sym - 1);
	return (ft_search_sym(head, elem->sym - 1));
}

static void		ft_set_xy(int *x, int *y, int n_x, int n_y)
{
	*x = n_x;
	*y = n_y;
}

char			**ft_frame_fill(char **frame, t_list *elem, int *xy, size_t sz)
{
	t_list	*head;

	head = elem;
	while (elem)
	{
		if (fsize(elem, xy[0], xy[1], sz) && fcheck(frame, elem, xy[0], xy[1]))
		{
			ft_write_elem(frame, elem, xy[0], xy[1]);
			ft_set_xy(&xy[0], &xy[1], 0, 0);
			((elem) ? elem = elem->next : 0);
		}
		else if (elem->x[max_xy(elem->x)] + xy[0] + 1 < (int)sz)
			xy[0]++;
		else if (elem->y[max_xy(elem->y)] + xy[1] + 1 < (int)sz)
			ft_set_xy(&xy[0], &xy[1], 0, xy[1] + 1);
		else
		{
			if (elem->sym - 1 < 'A')
				return (NULL);
			ft_set_xy(&xy[0], &xy[1], ft_search_x(frame, \
				elem->sym - 1, sz) + 1, ft_search_y(frame, elem->sym - 1));
			elem = ft_listback(frame, elem, head);
		}
	}
	return (frame);
}
