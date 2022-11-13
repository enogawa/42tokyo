# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 19:47:27 by enogawa           #+#    #+#              #
#    Updated: 2022/11/13 21:03:40 by enogawa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
cc		=	cc
CFLAGS	=	-Wall -Werror -Wextra

LIBFTDIR     =    libft
LIBFT        =    $(LIBFTDIR)/libft.a
LIB          =    $(LIBFT)

SRCS	=	src/check_args.c src/push_swap_utils.c src/push_swap.c src/radix_sort.c src/under6_sort.c\
			command/push.c command/reverse.c command/rotate.c command/swap.c\
			list_ope/list_mv_foot.c list_ope/list_mv_head.c list_ope/listnew.c list_ope/list_add_back.c


OBJS    =    ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) $(LIB) 
		$(CC) -o $(NAME) $(SRCS) $(LIB) $(CFLAGS)

$(LIBFT):
		$(MAKE) -C $(LIBFTDIR)

clean:
		$(MAKE) fclean -C $(LIBFTDIR)
		$(RM) ${OBJS}

fclean: clean
		$(RM) ${NAME}

re : fclean all

.PHONY:
		all clean fclean re 