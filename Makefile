NAME = so_long

SRCS = main.c \
	ft_memset.c \
	ft_memcmp.c \
	ft_strchr.c \
	ft_putnbr_fd.c \
	ft_parsing.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_map.c \
	ft_texture.c \
	ft_map_parsing.c \
	ft_map_composure_parsing.c \
	ft_draw.c \
	ft_key_press.c \
	ft_free.c \
	ft_img.c \
	ft_exit.c \

INCLUDES =	

OBJS =	$(SRCS:%.c=%.o)

CC = cc

CFLAGS = -Wall -Wextra -g -Iminilibx-linux -fsanitize=address

all : $(NAME)

$(NAME) : $(OBJS) minilibx-linux/libmlx.a
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Lminilibx-linux -lmlx -lm -lXext -lX11

minilibx-linux/libmlx.a :
		$(MAKE) -C minilibx-linux

clean :
		rm $(OBJS) 
		$(MAKE) clean -C minilibx-linux

fclean : clean 
		rm $(NAME)

re : fclean all

%.o : %.c $(INCLUDES)
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY = all clean fclean re
		