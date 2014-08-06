/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <guillaume.badi@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/06 02:26:15 by gbadi             #+#    #+#             */
/*   Updated: 2014/08/06 20:56:25 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/list.h"

char		*ft_strdup(char *str)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
 ** this simply duplicate the string from 0 to the first space.
 ** i.e.: "Hello World!" => "Hello"
*/
char		*ft_str_space_dup(char *str)
{
	char	*copy;
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	copy = (char *)malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
