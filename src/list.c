/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c    	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <guillaume.badi@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 23:22:34 by gbadi             #+#    #+#             */
/*   Updated: 2014/09/03 20:07:29 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./list.h"

void				ft_print_list(t_node *begin)
{
	t_node		*current;

	current = begin;
	ft_putchar('(');
	while (current != NULL)
	{
		if (current->data != NULL)
		{
			ft_putchar('\"');
			ft_putstr(current->data);
			ft_putchar('\"');
		}
		if (current->next != NULL)
		{
			ft_putstr(", ");
		}
		current = current->next;
	}
	ft_putchar(')');
	ft_putchar('\n');
}

t_node				*ft_create_node(char *data)
{
	t_node		*node;

	node = (t_node *)malloc(sizeof(t_node *));
	if (node == NULL)
		return (0);
	node->next = NULL;
	if (data != NULL)
		node->data = ft_strdup(data);
	else
	{
		node->data = NULL;
	}
	return (node);
}

t_node				*ft_unshift(t_node *begin, char *data)
{
	t_node		*node;

	node = ft_create_node(data);
	node->next = begin;
	return (node);
}

t_node				*ft_push(t_node *begin, char *data)
{
	t_node		*node;
	t_node		*current;

	node = ft_create_node(data);
	current = begin;
	while (current->next != NULL)
		current = current->next;
	current->next = node;
	return (begin);
}

int					list_length(t_node *node)
{
	int			i;
	t_node		*current;

	i = 0;
	current = node;
	while (current != NULL)
	{
		i += 1;
		current = current->next;
	}
	return (i);
}

char				*ft_list_get(t_node *node, int index)
{
	t_node		*current;
	int			i;

	current = node;
	i = 0;
	while (i < index)
	{
		current = current->next;
		i++;
	}
	return (current->data);
}

t_node				*ft_list_replace(t_node *node, int index, char *data)
{
	t_node		*current;
	int			i;

	current = node;
	i = 0;
	while (i < index)
	{
		current = current->next;
		i++;
	}
	current->data = ft_strdup(data);
	return (node);
}

t_node				*ft_list_set(t_node *node, int index, char *data)
{
	t_node		*current;

	current = node;
	if (index <= list_length(current) + 1)
	{
		ft_list_replace(node, index, data);
		return (node);
	}
	else
	{
		ft_push(node, 0);
		return (ft_list_set(node, index, data));
	}
}

t_node				*ft_shift(t_node *begin)
{
	t_node		*node;

	node = begin->next;
	begin->next = NULL;
	free(begin);
	begin = node;
	return (begin);
}

t_node				*ft_pop(t_node *begin)
{
	t_node		*current;
	
	current = begin;
	while (current->next->next != NULL)
		current = current->next;
	current->next = NULL;
	free(current->next);
	current->next = NULL;
	return (begin);
}

int					ft_indexOf(t_node *node, char *data)
{
	t_node		*current;
	int			len;

	current = node;
	len = list_length(node) - 1;
	while (current != NULL)
	{
		if (ft_strcmp(current->data, data) == 0)
			return (len);
		current = current->next;
		len--;
	}
	return (-1);
}
