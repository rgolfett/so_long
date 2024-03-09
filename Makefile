NAME = so_long

SRCS = main.c

INCLUDES =	

OBJS =	$(SRCS:%.c=%.o)

CC = cc

CFLAGS = -Wall -Wextra -g -Iminilibx-linux

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
		