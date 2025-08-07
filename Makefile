# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenini- <your@mail.com>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 17:03:00 by fbenini-          #+#    #+#              #
#    Updated: 2025/08/06 20:58:22 by fbenini-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printchar.c ft_printnbr.c ft_printstr.c ft_parse_special.c

LIBFT_DIR = ./libft

CFLAGS = -Wall -Wextra -Werror

HDRS = ft_printf.h

LIBFT = $(LIBFT_DIR)/libft.a

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I.$(HDRS) -c $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) bonus -C $(LIBFT_DIR)
	@cp $(LIBFT) .
	@mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJS)

fclean: clean
	find . -type f | xargs touch
	@$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean $(NAME)

bonus: $(NAME)

.PHONY: all re fclean clean bonus
