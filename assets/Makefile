# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 16:52:51 by wismith           #+#    #+#              #
#    Updated: 2022/06/06 20:22:37 by wismith          ###   ########.fr        #
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
		ft_split ft_strmapi\
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
		ft_split_mod ft_strrev

CFLAGS = -Wall -Wextra -Werror

CC = gcc

OBJ_DIR = Objects
SRC = src
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(LIST)))

$(OBJ_DIR)/%.o : src/%.c
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/assets
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)
	tput setaf 2; printf "\n-> library provided <-\n"
	tput setaf 7

$(NAME) : $(OBJ) $(HEADER) $(SRC)
	tput setaf 3; echo "LIBFT->"
	tput setaf 3; echo "Building->"
	mkdir -p Library
	ar -rc $(NAME) $(OBJ)

clean:
	tput setaf 3; echo "\nCleaning->"
	rm -rf $(OBJ_DIR)
	tput setaf 1; echo "Objects->" | tr -d '\n'
	tput setaf 2; echo "       [ok] [ok]\n"

fclean: clean
	tput setaf 3; echo "Cleaning->"
	rm -rf Library
	tput setaf 1; echo "Libraries->" | tr -d '\n'
	tput setaf 2; echo "     [ok] [ok]\n"


re : fclean all
	tput setaf 3; echo "\nRecreated->"
	tput setaf 2; echo "All->           [ok] [ok]"

.PHONY : all clean fclean re
