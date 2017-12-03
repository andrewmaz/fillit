/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:29:27 by oshvorak          #+#    #+#             */
/*   Updated: 2017/11/21 13:01:05 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_correction_coor(t_list *head)
{
	int		i;
	t_list	*lst;

	lst = head;
	while (lst)
	{
		while (lst->x[0] > 0 && lst->x[1] > 0 && lst->x[2] > 0 && lst->x[3] > 0)
		{
			i = 0;
			while (i < NUM_HASH)
				lst->x[i++] -= 1;
		}
		while (lst->y[0] > 0 && lst->y[1] > 0 && lst->y[2] > 0 && lst->y[3] > 0)
		{
			i = 0;
			while (i < NUM_HASH)
				lst->y[i++] -= 1;
		}
		lst = lst->next;
	}
}

static void		ft_rec_coor(char **arr, int *x, int *y, t_list *qw)
{
	int i;
	int j;
	int r;
	int k;

	i = 0;
	while (arr[i])
	{
		r = 0;
		j = 0;
		k = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '\n')
				r++;
			if (arr[i][j] == '#')
			{
				x[k] = j % 5;
				y[k++] = r;
			}
			j++;
		}
		ft_list_push_back(&qw, ft_lstnew(x, y, 'A' + i++));
	}
}

t_list			*ft_arr_to_list(char **arr)
{
	t_list	*qw;
	t_list	*q;
	int		x[4];
	int		y[4];

	qw = (t_list*)ft_memalloc(sizeof(t_list));
	q = qw;
	ft_rec_coor(arr, x, y, qw);
	ft_correction_coor(q->next);
	return (q->next);
}
