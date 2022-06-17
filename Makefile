# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 23:23:17 by wismith           #+#    #+#              #
#    Updated: 2022/06/15 11:23:00 by wismith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

# Cuz Names Are Important
NAME = minishell

# SRCS because we never outsource our work
SRCS = main/main cmds/cmdcheck parser/parser\
		parser/terminate errors/err1  parser/printer\
		parser/customsplit

# Objects used to compile
OBJDIR = Objects
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o , $(SRCS)))

# Compiler / Flags / libft library
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/Library/libft.a
READ = readline/lib/*.dylib readline/lib/*.a
OFLAGS = -L/usr/local/lib -I/usr/local/include -lreadline

# Compile the objects inside the objects folder
$(OBJDIR)/%.o : srcs/%.c
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/main
	mkdir -p $(OBJDIR)/parser
	mkdir -p $(OBJDIR)/cmds
	mkdir -p $(OBJDIR)/errors
	$(CC) $(CFLAGS) -c $< -o $@

# in case of bonus... use all? :)
all : $(NAME)
	tput setaf 2; echo "-> Executable Provided <-"; tput setaf 7;

# Compiles our executable
$(NAME) : $(OBJ)
	tput setaf 6; echo "-> Compiling <-"; tput setaf 7;
	make -C libft
	$(CC) $(CFLAGS) $(LIBFT) $(OFLAGS) $(OBJ) -o $(NAME)
#	$(CC) $(CFLAGS) $(LIBFT) $(READ) $(OBJ) -o $(NAME)

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

# Phony rules... we don't have to obey them. Cuz they're phony ;) lol
.PHONY: all clean fclean re printre