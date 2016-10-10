# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oexall <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/26 10:23:10 by oexall            #+#    #+#              #
#    Updated: 2016/09/27 15:03:34 by oexall           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ExpertSystem

CC= g++
CFLAGS= -Wall -Werror -Wextra
HEADERS= -I ./include

SP= ./srcs/

SRC= $(SP)main.cpp $(SP)process.cpp $(SP)strsplit.cpp

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(HEADERS)

clean:
	rm $(NAME)

fclean: clean

re: fclean all
