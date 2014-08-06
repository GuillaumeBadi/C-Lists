/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <guillaume.badi@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/06 16:42:04 by gbadi             #+#    #+#             */
/*   Updated: 2014/08/06 21:55:16 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/list.h"

int			main(void)
{
	t_node		*command;
	char		*str;

	str = ft_prompt("command: ");
	command = ft_parse(str);
	command = ft_list_set(command, 4, "Hello");
	ft_print_list(command);
	return (0);
}
