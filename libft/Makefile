# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 20:31:25 by galves-f          #+#    #+#              #
#    Updated: 2023/11/01 22:11:11 by galves-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a
# SRC 	= $(wildcard *.c)
SRC 	= ft_isalpha.c ft_isdigit.c ft_isalnum.c
# OBJ 	= $(SRC:.c=.o)
OBJF 	= obj
OBJ 	= $(patsubst %.c, $(OBJF)/%.o, $(SRC))
# OBJ 	= $($(SRC):%.c=$(OBJF)/%.o)
# libft.h
INC 	= . 
CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror
RM 		= rm -rf

$(OBJF)/%.o: %.c
	mkdir -p $(OBJF)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJF)

fclean: clean
	$(RM) $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)
