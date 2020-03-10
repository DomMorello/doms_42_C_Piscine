# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donglee <donglee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 12:25:59 by yshim             #+#    #+#              #
#    Updated: 2020/02/13 02:33:26 by donglee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BSQ

SRCS = $(addprefix srcs/, main.c parse1.c parse2.c parse3.c sol_ver2_1.c sol_ver2_2.c solution1.c solution2.c)

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f

MAPGEN = perl mapgen.pl 5 5 1 > example_file
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o} -g

${NAME} : ${OBJS} 
	$(CC) $(CFLAGS) -o ${NAME} ${OBJS}


all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

norm :
	norminette -R CheckForbiddenSourceHeader ./srcs/*.c ./includes/*.h

re : fclean all

.PHONY: all clean fclean re
