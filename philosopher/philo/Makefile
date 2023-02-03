# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 05:37:36 by enogawa           #+#    #+#              #
#    Updated: 2023/02/03 13:36:58 by enogawa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo

SRCS			=	$(shell find . -name "*.c")

OBJS			=	$(SRCS:.c=.o)

INCLUDE			=	-I include

CC		  		=	cc

CFLAGS			=	-Wall -Wextra -Werror -pthread
THREAD_FLAGS	=	-g -fsanitize=thread 

.c.o:			  $(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME):		  $(OBJS)
					 $(CC) $(CFLAGS) -o $(NAME) $(OBJS)

PHONY			=  all
all:				$(NAME)

PHONY			+= clean
clean:		
					 $(RM) $(OBJS)

PHONY			+= fclean
fclean:	clean
					 $(RM) $(NAME)

PHONY			+= re
re:	 fclean all

PHONY			+= thread
thread:			CFLAGS += $(THREAD_FLAGS)
thread:			re

.PHONY:	$(PHONY)