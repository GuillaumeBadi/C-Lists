/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <guillaume.badi@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/06 02:26:15 by gbadi             #+#    #+#             */
/*   Updated: 2014/08/06 22:24:50 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/list.h"

int			ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	printf("input s1\t%s\n", s1);
	printf("input s2\t%s\n", s2);
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL || s2 == NULL)
		return (1);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			printf("char de discorde\t%c\n", s1[i]);
			return (s1[i] - s2[i]);
		}
		i++;
	}
	printf("%s\n", "same");
	return (0);
}	
