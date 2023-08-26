# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 16:59:22 by changhyl          #+#    #+#              #
#    Updated: 2023/08/26 14:53:19 by changhyl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CFLAGS = -Wall -Wextra -Werror
#DEBUG_FLAGS = -g -fsanitize=thread
CC = cc
SRCS = arg.c ft_atoi.c run.c cycle.c init.c utils.c main.c
OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $^ -o $@

clean:
	rm -f $(OBJS)
	
fclean:	clean
	rm -f $(NAME)

re:
	$(MAKE)	fclean
	$(MAKE)	all

.PHONY: all clean fclean re
