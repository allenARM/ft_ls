INCLUDES = -I ft_ls.h
SRCS = ./srcs/*
UTILS = ./utils/*
NAME = ft_ls

$(NAME):
	make -C libft
	gcc -Wall -Wextra -Werror main.c $(SRCS) $(UTILS) $(INCLUDES) -o $(NAME) libft/libft.a

all: $(NAME)

clean:
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
