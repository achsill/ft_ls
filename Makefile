# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlouar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/23 18:43:37 by hlouar            #+#    #+#              #
#    Updated: 2016/04/23 18:43:40 by hlouar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

HEADER = includes/ls.h

FLAGS = -Wall -Werror -Wextra -g3

SRC =	ft_stickybit.c \
		error_check.c \
		error_check2.c \
		for_dev.c \
		main.c \
		mode.c \
		mode2.c \
		mode3.c \
		option.c \
		output.c \
		output2.c \
		recursive.c \
		reparse.c \
		sort_by_ascii.c \
		sort_rev.c \
		sort_by_time.c \

OBJDIR = obj/

OBJ = $(SRC:%.c=$(OBJDIR)%.o)

all: $(NAME)

norm:
	@norminette $(SRC) $(HEADER)

$(NAME): compile_lib compile_p $(OBJ)
		@clang $(FLAGS) -o $(NAME) $(OBJ) -L libft -lft
		@echo ""
		@echo "\033[32mCompilation Succeeded\033[39m"
		@echo ""

compile_p:
		@echo "\n\033[34mCompiling Project Wait...\033[39m"
		@echo ""

compile_lib:
		@make -C libft/

$(OBJDIR)%.o: %.c
		@mkdir -p $(OBJDIR)
		@clang $(FLAGS) -I libft/includes -o $@ -c $<
		@printf "\033[33m. \033[39m"
		@echo ""

clean_proj:
		@/bin/rm -f $(OBJ)

clean:
		@make -C libft/ fclean
		@/bin/rm -rf $(OBJDIR)

fclean: clean
		@/bin/rm -f $(NAME)
		@echo "\033[31mRemove\033[39m $(NAME)"

re: fclean all

.PHONY: clean fclean clean_proj compile_lib compile_p norm all
