# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 10:04:23 by aherrman          #+#    #+#              #
#    Updated: 2023/11/08 17:32:39 by sbouheni         ###   ########.fr        #
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
SRCS 	=			main.c									\
					environement/environement.c				\
					environement/environement_extraction.c	\
					environement/environement_list.c		\
					environement/environement_utils.c		\
					environement/get_path.c					\
					lexer/tokenizer.c						\
					lexer/tokenize_operator.c				\
					lexer/token_type.c						\
					lexer/token_list.c						\
					lexer/quote_process.c					\
					lexer/expansion.c						\
					lexer/tokens_analysis.c					\
					lexer/extract_varname.c					\
					prompt/prompt.c							\
					redirection/in_and_out.c				\
					signal/setup_signals.c					\
					signal/handle_sigint.c					\
					resources/init.c						\
					resources/clean.c						\
					global_utils/utils_for_tab.c			\
					global_utils/utils_for_tab2.c			\
					global_utils/is_operator.c				\
					global_utils/is_quote.c					\
					global_utils/is_variable.c				\
					global_utils/is_exit_code.c				\
					global_utils/is_token_delimiter.c		\
					global_utils/get_str.c					\
					exec_list/ft_execl_utils.c				\
					exec_list/exec_free.c					\
					pipe/pipe.c								\
					format_for_exec/main_format.c			\
					format_for_exec/fd_save.c				\
					builtins/cd.c							\
					builtins/pwd.c							\
					builtins/unset.c						\
					builtins/export.c						\
					builtins/env.c							\
					builtins/echo.c							\
					builtins/utils.c						\
					builtins/exit.c							\
					execution/execution.c					\
					execution/execution_utils.c				\
					execution/redir_for_exec.c				\
					execution/redir_for_exec2.c				\
					execution/command_execution.c			\
					error/error.c							\
					fork/fork.c								\

				
					
					

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
