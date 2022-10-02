# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 23:23:17 by wismith           #+#    #+#              #
#    Updated: 2022/10/03 00:14:13 by wismith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Cuz Names Are Important
NAME = minishell

# SRCS because we never outsource our work
SRCS = main/main\
		main/cmd\
		main/cmdblock\
		main/signalhandlr\
		main/rtn_prompt\
		parser/quote_strip\
		parser/terminate\
		parser/printer\
		parser/split/customsplit\
		parser/split/split_tools\
		parser/split/split_by_pipe\
		parser/split/utils\
		parser/redir/redir_pars\
		parser/count_pipes\
		parser/tools\
		parser/env\
		parser/strip_all_quotes\
		builtins/echo\
		builtins/exit\
		err/err\
		err/utils\
		err/quote_check\
		expand/expand\
		expand/expand2\
		expand/seperate_cmd\
		expand/tools\
		expand/tools2\
		exec/multipipe\
		exec/tools\
		exec/access\
		exec/close_fds\
		\
		\
		builtins/builitins\
		exec/execve2\
		builtins/pwd\
		builtins/env\
		builtins/cd/cd\
		builtins/cd/cd2\
		builtins/cd/utils\
		builtins/export/export\
		builtins/export/export2\
		builtins/export/export3\
		builtins/export/export4\
		builtins/unset\
		exec/redir\
		exec/Heredoc\
		heredoc/pars_heredoc\

# Objects used to compile
OBJDIR = Objects
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o , $(SRCS)))

# Compiler / Flags / libft library
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I/readline/includes/*
LIBFT = ./libft/Library/libft.a
LDFLAGS = -lreadline -L ./readline/lib/
LINUX = -lreadline

ifeq ($(shell uname -s), Linux)
	RUNNER		= $(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LINUX) -o $(NAME)
endif
ifeq ($(shell uname -s), Darwin)
	RUNNER		= $(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)
endif

# Compile the objects inside the objects folder
$(OBJDIR)/%.o : srcs/%.c
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/main
	@mkdir -p $(OBJDIR)/cmdbus
	@mkdir -p $(OBJDIR)/parser
	@mkdir -p $(OBJDIR)/parser/split
	@mkdir -p $(OBJDIR)/parser/redir
	@mkdir -p $(OBJDIR)/builtins
	@mkdir -p $(OBJDIR)/builtins/cd
	@mkdir -p $(OBJDIR)/builtins/export
	@mkdir -p $(OBJDIR)/err
	@mkdir -p $(OBJDIR)/expand
	@mkdir -p $(OBJDIR)/exec
	@mkdir -p $(OBJDIR)/heredoc
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
	$(RUNNER)

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

valgrind: re
	@clear
	@echo "\033[0;32mRunning in Valgrind.\033[0m"
	@valgrind \
	--leak-check=full \
	--track-fds=yes \
	--track-origins=yes \
	--trace-children=yes \
	--show-leak-kinds=all \
	--suppressions=readline/readline_ig2.supp \
	./minishell\

noenv: re
	@clear
	@echo "\033[0;32mRunning in Valgrind.\033[0m"
	@valgrind \
	--leak-check=full \
	--track-fds=yes \
	--track-origins=yes \
	--show-leak-kinds=all \
	--suppressions=readline/readline_ig2.supp \
	env -i ./minishell\

run : re
	@sleep 2
	@clear && ./minishell

# Phony rules... we don't have to obey them. Cuz they're phony ;) lol
.PHONY: all clean fclean re printre execute
