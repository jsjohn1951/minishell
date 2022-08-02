# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnyalhdrmy <mnyalhdrmy@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 23:23:17 by wismith           #+#    #+#              #
#    Updated: 2022/08/02 10:07:07 by mnyalhdrmy       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

# Cuz Names Are Important
NAME = minishell

# SRCS because we never outsource our work
SRCS = main/main parser/quote_strip\
		parser/terminate parser/printer\
		parser/customsplit parser/split_tools\
		builtins/echo builtins/exit\
		main/cmd parser/set_mode\
		parser/split_by_pipe parser/env\
		main/cmdblock errhandle/err\
		errhandle/quote_check\
		expansions/cmd_check\
		expansions/exp_tools\
		\
		\
		builtins/builitins builtins/execve2\
		builtins/pwd builtins/env\
		builtins/get_path builtins/cd\
		builtins/export builtins/export2\
		builtins/unset builtins/cd2\

# Objects used to compile
OBJDIR = Objects
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o , $(SRCS)))

# Compiler / Flags / libft library
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/Library/libft.a
READ = ./readline/lib/*
LDFLAGS = -lreadline

# Compile the objects inside the objects folder
$(OBJDIR)/%.o : srcs/%.c create_dir
	$(CC) $(CFLAGS) -c $< -o $@

# in case of bonus... use all? :)
all : $(NAME)
	@printf "\e[1;1H\e[2J"
	@printf "\n\n"
	@printf "\x1B[31m\n"
	@echo ───────────▒▒▒▒▒▒▒▒
	@echo ─────────▒▒▒──────▒▒▒
	@echo ────────▒▒───▒▒▒▒──▒░▒
	@echo ───────▒▒───▒▒──▒▒──▒░▒
	@echo ──────▒▒░▒──────▒▒──▒░▒
	@echo ───────▒▒░▒────▒▒──▒░▒
	@echo ─────────▒▒▒▒▒▒▒───▒▒
	@echo ─────────────────▒▒▒ | tr -d '\n'; printf "                               _.-''|''-._\n"
	@echo ─────▒▒▒▒────────▒▒ | tr -d '\n'; printf "                             .-'     |     '-.\n"
	@echo ───▒▒▒░░▒▒▒─────▒▒──▓▓▓▓▓▓▓▓ | tr -d '\n'; printf "                  .'\       |       /'.\n"
	@echo ──▒▒─────▒▒▒────▒▒▓▓▓▓▓░░░░░▓▓──▓▓▓▓ | tr -d '\n'; printf "        .'   \      |      /   '.\n"
	@echo ─▒───▒▒────▒▒─▓▓▒░░░░░░░░░█▓▒▓▓▓▓░░▓▓▓ | tr -d '\n'; printf "      \    <- SEA SHELL ->    /\n"
	@echo ▒▒──▒─▒▒───▓▒▒░░▒░░░░░████▓▓▒▒▓░░░░░░▓▓ | tr -d '\n'; printf "      '\    \    |    /    /'\n"
	@echo ░▒▒───▒──▓▓▓░▒░░░░░░█████▓▓▒▒▒▒▓▓▓▓▓░░▓▓ | tr -d '\n'; printf "       '\   \   |   /   /'\n"
	@echo ──▒▒▒▒──▓▓░░░░░░███████▓▓▓▒▒▒▒▒▓───▓▓░▓▓ | tr -d '\n'; printf "         '\  \  |  /  /'\n"
	@echo ──────▓▓░░░░░░███████▓▓▓▒▒▒▒▒▒▒▓───▓░░▓▓ | tr -d '\n'; printf "        _.-'\ \ | / /'-._\n"
	@echo ─────▓▓░░░░░███████▓▓▓▒▒▒▒▒▒▒▒▒▓▓▓▓░░▓▓ | tr -d '\n'; printf "        {_____'\\|//'_____}\n"
	@echo ────▓▓░░░░██████▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▓░░░░▓▓ | tr -d '\n'; printf "                 '-'\n"
	@echo ────▓▓▓░████▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓ | tr -d '\n'; printf "           Devs: Muna / Willem\n"
	@echo ─────▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓
	@echo ─────▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓ | tr -d '\n'; printf "\x1B[32m __  __ _       _     _          _ _\x1B[31m\n"
	@echo ──────▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓ | tr -d '\n'; printf "\x1B[32m |  \/  (_)_ __ (_)___| |__   ___| | |\x1B[31m\n"
	@echo ───────▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓ | tr -d '\n'; printf "\x1B[32m  | |\/| | | '_ \| / __| '_ \ / _ \ | |\x1B[31m\n"
	@echo ─────────▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓ | tr -d '\n'; printf "\x1B[32m    | |  | | | | | | \__ \ | | |  __/ | |\x1B[31m\n"
	@echo ───────────▓▓▓▓▓▓▒▒▒▒▒▓▓▓▓ | tr -d '\n'; printf "\x1B[32m      |_|  |_|_|_| |_|_|___/_| |_|\___|_|_|\x1B[31m\n"
	@echo ───────────────▓▓▓▓▓▓▓▓ | tr -d '\n'; printf "\x1B[34m               -> Executable Provided <-\n\x1B[0m"
	@printf "\n\n\n"

create_dir :
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/main
	mkdir -p $(OBJDIR)/cmdbus
	mkdir -p $(OBJDIR)/parser
	mkdir -p $(OBJDIR)/builtins
	mkdir -p $(OBJDIR)/errhandle
	mkdir -p $(OBJDIR)/expansions

# Compiles our executable
$(NAME) : $(OBJ)
	@tput setaf 6; echo "-> Compiling <-"; tput setaf 7;
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

execute : re
	./minishell

# Cleans the objects (including libft)
clean :
	@tput setaf 1; echo "-> Cleaning <-"; tput setaf 7;
	rm -rf $(OBJDIR)
	make clean -C libft

# Removes executables and libraries
fclean : clean
	rm -f $(NAME)
	make fclean -C libft

# What does this do??? Oh yeah! No wait... I forgot... It prints stuff, I think?
printre :
	@tput setaf 4; echo "-> Recreating <-"; tput setaf 7;

# Incase you want to redo everything... lol
re : fclean printre all

run : re
	clear && ./minishell

# Phony rules... we don't have to obey them. Cuz they're phony ;) lol
.PHONY: all clean fclean re printre execute