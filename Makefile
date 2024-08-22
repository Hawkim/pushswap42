# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nal-haki <nal-haki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 10:18:51 by nal-haki          #+#    #+#              #
#    Updated: 2024/07/30 10:58:43 by nal-haki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	push_swap.c push_swap_utils.c instructions.c \
		sort.c sort_utils.c sort_big_utils.c

BSRCS = checker.c push_swap_utils.c instructions.c get_next_line.c

OBJS =	$(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: push_swap

bonus: push_swap checker

push_swap: $(OBJS) libft
	gcc -o $@ $(OBJS) -Llibft -lft

checker: $(BOBJS) libft
	gcc -o $@ $(BOBJS) -Llibft -lft

%.o: %.c
	gcc -c $(CFLAGS) $?

libft:
	make -C libft bonus

clean:
	rm -f $(OBJS) $(BOBJS)
	make -C libft clean

fclean: clean
	rm -f push_swap checker libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re
