# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: student <student@42.fr>                    +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 00:00:00 by student           #+#    #+#              #
#    Updated: 2025/11/12 17:45:00 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	  ft_utils.c ft_utils2.c \
	  ft_print_char_bonus.c ft_print_str_bonus.c \
	  ft_print_ptr_bonus.c ft_print_nbr_bonus.c \
	  ft_print_unsigned_bonus.c ft_print_hex_bonus.c ft_format_flags.c

OBJ_DIR = objects
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[1;33m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo ""
	@echo "$(GREEN)✔ libftprintf.a compiled successfully !$(NC)"
	@EXEC_LINE="=> Library: $(NAME)"; \
	LEN=$$(echo "$$EXEC_LINE" | wc -c); \
	LEN=$$((LEN - 1)); \
	BORDER_LEN=$$((LEN + 2)); \
	TOP="┌$$(printf '─%.0s' $$(seq 1 $$BORDER_LEN))┐"; \
	MID="│ $$EXEC_LINE │"; \
	BOT="└$$(printf '─%.0s' $$(seq 1 $$BORDER_LEN))┘"; \
	echo "$(MAGENTA)$$TOP"; \
	echo "$$MID"; \
	echo "$$BOT$(NC)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)Compiled:$(NC) $<"

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		echo "$(GREEN)Cleaning object files...$(NC)"; \
		$(RM) $(OBJ_DIR); \
		echo "$(GREEN)Clean completed successfully!$(NC)"; \
	else \
		echo "$(YELLOW)No objects to clean.$(NC)"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		echo "$(GREEN)Removing $(NAME)...$(NC)"; \
		$(RM) $(NAME); \
		echo "$(GREEN)Full clean completed successfully!$(NC)"; \
	else \
		echo "$(YELLOW)No library to clean.$(NC)"; \
	fi


re: fclean all

bonus: re
	@echo ""
	@echo "$(CYAN)✨ Bonus rule triggered — full rebuild complete!$(NC)"

.PHONY: all clean fclean re bonus
