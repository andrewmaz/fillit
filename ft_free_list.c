/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:56:35 by amazurok          #+#    #+#             */
/*   Updated: 2017/11/21 17:57:14 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_list(t_list *lst)
{
	t_list *head;

	while (lst)
	{
		head = lst->next;
		free(lst->x);
		free(lst->y);
		free(lst);
		lst = head;
	}
}
