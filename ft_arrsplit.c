/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 11:50:46 by oshvorak          #+#    #+#             */
/*   Updated: 2017/11/16 14:31:59 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		elem_count(char *str)
{
	int num;

	num = 0;
	while (*str)
	{
		if ((*str == '\n' && (*(str + 1)) == '\n') || (*(str + 1) == '\0'))
			num++;
		str++;
	}
	return (num);
}

char			**ft_arrsplit(char *str)
{
	int		i;
	int		j;
	int		start;
	char	**arr;

	i = 0;
	j = 0;
	if (str == NULL)
		ft_error();
	if (!(arr = (char**)malloc(sizeof(char*) * (elem_count(str) + 1))))
		ft_error();
	start = 0;
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == '\n' && ((str[i + 1] == '\n') || (str[i + 1] == '\0')))
		{
			arr[j++] = ft_strsub(str, start, SIZE_ELEM - 1);
			i++;
			start = i + 1;
		}
		i++;
		((j > 26) ? ft_error() : 0);
	}
	arr[j] = NULL;
	return (arr);
}
