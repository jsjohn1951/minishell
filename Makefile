# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 23:23:17 by wismith           #+#    #+#              #
#    Updated: 2022/08/28 14:52:30 by wismith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#.SILENT:

# Cuz Names Are Important
NAME = minishell

# SRCS because we never outsource our work
SRCS = main/main\
		main/cmd\
		main/cmdblock\
		main/argargv\
		main/signalhandlr\
		parser/quote_strip\
		parser/terminate\
		parser/printer\
		parser/customsplit\
		parser/split_tools\
		parser/count_pipes\
		parser/tools\
		builtins/echo\
		builtins/exit\
		parser/set_mode\
		parser/split_by_pipe\
		parser/env\
		parser/strip_all_quotes\
		err/err\
		err/utils\
		err/quote_check\
		expand/cmd_check\
		expand/exp_tools\
		expand/extra\
		exec/multipipe\
		\
		\
		builtins/builitins exec/execve2\
		builtins/pwd builtins/env\
		builtins/get_path builtins/cd\
		builtins/export builtins/export2\
		builtins/unset builtins/cd2\
		exec/redirecation exec/redirecation2\
		builtins/testfile\

# Objects used to compile
OBJDIR = Objects
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o , $(SRCS)))

# Compiler / Flags / libft library
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I/readline/includes/*
LIBFT = ./libft/Library/libft.a
LDFLAGS = -lreadline -L ./readline/lib/
LINUX = -lreadline

# Compile the objects inside the objects folder
$(OBJDIR)/%.o : srcs/%.c
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/main
	@mkdir -p $(OBJDIR)/cmdbus
	@mkdir -p $(OBJDIR)/parser
	@mkdir -p $(OBJDIR)/builtins
	@mkdir -p $(OBJDIR)/err
	@mkdir -p $(OBJDIR)/expand
	@mkdir -p $(OBJDIR)/exec
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
#	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LINUX) -o $(NAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

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
	@sleep 2
	@clear && ./minishell

# Phony rules... we don't have to obey them. Cuz they're phony ;) lol
.PHONY: all clean fclean re printre execute
