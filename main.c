/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:25:37 by amazurok          #+#    #+#             */
/*   Updated: 2017/11/21 19:27:58 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_print_frame(char **frame)
{
	int i;

	i = 0;
	while (frame[i])
		ft_putendl(frame[i++]);
}

int				main(int argc, char *argv[])
{
	char	**frame;
	char	*str;
	char	**arr;
	t_list	*list;
	size_t	size;

	str = NULL;
	if (argc != 2)
		ft_usage();
	else
		str = ft_read(argv[1]);
	ft_check_format(str);
	arr = ft_arrsplit(str);
	(str) ? free(str) : 0;
	ft_check_valid(arr);
	list = ft_arr_to_list(arr);
	(arr) ? ft_free_frame(arr) : 0;
	size = ft_size_map(list);
	frame = ft_create_tetris(size, list);
	list ? ft_free_list(list) : 0;
	ft_print_frame(frame);
	(frame) ? ft_free_frame(frame) : 0;
	return (0);
}
