/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <guillaume.badi@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/06 02:03:28 by gbadi             #+#    #+#             */
/*   Updated: 2014/08/06 21:59:45 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/list.h"


/*
 * *
 * * return the number of characters before the next space
 * *
 */
int			ft_len_space(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	return (i);
}

/*
 * *
 * * return the number of words
 * *
 */
int			ft_count_words(char *str)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != ' ' && str[i - 1] == ' ') || (i == 0 && str[i] != ' '))
			counter++;
		i++;
	}
	return (counter);
}

/*
 * *
 * * return the next word as a string
 * *
 */
char		*ft_get_word(char *str)
{
	char		*copy;
	int			i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	copy = ft_str_space_dup(str + i);
	return (copy);
}

/*
 * *
 * * return a list of words
 * * The first element is a 0 charactere
 * *
 */
t_node		*ft_parse(char *str)
{
	t_node		*node;
	int			i;
	int			len;
	char		*word;
	int			count;

	i = 0;
	len = 0;
	count = ft_count_words(str);
	if (count < 1)
		return (NULL);
	else
	{
		str = str + len;
		len = ft_len_space(str);
		word = ft_get_word(str);
		node = ft_create_node(word);
		i++;
	}
	while (i < count)
	{
		str = str + len;
		len = ft_len_space(str);
		word = ft_get_word(str);
		node = ft_push(node, word);
		i++;
	}
	return (node);
}
