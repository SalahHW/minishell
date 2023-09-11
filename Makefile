# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 10:04:23 by aherrman          #+#    #+#              #
#    Updated: 2023/09/11 16:24:28 by sbouheni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=			minishell
OBJST	=			$(addprefix src/test/,$(SRCST:.c=.o))
OBJS	=			$(addprefix src/,$(SRCS:.c=.o))
CC		= 			gcc
CFLAGS	= 			-g3 -Wall -Wextra -Werror
RM		=			rm -rf
LIBS 	=			include/libft/libft.a
INC 	=			-I 
SRCS 	=			main.c							\
					lexer/lexer.c					\
					prompt/prompt.c					\
					signal/setup_signals.c			\
					signal/handle_sigquit.c			\
					signal/handle_sigint.c			\
					resources/init.c				\
					resources/clean.c				\

SRCST 	=			ft_print_list.c					\


.c.o	:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all		:		$(NAME)

$(NAME)	:	$(OBJS) 
	make -C ./include/libft
	gcc $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) -lreadline

debug	:		$(OBJS)
	make -C ./include/libft
	gcc $(CFLAGS) -fsanitize=address $(OBJS) $(LIBS) -o $(NAME)

test	:		$(OBJS) $(OBJST)
	make -C ./include/libft
	gcc $(CFLAGS) $(OBJS) $(OBJST) $(LIBS) -o $(NAME)
	
testd	:		$(OBJS) $(OBJST)
	make -C ./include/libft
	gcc $(CFLAGS) -fsanitize=address $(OBJS) $(OBJST) $(LIBS) -o $(NAME)

clean	:
	$(RM) $(OBJS)
	$(RM) $(OBJST)
	make clean -C ./include/libft


fclean	:		clean
	$(RM) $(NAME)
	make clean -C ./include/libft
	
re		:		fclean all

ret		:		fclean test
