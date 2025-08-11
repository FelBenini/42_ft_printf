# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenini- <your@mail.com>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 17:03:00 by fbenini-          #+#    #+#              #
#    Updated: 2025/08/08 18:46:13 by fbenini-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c

BONUS_SRCS = ft_printf_bonus.c ft_printchar_bonus.c ft_printnbr_bonus.c \
			ft_printstr_bonus.c ft_printhex_bonus.c ft_printptr_bonus.c \
			ft_parse_special_bonus.c ft_printunsigned_bonus.c ft_hex_util_bonus.c \

LIBFT_DIR = ./libft

CFLAGS = -Wall -Wextra -Werror

HDRS = ft_printf.h

HDRS_BONUS = ft_printf_bonus.h

LIBFT = $(LIBFT_DIR)/libft.a

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc

%.o: %.c
	$(CC) $(CFLAGS) -I.$(HDRS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	rm $(NAME)

re: fclean $(NAME)

bonus: $(LIBFT) $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

all: $(NAME)

$(LIBFT):
	@$(MAKE) bonus -C $(LIBFT_DIR)
	@cp $(LIBFT) .
	@mv libft.a $(NAME)

.PHONY: all re fclean clean bonus
