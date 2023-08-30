# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 15:45:26 by aherrman          #+#    #+#              #
#    Updated: 2023/08/22 14:31:22 by aherrman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_is.c\
		ft_mem.c\
		ft_mem2.c\
		ft_put.c\
		ft_split.c\
		ft_base_list.c\
		ft_printf.c\
		ft_str.c\
		ft_str2.c\
		ft_str3.c\
		ft_str4.c\
		ft_atoi_one_lint.c\
		ft_atoi.c\
		ft_itoa.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_printf.c\
		pft_compteur.c\
		pft_putc.c\
		pft_putnb.c\
		pft_putpnb.c\
		pft_puts.c\
		pft_putunb.c\
		pft_putxnb.c\
		get_next_line.c\
		get_next_line_utils.c\
	

OBJS = $(SRCS:.c=.o)

OBJS_BONUS =$(SRCS_BONUS:.c=.o)

CC = gcc

CFLAGS += -Wall -Werror -Wextra

RM = rm -rf

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS) $(OBJS_BONUS)
	@ar rc $(NAME) $(OBJS) $(OBJS_BONUS)
	@ranlib $(NAME)

clean	:	
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)

fclean	:	clean
	@$(RM) $(NAME)

re	:	fclean all

bonus : $(OBJS_BONUS)
	@ar rc $(NAME) $(OBJS_BONUS)
	@ranlib $(NAME)
