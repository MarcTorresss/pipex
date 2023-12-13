# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: martorre <martorre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 18:13:35 by pfontenl          #+#    #+#              #
#    Updated: 2023/12/13 17:50:56 by martorre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a
FLAGS 	= -Wall -Wextra -Werror -I .
INCLUDE = libft.h
CC = cc
LIB = ar rcs
DIR_OBJ = temp/

SRC_LIBFT = ft_atoi.c ft_atol.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_isprint.c ft_memset.c ft_tolower.c ft_toupper.c ft_memcpy.c\
ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncmp.c ft_memmove.c ft_strlcpy.c ft_strchr.c\
ft_strrchr.c ft_memchr.c ft_itoa.c ft_substr.c ft_memcmp.c ft_putchar_fd.c ft_strcmp.c\
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strnstr.c ft_split.c ft_strjoin.c\
ft_strtrim.c ft_calloc.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_lstnew_bonus.c\
ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c ft_split_qtt.c

OBJ_LIBFT = $(addprefix $(DIR_OBJ), $(SRC_LIBFT:.c=.o))

all: temp $(NAME)

temp: 
	mkdir -p $(DIR_OBJ)
	
$(NAME): $(OBJ_LIBFT)
	@$(LIB) $(NAME) $(OBJ_LIBFT)
	@echo Libft compiled

$(DIR_OBJ)%.o: %.c Makefile $(INCLUDE)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo Compiling $< ...

clean:
	@rm -rf $(DIR_OBJ)
	@echo Deleting all objs

fclean: clean
	@rm -rf $(NAME)
	@echo Deleting all libft

re : fclean all

.PHONY: all clean fclean re
