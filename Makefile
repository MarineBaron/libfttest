# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 18:36:43 by mbaron            #+#    #+#              #
#    Updated: 2018/01/05 19:06:00 by mbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		libfttests

LIB_DIR			=		../libft_validation

LIB				=		$(LIB_DIR)/libft.a

DIR_SRCS		=		.

SRCS			=		$(DIR_SRCS)/test.c	\
						$(DIR_SRCS)/main.c

DIR_HEADERS		=		$(LIB_DIR)

OBJS			=		$(SRCS:.c=.o)

HEADERS			=		-I$(DIR_HEADERS)

LIB_INCLUDE		= 		-L$(LIB_DIR) -lft

CC				=		gcc

CFLAGS			=		-Wall -Werror -Wextra 

RM				=		rm -f

all				:		$(NAME)

$(LIB)			:		
						(cd $(LIB_DIR) ; make re)

$(NAME)			:		$(LIB) $(OBJS)
						$(CC) -o $(NAME) $(OBJS) $(HEADERS) $(CFLAGS)		\
							$(LIB_INCLUDE)

clean			:
						(cd $(LIB_DIR) ; make clean)
						$(RM) $(OBJS)

fclean			:		clean
						(cd $(LIB_DIR) ; make fclean)
						$(RM) $(NAME)

re				:		fclean all
