/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:02:17 by amazurok          #+#    #+#             */
/*   Updated: 2017/11/21 13:02:22 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_realloc(char *str, int size)
{
	char *nstr;

	if (!(nstr = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	ft_memcpy(nstr, str, --size);
	if (str)
		free(str);
	return (nstr);
}
