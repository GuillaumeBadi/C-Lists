/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <guillaume.badi@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 23:30:49 by gbadi             #+#    #+#             */
/*   Updated: 2014/09/03 20:07:49 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_node
{
	struct s_node	*next;
	char			*data;
}					t_node;

int					ft_strcmp(char *s1, char *s2);
int					list_length(t_node *node);
int					ft_indexOf(t_node *node, char *data);
int					ft_strlen(char *str);
char				*ft_prompt(char *message);
char				*ft_strdup(char *str);
char				*ft_str_space_dup(char *str);
char				*ft_list_get(t_node *node, int index);
void				ft_print_reversed(t_node *node);
void				ft_print_list(t_node *begin);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int number);
t_node				*ft_create_node(char *data);
t_node				*ft_list_set(t_node *node, int index, char *value);
t_node				*ft_parse(char *str);
t_node				*ft_push(t_node *begin, char *data);
t_node				*ft_unshift(t_node *begin, char *data);
t_node				*ft_pop(t_node *begin);
t_node				*ft_shift(t_node *begin);


#endif
