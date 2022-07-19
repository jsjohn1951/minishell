# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnyalhdrmy <mnyalhdrmy@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 23:23:17 by wismith           #+#    #+#              #
#    Updated: 2022/07/19 11:56:10 by mnyalhdrmy       ###   ########.fr        #
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
		\
		\
		builtins/builitins builtins/execve2\
		builtins/pwd builtins/env\
		builtins/get_path builtins/cd\

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
$(OBJDIR)/%.o : srcs/%.c
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/main
	mkdir -p $(OBJDIR)/cmdbus
	mkdir -p $(OBJDIR)/parser
	mkdir -p $(OBJDIR)/builtins
	mkdir -p $(OBJDIR)/errors
	$(CC) $(CFLAGS) -c $< -o $@

# in case of bonus... use all? :)
all : $(NAME)
	tput setaf 2; echo "-> Executable Provided <-"; tput setaf 7;

# Compiles our executable
$(NAME) : $(OBJ)
	tput setaf 6; echo "-> Compiling <-"; tput setaf 7;
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

# Cleans the objects (including libft)
clean :
	tput setaf 1; echo "-> Cleaning <-"; tput setaf 7;
	rm -rf $(OBJDIR)
	make clean -C libft

# Removes executables and libraries
fclean : clean
	rm -f $(NAME)
	make fclean -C libft

# What does this do??? Oh yeah! No wait... I forgot... It prints stuff, I think?
printre :
	tput setaf 4; echo "-> Recreating <-"; tput setaf 7;

# Incase you want to redo everything... lol
re : fclean printre all

run : re
	clear && ./minishell

# Phony rules... we don't have to obey them. Cuz they're phony ;) lol
.PHONY: all clean fclean re printre