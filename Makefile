# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenini- <your@mail.com>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 17:03:00 by fbenini-          #+#    #+#              #
#    Updated: 2025/07/26 18:06:42 by fbenini-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c ft_parse_special.c ft_special_flags.c

LIBFT_DIR = ./libft

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

re: fclean
	$(NAME)

bonus: $(NAME)

.PHONY: all re fclean clean bonus
