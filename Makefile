# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 10:04:23 by aherrman          #+#    #+#              #
#    Updated: 2023/10/12 16:36:45 by sbouheni         ###   ########.fr        #
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
					lexer/tokenizer.c				\
					lexer/tokenize_operator.c		\
					lexer/tokenize_quote.c			\
					lexer/tokenize_word.c			\
					lexer/token_type.c				\
					lexer/token_list.c				\
					parser/parser.c					\
					parser/token_check.c			\
					parser/command_check.c			\
					parser/file_check.c				\
					prompt/prompt.c					\
					redirection/in_and_out.c		\
					signal/setup_signals.c			\
					signal/handle_sigquit.c			\
					signal/handle_sigint.c			\
					resources/create_r.c			\
					resources/init.c				\
					resources/clean.c				\
					global_utils/utils_for_char.c	\
					global_utils/utils_for_tab.c	\
					global_utils/utils_for_tab2.c	\
					global_utils/utils_for_tab3.c	\
					global_utils/utils_for_env.c	\
					global_utils/utils_for_test.c	\
					global_utils/utils_redir.c		\
					global_utils/is_operator.c		\
					global_utils/is_quote.c			\
					exec_list/ft_create_struct.c	\
					exec_list/ft_execl_utils.c		\
					builtins/cd.c					\
					builtins/pwd.c					\
					builtins/unset.c				\
					builtins/export.c				\
					builtins/env.c					\
					builtins/echo.c					\
					execution/execution.c			\
					test/print_tokens.c				\

					
					

SRCST 	=			ft_print_list.c					\


.c.o	:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all		:		$(NAME)

$(NAME)	:	$(OBJS) 
	@make -C ./include/libft
	gcc $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) -lreadline

debug	:		$(OBJS)
	make -C ./include/libft
	gcc $(CFLAGS) -fsanitize=address $(OBJS) $(LIBS) -o $(NAME) -lreadline

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
	@make clean -C ./include/libft
	
re		:		fclean all

ret		:		fclean test
