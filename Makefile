# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galves-f <galves-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 20:31:25 by galves-f          #+#    #+#              #
#    Updated: 2024/08/23 13:39:33 by galves-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################


NAME	= libft.a
CC 		= cc
CFLAGS	= -Wall -Werror -Wextra
AUTHOR	= galves-f
DATE	= 2024/01/24

NOVISU 	= 0 # 1 = no progress bar usefull when tty is not available

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

FILE_EXTENSION	= .c

SRCS_PATH		= src

INCLUDE_PATH	= inc

SRCS			= convert/ft_atoi.c \
					convert/ft_atol.c \
					convert/ft_itoa.c \
					convert/ft_uitoa.c \
					convert/ft_tolower.c \
					convert/ft_toupper.c \
					convert/ft_char_to_string.c \
					check/ft_isalnum.c \
					check/ft_isalpha.c \
					check/ft_isascii.c \
					check/ft_isdigit.c \
					check/ft_isprint.c \
					check/ft_isword.c \
					memory/ft_bzero.c \
					memory/ft_calloc.c \
					memory/ft_memchr.c \
					memory/ft_memcmp.c \
					memory/ft_memcpy.c \
					memory/ft_memmove.c \
					memory/ft_memset.c \
					memory/ft_free_multiple.c \
					memory/ft_free_2d_array.c \
					math/ft_nbrlen_base.c \
					math/ft_pow.c \
					math/ft_sqrt.c \
					fs/ft_putchar_fd.c \
					fs/ft_putendl_fd.c \
					fs/ft_putnbr_fd.c \
					fs/ft_putstr_fd.c \
					fs/get_next_line.c \
					fs/get_next_line_utils.c \
					string/ft_split.c \
					string/ft_split_word.c \
					string/ft_strchr.c \
					string/ft_strdup.c \
					string/ft_striteri.c \
					string/ft_strjoin.c \
					string/ft_strlcat.c \
					string/ft_strlcpy.c \
					string/ft_strlen.c \
					string/ft_strmapi.c \
					string/ft_strncmp.c \
					string/ft_strnstr.c \
					string/ft_strrchr.c \
					string/ft_strtrim.c \
					string/ft_substr.c \
					string/ft_is_between_char.c \
					linked_list/ft_lstadd_back.c \
					linked_list/ft_lstadd_front.c \
					linked_list/ft_lstclear.c \
					linked_list/ft_lstdelone.c \
					linked_list/ft_lstremove.c \
					linked_list/ft_lstremove_del.c \
					linked_list/ft_lstiter.c \
					linked_list/ft_lstlast.c \
					linked_list/ft_lstmap.c \
					linked_list/ft_lstnew.c \
					linked_list/ft_lstsize.c \
					linked_list/ft_lstget.c \
					linked_list/ft_lstiter_param.c

################################################################################
#                                  Makefile  objs                              #
################################################################################

SHELL := /bin/bash


OBJS				= $(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.o})
DEPS				= $(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.d})

################################################################################
#                                 Makefile logic                               #
################################################################################

# property color aliases
COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

# Color Aliases
DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

COM_STRING   = "compiling"

HASH	= 

ifeq ($(OS),Windows_NT) 
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(detected_OS),Darwin) 
	RUN_CMD = script -q $@.log $1 > /dev/null; \
				RESULT=$$?
else ifeq ($(detected_OS),Linux)
	RUN_CMD = script -q -e -c "$(1)" $@.log > /dev/null; \
				RESULT=$$?; \
				sed -i '1d' $@.log; \
				sed -i "$$(($$(wc -l < $@.log)-1)),\$$d" $@.log
else
	RUN_CMD = $(1) 2> $@.log; \
				RESULT=$$?
endif

ifeq ($(shell git rev-parse HEAD &>/dev/null; echo $$?),0)
	AUTHOR	:= $(shell git log --format='%aN' | sort -u | awk '{printf "%s, ", $$0}' | rev | cut -c 3- | rev)
	DATE	:= $(shell git log -1 --date=format:"%Y/%m/%d %T" --format="%ad")
	HASH	:= $(shell git rev-parse --short HEAD)
endif

# Progress vars
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRCS) | wc -w) - $(shell ls -l objs 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -lt 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

################################################################################
#                                 Makefile rules                             #
################################################################################

# all: header $(NAME)
all: $(NAME)
	@rm -rf .files_changed

header:
	@printf "%b" "$(OK_COLOR)"
	@echo "        ___  _____ ___  ___      _        "
	@echo "       /   |/ __  \|  \/  |     | |       "
	@echo "      / /| |\`' / /'| .  . | __ _| | _____ "
	@echo "     / /_| |  / /  | |\/| |/ _\` | |/ / _ \\"
	@echo "     \___  |./ /___| |  | | (_| |   <  __/"
	@echo "         |_/\_____/\_|  |_/\__,_|_|\_\___| v2"
	@echo
	@echo "OS : $(detected_OS)"
ifneq ($(HASH),)
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)@$(HASH)\n"
else
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)\n"
endif
	@printf "%b" "$(OBJ_COLOR)Author:	$(WARN_COLOR)$(AUTHOR)\n"
	@printf "%b" "$(OBJ_COLOR)Date: 	$(WARN_COLOR)$(DATE)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)CC: 	$(WARN_COLOR)$(CC)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)Flags: 	$(WARN_COLOR)$(CFLAGS)\n\033[m"
	@echo


$(NAME):	${OBJS}
	@ar rc $(NAME) $^
	@printf "\r%100s\r$(GREEN)libft is up to date!$(DEFAULT)\n"

objs/%.o: 	$(SRCS_PATH)/%$(FILE_EXTENSION)
			@mkdir -p $(dir $@)
			@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
			@printf "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
			@$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE_PATH)

clean:		
			@printf "$(CYAN)Cleaning up object files in libft...$(DEFAULT)\n\n"
			@rm -rf objs
			@printf "%-53b%b" "$(COM_COLOR)clean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

fclean:		clean
			@rm -rf $(NAME)
			@printf "%-53b%b" "$(COM_COLOR)fclean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

re:			fclean all

norminette:
	@printf "$(CYAN)\nChecking norm for libft...$(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(SRCS_PATH) $(INCLUDE_PATH) | nform

.PHONY:		all clean fclean re header norminette
