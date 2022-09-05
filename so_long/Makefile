# NAME   = so_long
#CC      =    cc
# CFLAGS = -Wall -Wextra -Werror
# SRCS   = args_error_handler.c ft_strlen_so_long.c map_error_handler.c\
# OBJS  = $(SRCS:.c=.o)


NAME         =    so_long
CC           =    cc
CFLAGS       =    -Wall -Werror -Wextra -I ./include

MLX_PATH     =    ./mlx_linux/
MLX_FLAG     =    -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
MLX_MAKE     =    $(MLX)
MLX          =    ./mlx_linux/libmlx_Darwin.a


LIBFTDIR     =    libft
LIBFT        =    $(LIBFTDIR)/libft.a
LIB          =    $(LIBFT)

GNL_SRC      =    ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
GNL_PATH     =    ./get_next_line/
GNL_OBJS     =    $(GNL_SRC:.c=.o)

SRCS         =    ./src/so_long.c ./src/args_error_handler.c ./src/ft_strlen_so_long.c ./src/map_error_handler.c \
				./src/put_gnl.c

OBJS         =    ${SRCS:.c=.o}


all: $(NAME)

$(NAME): $(OBJS) $(LIB) $(GNL_OBJS) 
		$(MAKE) -C $(MLX_PATH)
		$(CC) -o $(NAME) $(SRCS) $(GNL_OBJS) $(LIB) $(CFLAGS) $(MLX) $(MLX_FLAG)

$(LIBFT):
		$(MAKE) -C $(LIBFTDIR)

clean:
		$(MAKE) clean -C $(LIBFTDIR)
		$(RM) ${GNL_OBJS}
		$(RM) ${OBJS}
		$(MAKE) clean -C $(MLX_PATH)

fclean: clean
		$(MAKE) fclean -C $(LIBFTDIR)
		$(RM) ${NAME}
		$(RM) ${MLX}
re : fclean all

.PHONY:
		all clean fclean re 