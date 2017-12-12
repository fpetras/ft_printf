# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpetras <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 07:33:44 by fpetras           #+#    #+#              #
#    Updated: 2017/12/12 07:47:41 by fpetras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libftprintf.a

FT_PRINTF_SRC = ft_printf.c \
	  			parse_modifiers.c \
	  			print_decimal.c \
				print_decimal_padding.c \
	  			print_unsigned_decimal.c \
	  			print_octal.c \
	  			print_hexadecimal.c \
	  			print_pointer.c \
	  			print_binary.c \
	  			print_char.c \
				print_control_char.c \
				print_string.c \
				print_percent_sign.c \
	  			\
	  			ft_itoa_base_pf.c \
	  			ft_uitoa_base_pf.c \
	  			ft_signed_nbr_len.c \
				ft_unsigned_nbr_len.c \
				ft_putwchar_pf.c \
				ft_putwstr_pf.c \
				ft_wstrsize_pf.c

LIBFT_SRC =		libft/ft_atoi.c \
	  			libft/ft_isdigit.c \
	  			libft/ft_memalloc.c \
	  			libft/ft_strchr.c \
				libft/ft_strcmp.c \
	  			libft/ft_strdup.c \
	  			libft/ft_strlen.c \
	  			\
	  			libft/ft_bzero.c \
	  			libft/ft_isspace.c \
	  			libft/ft_strcpy.c

FT_PRINTF_OBJ = $(FT_PRINTF_SRC:.c=.o)

LIBFT_OBJ = 	ft_atoi.o \
				ft_isdigit.o \
				ft_memalloc.o \
				ft_strchr.o \
				ft_strcmp.o \
				ft_strdup.o \
				ft_strlen.o \
				\
				ft_bzero.o \
				ft_isspace.o \
				ft_strcpy.o

CC = gcc

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@$(CC) -c $(FLAGS) $(FT_PRINTF_SRC) $(LIBFT_SRC)
	@ar rc $(NAME) $(FT_PRINTF_OBJ) $(LIBFT_OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(FT_PRINTF_OBJ) $(LIBFT_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
