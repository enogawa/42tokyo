NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
ft_printf_materials.c \
ft_printf_materials2.c \
ft_printf_materials3.c \

OBJS = $(SRCS:.c=.o)

# LIBFT_DIR = ./libft
# LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) #$(LIBFT)
# 	cp $(LIBFT) ./$(NAME)
	ar -rcs $(NAME) $(OBJS)

# $(LIBFT):
# 	make -C $(LIBFT_DIR)
	
clean:
#	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
#	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re