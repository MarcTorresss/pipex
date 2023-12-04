# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: martorre <martorre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 17:57:56 by martorre          #+#    #+#              #
#    Updated: 2023/12/04 18:08:33 by martorre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = pipex

FLAGS = -Wall -Wextra -Werror -I./libft

LIBFT = libft

DIR_O = temp/

SOURCES = main.c

OBJS = $(addprefix $(DIR_O),$(SOURCES:.c=.o))

all: temp make_lib $(NAME)

$(NAME): $(OBJS) libft/libft.a
	@$(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)
	@echo "pipex Compiled"

make_lib:
	@$(MAKE) -C $(LIBFT) --no-print-directory

temp:
	@mkdir -p temp

$(DIR_O)%.o: %.c $(NAME).h libft/libft.a Makefile 
	$(CC) -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -rf $(DIR_O)
	@echo Deleting all objects

fclean: clean
	@rm -rf $(NAME)
	@echo Deleting all

re : fclean all

.PHONY: all clean fclean re
