# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vleida <vleida@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/16 11:18:50 by vleida            #+#    #+#              #
#    Updated: 2021/04/26 10:31:40 by vleida           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c	\
		ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c	\
		ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c	\
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strdup.c ft_calloc.c	\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c		\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c	\
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS:.c=.o}

NAME = libft.a

HEADER = libft.h

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

%.o:%.c	
			${CC} ${CFLAGC} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS} ${HEADER}
			@ar rcs ${NAME} ${OBJS} $?

bonus:		${OBJS} ${BONUS_OBJS} ${HEADER}
			@ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

all:		${NAME} 

clean:		
			${RM} ${OBJS} ${BONUS_OBJS} 

fclean:		clean
			${RM} ${NAME} 

re:			fclean all 