# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/05 17:32:59 by ktombola          #+#    #+#              #
#    Updated: 2025/06/06 17:50:29 by ktombola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = main.c push_swap_utils.c push_swap_utils1.c push_swap_utils2.c \
		push_swap_utils3.c push_swap_utils4.c push_swap_utils5.c \
		operations.c operations2.c operations3.c
OBJ = $(SRC:.c=.o)

CC = cc
CCFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes -Ilibft

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	$(CC) $(CCFLAGS) $(OBJ) -Llibft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re libft