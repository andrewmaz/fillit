/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:40:38 by oshvorak          #+#    #+#             */
/*   Updated: 2017/11/21 19:56:27 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# define SIZE_ELEM 20
# define NUM_HASH 4
# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_list
{
	int				*x;
	int				*y;
	char			sym;
	struct s_list	*next;
}					t_list;

char				*ft_realloc(char *str, int size);
char				**ft_arrsplit(char *str);
void				*ft_error(void);
char				*ft_read(char *file_name);
void				ft_check_format(char *str);
void				ft_check_valid(char **arr);
char				**ft_create_frame(size_t size);
void				ft_free_frame(char **frame);
int					fcheck(char **f, t_list *e, int x, int y);
int					fsize(t_list *elem, int x, int y, size_t s);
void				ft_write_elem(char **frame, t_list *elem, int x, int y);
t_list				*ft_search_sym(t_list *lst, char c);
int					ft_search_x(char **p, char c, size_t size);
int					ft_search_y(char **p, char c);
t_list				*ft_lstnew(int *x, int *y, char sym);
t_list				*ft_arr_to_list(char **arr);
void				ft_list_push_back(t_list **list, t_list *new);
size_t				ft_lstlen(t_list *lst);
size_t				ft_size_map(t_list *lst);
char				**ft_create_tetris(size_t size, t_list *elem);
char				**ft_frame_fill(char **fr, t_list *el, int *xy, size_t sz);
void				ft_free_list(t_list *lst);
void				ft_usage(void);

#endif
