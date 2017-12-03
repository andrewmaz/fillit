/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:22:03 by amazurok          #+#    #+#             */
/*   Updated: 2017/11/21 15:09:14 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_search_sym(t_list *lst, char c)
{
	t_list *head;

	head = lst;
	while (head->sym != c)
		head = head->next;
	return (head);
}

int		ft_search_x(char **p, char c, size_t size)
{
	int i;
	int j;

	i = (int)size;
	while (--i >= 0)
	{
		j = -1;
		while (p[i][++j])
			if (p[i][j] == c)
				return (j);
	}
	return (0);
}

int		ft_search_y(char **p, char c)
{
	int i;
	int j;

	i = -1;
	while (p[++i])
	{
		j = -1;
		while (p[i][++j])
			if (p[i][j] == c)
				return (i);
	}
	return (0);
}
