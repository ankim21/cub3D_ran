# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/28 19:11:38 by rabi-aka          #+#    #+#              #
#    Updated: 2026/02/28 19:50:34 by rabi-aka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_calloc.c\
ft_isalpha.c\
ft_isalnum.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_memset.c\
ft_memcpy.c\
ft_memmove.c\
ft_memchr.c\
ft_memcmp.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strchr.c\
ft_strrchr.c\
ft_strlcat.c\
ft_strncmp.c\
ft_strnstr.c\
ft_strdup.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c\
ft_toupper.c\
ft_tolower.c\
ft_bzero.c\
ft_substr.c\
ft_strjoin.c\
ft_strmapi.c\
ft_striteri.c\
ft_strtrim.c\
ft_itoa.c\
ft_lstnew_bonus.c\
ft_lstadd_front_bonus.c\
ft_lstsize_bonus.c\
ft_lstlast_bonus.c\
ft_lstadd_back_bonus.c\
ft_lstdelone_bonus.c\
ft_lstclear_bonus.c\
ft_lstiter_bonus.c\
ft_lstmap_bonus.c\
ft_split.c\
ft_is_whitespace.c\
ft_strcmp.c\
ft_strndup.c\
ft_chardup.c\
ft_is_printable_ascii.c\
ft_strcpy.c\
ft_split_exec.c\
ft_atoi.c\

INCLUDES = .
HEADER = libft.h
OBJS = ${SOURCES:.c=.o}

%.o: %.c $(HEADER)
	${CC} -I $(INCLUDES) ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re
