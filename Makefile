#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: gbadi <guillaume.badi@gmail.com>           +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2014/08/06 02:16:20 by gbadi             #+#    #+#             *#
#*   Updated: 2014/08/06 21:56:11 by gbadi            ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =		prompt

SOURCE =	src/main.c \
			src/list.c \
			src/ft_prompt.c \
			src/ft_parse.c \
			lib/ft_putchar.c \
			lib/ft_putstr.c \
			lib/ft_strcmp.c \
			lib/ft_strdup.c \
			lib/ft_strlen.c \
			lib/ft_putnbr.c

FLAGS =		-Wall -Werror -Wextra

all:
	gcc $(FLAGS) -o $(NAME) -I./includes $(SOURCE) 

noflag:
	gcc -o $(NAME) $(SOURCE)

clean:
	rm $(NAME)

re: clean all
