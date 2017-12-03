/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:32:18 by oshvorak          #+#    #+#             */
/*   Updated: 2017/11/21 13:01:53 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_lstnew(int *x, int *y, char sym)
{
	t_list	*list;
	int		i;

	i = 0;
	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!x || !y)
	{
		list->x = NULL;
		list->y = NULL;
	}
	else
	{
		list->x = (int*)malloc(sizeof(int) * NUM_HASH);
		list->y = (int*)malloc(sizeof(int) * NUM_HASH);
		while (i < NUM_HASH)
		{
			list->x[i] = x[i];
			list->y[i] = y[i];
			i++;
		}
		list->sym = sym;
		list->next = NULL;
	}
	return (list);
}
