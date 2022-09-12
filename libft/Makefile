# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 16:52:51 by wismith           #+#    #+#              #
#    Updated: 2022/09/12 12:04:35 by wismith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Library/libft.a

.SILENT:

LIST =	ft_atoi ft_bzero ft_calloc\
		ft_isalnum ft_isalpha ft_isascii\
		ft_isdigit ft_isprint ft_memchr\
		ft_memcmp	ft_memcpy	ft_memmove\
		ft_memset	ft_strchr\
		ft_strdup ft_strlcat ft_strlcpy\
		ft_strlen ft_strncmp ft_strnstr\
		ft_strrchr ft_tolower ft_toupper\
		ft_substr ft_strjoin ft_strtrim\
		ft_split_old ft_strmapi\
		ft_striteri ft_putchar_fd ft_putstr_fd\
		ft_putendl_fd ft_putnbr_fd ft_itoa\
		ft_strjoin_mod ft_lstnew\
		ft_lstadd_front ft_lstsize\
		ft_lstlast ft_lstadd_back\
		ft_lstdelone ft_lstclear\
		ft_lstiter ft_lstmap\
		get_next_line get_next_line_utils\
		assets/ft_int_min assets/ft_printf\
		assets/ft_put_u assets/ft_put\
		assets/ft_puthex assets/ft_putptr\
		ft_split_mod ft_strrev\
		new_funcs/ft_matrix_len new_funcs/ft_matrix_dup\
		new_funcs/ft_print_matrix new_funcs/ft_free_matrix\
		new_funcs/ft_free new_funcs/ft_add_matrix_elem\
		new_funcs/ft_freer

CFLAGS = -Wall -Wextra -Werror

CC = gcc

OBJ_DIR = Objects
SRC = src
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(LIST)))

$(OBJ_DIR)/%.o : src/%.c
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/assets
	mkdir -p $(OBJ_DIR)/new_funcs
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)
	tput setaf 2; printf "\n<- library provided ->\n\n"
	tput setaf 7

$(NAME) : $(OBJ) $(HEADER) $(SRC)
	tput setaf 2; printf "\n<- Libft ->\n<- Building ->"
	mkdir -p Library
	ar -rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf Library

re : fclean all

.PHONY : all clean fclean re
