CC = cc
CFLAGS = -O3 -Wall -Wextra -Werror -g
MLXFLAGS = -lmlx -lXext -lX11
NAME = so_long

LIBFT = libs/libft
LIBFTPRINTF = libs/libft/ft_printf
LIBX = libs/minilibx

SRCS = display.c error.c main.c mapcheck.c utils.c utils_body.c ff.c event.c finish.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT) -s all
	@$(MAKE) -C $(LIBFTPRINTF) -s all
	@$(MAKE) -C $(LIBX) -s all
	@$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT) -lftprintf -L $(LIBFTPRINTF) -lft -L $(LIBX) $(MLXFLAGS) -o $(NAME)


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT) -s fclean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
