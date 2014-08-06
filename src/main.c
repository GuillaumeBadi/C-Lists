/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <guillaume.badi@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/06 16:42:04 by gbadi             #+#    #+#             */
/*   Updated: 2014/08/07 00:17:34 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/list.h"

int		main(void)
{
	char		*str;
	t_node		*list;

	str = ft_prompt("type a random string: ");
	list = ft_parse(str);
	list = ft_push(list, "bitch!!");
	ft_print_list(list);

	return (0);
}
