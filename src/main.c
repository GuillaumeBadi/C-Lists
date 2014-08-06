/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <guillaume.badi@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/06 16:42:04 by gbadi             #+#    #+#             */
/*   Updated: 2014/08/06 22:26:24 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/list.h"

int			main(void)
{
	t_node		*command;
	char		*str;

	str = ft_prompt("command: ");
	command = ft_parse(str);
	printf("%d\n", ft_indexOf(command, "guillaume"));
	ft_print_list(command);
	return (0);
}
