# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 16:53:28 by anareval          #+#    #+#              #
#    Updated: 2025/05/08 19:22:42 by anareval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo

# Colors ANSI
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
MAGENTA	= \033[1;35m
CYAN	= \033[1;36m
WHITE	= \033[1;37m
RESET	= \033[0m
PURPLE	= \033[38;5;141m
ORANGE	= \033[38;5;208m
TEAL	= \033[38;5;80m

CC = cc
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -g
RM = rm -f
#SANITAZE = -fsanitize=address

HEADERS = 	-I ./include

SRCS =				sources/inicialice.c \
					sources/philo_rutine.c \
					sources/philo.c \
					sources/threads.c \
					sources/utils.c \
					
OBJS = $(SRCS:.c=.o)

all:$(NAME)
	@echo "$(GREEN)✅ Build completed successfully!$(RESET)"
	
%.o: %.c
	@echo "$(CYAN)🛠️  Compiling $@...$(RESET)"
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME): $(OBJS)
	@echo "$(PURPLE)📦 Creating the program: $(NAME)"
	@$(CC) $(OBJS) $(LIBS) $(SANITAZE) -o $(NAME)

clean:
	@echo "$(MAGENTA)🗑️🧹Deleting $(NAME) .o files...$(RESET)"
	@$(RM) $(OBJS)
	@echo "$(GREEN)✅ Done!$(RESET)"

fclean: clean
	@echo "$(RED)💥 Deleting $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)✅ Done!$(RESET)"

re: re_msg fclean all

new: re_msg fclean all
	@make -s clean

re_msg:
	@echo "$(ORANGE)🔄 Recreating $(NAME)...$(RESET)"

valgr:
	- valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes -s ./$(NAME) $(ARG) || true

.PHONY: all clean fclean re new valgr