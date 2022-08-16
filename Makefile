# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 23:23:17 by wismith           #+#    #+#              #
#    Updated: 2022/08/17 01:00:24 by wismith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#.SILENT:

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
		expansions/extra\
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
CFLAGS = -Wall -Wextra -Werror -I/readline/includes/*
LIBFT = ./libft/Library/libft.a
READ = ./readline/lib/libreadline.a
LDFLAGS = -lreadline

# Compile the objects inside the objects folder
$(OBJDIR)/%.o : srcs/%.c
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/main
	@mkdir -p $(OBJDIR)/cmdbus
	@mkdir -p $(OBJDIR)/parser
	@mkdir -p $(OBJDIR)/builtins
	@mkdir -p $(OBJDIR)/errhandle
	@mkdir -p $(OBJDIR)/expansions
	$(CC) $(CFLAGS) -c $< -o $@

# in case of bonus... use all? :)
all : $(NAME)
	@printf "\e[1;1H\e[2J"
	@printf "\n\n"
	@tput setaf 1
	@echo ───────────▒▒▒▒▒▒▒▒
	@echo ─────────▒▒▒──────▒▒▒
	@echo ────────▒▒───▒▒▒▒──▒░▒
	@echo ───────▒▒───▒▒──▒▒──▒░▒
	@echo ──────▒▒░▒──────▒▒──▒░▒
	@echo ───────▒▒░▒────▒▒──▒░▒
	@echo ─────────▒▒▒▒▒▒▒───▒▒
	@echo ─────────────────▒▒▒ | tr -d '\n'; printf "                               _.-''|''-._\n"
	@echo ─────▒▒▒▒────────▒▒ | tr -d '\n'; printf "                             .-'     |     '-.\n"
	@echo ───▒▒▒░░▒▒▒─────▒▒──▓▓▓▓▓▓▓▓ | tr -d '\n'; printf "                  .'\       |       /'.                .___________________________. \n"
	@echo ──▒▒─────▒▒▒────▒▒▓▓▓▓▓░░░░░▓▓──▓▓▓▓ | tr -d '\n'; printf "        .'   \      |      /   '.              | .____________________. |==| \n"
	@echo ─▒───▒▒────▒▒─▓▓▒░░░░░░░░░█▓▒▓▓▓▓░░▓▓▓ | tr -d '\n'; printf "      \    <- SEA SHELL ->    /              | | .................. | |  | \n"
	@echo ▒▒──▒─▒▒───▓▒▒░░▒░░░░░████▓▓▒▒▓░░░░░░▓▓ | tr -d '\n'; printf "      '\    \    |    /    /'               | | SEA SHELL ->:vim:: | |  |\n"
	@echo ░▒▒───▒──▓▓▓░▒░░░░░░█████▓▓▒▒▒▒▓▓▓▓▓░░▓▓ | tr -d '\n'; printf "       '\   \   |   /   /'                 | | #include:'file.h': | |  |\n"
	@echo ──▒▒▒▒──▓▓░░░░░░███████▓▓▓▒▒▒▒▒▓───▓▓░▓▓ | tr -d '\n'; printf "         '\  \  |  /  /'                   | | int:main(void):::: | |  |\n"
	@echo ──────▓▓░░░░░░███████▓▓▓▒▒▒▒▒▒▒▓───▓░░▓▓ | tr -d '\n'; printf "        _.-'\ \ | / /'-._                  | | {::::::::::::::::: | |  |\n"
	@echo ─────▓▓░░░░░███████▓▓▓▒▒▒▒▒▒▒▒▒▓▓▓▓░░▓▓ | tr -d '\n'; printf "        {_____ '\\|/' _____}                 | | :printf('hello!'); | |  |\n"
	@echo ────▓▓░░░░██████▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▓░░░░▓▓ | tr -d '\n'; printf "                 '-'                         | | }::::::::::::::::: | | ,|\n"
	@echo ────▓▓▓░████▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓ | tr -d '\n'; printf "           Devs: Muna / Willem                 | !____________________! |(c|\n"
	@echo ─────▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓ | tr -d '\n'; printf "                                                   !________________________!__!\n"
	@echo ─────▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓ | tr -d '\n'; printf "       __  __ _       _     _          _ _        /                            \\ \n"
	@echo ──────▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓ | tr -d '\n'; printf "       |  \/  (_)_ __ (_)___| |__   ___| | |      /  [][][] [][][][][][][][][][]  \\ \n"
	@echo ───────▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓ | tr -d '\n'; printf "        | |\/| | | '_ \| / __| '_ \ / _ \ | |     /  [][][][][] [][][][][][][][][]  \\ \n"
	@echo ─────────▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓ | tr -d '\n'; printf "          | |  | | | | | | \__ \ | | |  __/ | |    (  [][][][][_____________][][][][]  ) \n"
	@echo ───────────▓▓▓▓▓▓▒▒▒▒▒▓▓▓▓ | tr -d '\n'; printf "            |_|  |_|_|_| |_|_|___/_| |_|\___|_|_|     \\ ------------------------------- /\n"
	@echo ───────────────▓▓▓▓▓▓▓▓ | tr -d '\n'; tput setaf 2; printf "                    -> Executable Provided <-";
	@tput setaf 1; printf "             \\_______________________________/\n"
	@tput setaf 7
	@printf "\n\n\n"

# Compiles our executable
$(NAME) : $(OBJ)
	@tput setaf 6; echo "-> Compiling <-"; tput setaf 7;
	@make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) $(READ) -o $(NAME)

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