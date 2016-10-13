# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oexall <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/26 10:23:10 by oexall            #+#    #+#              #
#    Updated: 2016/10/12 08:49:35 by kchetty          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ExpertSystem

CC= g++
CFLAGS= -Wall -Werror -Wextra -std=c++11
HEADERS= -I ./include

SP= ./srcs/

SRC= $(SP)main.cpp $(SP)save_data.cpp $(SP)process.cpp $(SP)solve_queries.cpp

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(HEADERS)

clean:
	rm $(NAME)

fclean: clean

re: fclean all
