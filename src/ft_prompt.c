/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <guillaume.badi@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/06 01:15:17 by gbadi             #+#    #+#             */
/*   Updated: 2014/08/06 21:28:05 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/list.h"

/*
 * *
 * * This function simply display a message, read on fd 0, delete the '\n' and
 * * return the string element.
 * *
 * * Usage: 
 * * char	*name;
 * * name = ft_prompt("What is your name ? : ");
 * *
 */
char		*ft_prompt(char *message)
{
	int		ret;
	char	buffer[50];

	ft_putstr(message);
	ret = read(0, buffer, 50);
	buffer[ret - 1] = '\0';
	return (ft_strdup(buffer));
}
