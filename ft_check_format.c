/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:59:30 by amazurok          #+#    #+#             */
/*   Updated: 2017/11/21 20:15:20 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check_format(char *str)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			ft_error();
		if ((j != SIZE_ELEM + 1 && j % 5 != 0) && str[i] == '\n')
			ft_error();
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0') \
			&& j != SIZE_ELEM)
			ft_error();
		if (j == SIZE_ELEM && (str[i + 1] != '\n' && str[i + 1] != '\0'))
			ft_error();
		if (j == SIZE_ELEM + 1 && str[i + 1] != '.' && str[i + 1] != '#')
			ft_error();
		if (str[i] != '\n' && str[i + 1] == '\0')
			ft_error();
		if (j == SIZE_ELEM + 1)
			j = 0;
		i++;
		j++;
	}
}
