# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 05:37:36 by enogawa           #+#    #+#              #
#    Updated: 2023/01/25 10:56:47 by enogawa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo

SRCS			=	$(shell find . -name "*.c")

OBJS			=	$(SRCS:.c=.o)

INCLUDE			=	-I include

CC		  		=	cc

CFLAGS			=	-Wall -Wextra -Werror -pthread #-fsanitize=thread

# DEBUG_FLAGS 	 =	-g -fsanitize=address -fsanitize=undefined -pthread
# THREAD_FLAGS	 =	-g -fsanitize=undefined -fsanitize=thread -pthread

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

# PHONY			+= debug
# debug:		CFLAGS += $(DEBUG_FLAGS)
# debug:		re

# PHONY			+= thread
# thread:	CFLAGS +=	 $(THREAD_FLAGS)
# thread:	re

.PHONY:	$(PHONY)