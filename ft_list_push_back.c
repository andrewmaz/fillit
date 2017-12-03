/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:44:31 by oshvorak          #+#    #+#             */
/*   Updated: 2017/11/16 16:52:55 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_list_push_back(t_list **list, t_list *end)
{
	t_list *new;

	if (!(*list))
		*list = end;
	else if (*list)
	{
		new = (*list);
		while (new->next)
			new = new->next;
		new->next = end;
	}
}
