/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c    	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <guillaume.badi@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 23:22:34 by gbadi             #+#    #+#             */
/*   Updated: 2014/08/06 23:07:45 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./list.h"

/*
 * *
 * * Cf ft_print_list();
 * *
 */
void				ft_print_reversed(t_node *node)
{
	if (node == NULL)
		return ;
	else
	{
		ft_print_reversed(node->next);
		if (node->next != NULL)
			ft_putstr(", ");
		if (node->data != NULL)
		{
			ft_putchar('"');
			ft_putstr(node->data);
			ft_putchar('"');
		}
		else
			ft_putstr("");
	}
}

/*
 * *
 * * This function prints a '(', prints recursively all the elements of the list
 * * in a reversed order, separated by commas, and prints a ')'
 * *
 * * Might be a better way
 */
void				ft_print_list(t_node *begin)
{
	ft_putchar('(');
	ft_print_reversed(begin);
	ft_putchar(')');
	ft_putchar('\n');
}

/*
 * *
 * * This function initializes a list element, makes it point to NULL and assigns it 
 * * a value.
 * *
 */
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

/*
 * * 
 * * This adds an element at the end of the list
 * *
 * * Usage:
 * * t_node		*list;
 * * list = ft_create_node("Hello");
 * * list = ft_push(list, "World!");
 * * => (Hello, World!)
 */
t_node				*ft_push(t_node *begin, char *data)
{
	t_node		*node;

	node = ft_create_node(data);
	node->next = begin;
	return (node);
}

/*
 * * 
 * * This adds an element at the beginning of the list
 * *
 * * Usage:
 * * t_node		*list;
 * * list = ft_create_node("Hello");
 * * list = ft_push(list, "World!");
 * * list = ft_unshift(list, "Hey!");
 * * => (Hey, Hello, World!)
 */
t_node				*ft_unshift(t_node *begin, char *data)
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

/*
 * *
 * * Well...
 * *
 */
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

/*
 * *
 * * This returns the value of the element at a given index of the list
 * * 
 * * Usage:
 * *
 * * t_node		*list;
 * * list = ft_create_node("Hello");
 * * list = ft_push(list, "World");
 * * list = ft_push(list, "my");
 * * list = ft_push(list, "name");
 * * list = ft_push(list, "is");
 * * list = ft_push(list, "Guillaume");
 * * 
 * * (Hello, 	World, 		my, 		name, 		is, 		Guillaume)
 * *	0		  1			 2			  3			 4				5
 * * name = ft_list_get(list, 5); => Guillaume :')
 */
void				*ft_list_get(t_node *node, int index)
{
	t_node		*current;
	int			len;

	current = node;
	len = list_length(node) - 1;
	while (len > index)
	{
		current = current->next;
		len--;
	}
	if (len != index)
	{
		return (NULL);
	}
	return (current->data);
}

/*
 * *
 * * Cf ft_list_set()
 * *
 */
t_node				*ft_list_replace(t_node *node, int index, char *data)
{
	t_node		*current;
	int			len;

	current = node;
	len = list_length(node) - 1;
	while (len > index)
	{
		current = current->next;
		len--;
	}
	current->data = ft_strdup((char *)data);
	return (node);
}

/*
 * *
 * * This function simply set (creates/replaces) an list element
 * * and fills the blanks with NULL
 * *
 * * It is a recursive function.
 * * If the position we want is greater than the (length - 1) (the position of the last element),
 * * we push a NULL node to the list, and call the function again with the newly created list.
 * * Else we replace the node->data with ft_list_replace
 * *
 * * Usage:
 * * (hello, world)
 * * 
 * * list = ft_list_set(list, 1, "guillaume") => (Hello, Guillaume)
 * * list = ft_list_set(list, 4, "42") => (Hello, Guillaume, , , 42)
 * *
 */
t_node				*ft_list_set(t_node *node, int index, char *data)
{
	if (index > list_length(node) - 1)
	{
		node = ft_push(node, NULL);
		return (ft_list_set(node, index, data));
	}
	else
	{
		node = ft_list_replace(node, index, data);
		return (node);
	}
}

/*
 * *
 * * THis removes the last element of the list
 * *
 */
t_node				*ft_pop(t_node *begin)
{
	t_node		*node;

	node = begin->next;
	begin->next = NULL;
	free(begin);
	begin = node;
	return (begin);
}

/*
 * * 
 * * This removes the first element of the list
 * * 
 */
t_node				*ft_shift(t_node *begin)
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

/*
 * *
 * * This function search for an occurence of a given element in the list, and returns its index
 * * It returns -1 if there's no occurence of the word;
 * * It's useful to test wether a string contains an option or a command
 */
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
