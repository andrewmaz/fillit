/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:02:49 by amazurok          #+#    #+#             */
/*   Updated: 2017/11/21 13:18:35 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_check_count(char **arr)
{
	int i;
	int j;
	int num;

	i = 0;
	num = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '#')
				num++;
			j++;
		}
		if (num != NUM_HASH)
			ft_error();
		num = 0;
		i++;
	}
}

static void		ft_check_connect(char *arr, int i)
{
	if (i - 1 >= 0 && arr[i - 1] == '#')
		return ;
	if (i + 1 < SIZE_ELEM && arr[i + 1] == '#')
		return ;
	if (i - 5 >= 0 && arr[i - 5] == '#')
		return ;
	if (i + 5 < SIZE_ELEM && arr[i + 5] == '#')
		return ;
	ft_error();
}

static int		ft_check_double_connect(char *arr, int i)
{
	int num;

	num = 0;
	if (i - 1 >= 0 && arr[i - 1] == '#')
		num++;
	if (i + 1 < SIZE_ELEM && arr[i + 1] == '#')
		num++;
	if (i - 5 >= 0 && arr[i - 5] == '#')
		num++;
	if (i + 5 < SIZE_ELEM && arr[i + 5] == '#')
		num++;
	return (num);
}

static void		ft_check_arr(char *arr)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (arr[i])
	{
		if (arr[i] == '#')
			ft_check_connect(arr, i);
		i++;
	}
	i = 0;
	while (arr[i])
	{
		if (arr[i] == '#')
			if ((num = ft_check_double_connect(arr, i)) > 1)
				return ;
		i++;
	}
	ft_error();
}

void			ft_check_valid(char **arr)
{
	int i;

	ft_check_count(arr);
	i = 0;
	while (arr[i])
		ft_check_arr(arr[i++]);
}
