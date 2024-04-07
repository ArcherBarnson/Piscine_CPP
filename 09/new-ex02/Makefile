# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 10:53:17 by bgrulois          #+#    #+#              #
#    Updated: 2024/02/22 18:10:02 by bgrulois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	PmergeMe	

SRCS	=	PmergeMe.cpp \
		main.cpp	

OBJS	=	$(SRCS:.cpp=.o)

CC	=	c++

CPPFLAGS=	-Wall -Werror -Wextra -std=c++98 -g3


%.o:		%.cpp
		$(CC) $(CPPFLAGS) -c $< -o $@

all:		${NAME}

${NAME}:	$(OBJS)
		${CC} ${CPPFLAGS} $(OBJS) -o $(NAME)

clean:
		rm -rf ${OBJS}

fclean:		clean
		rm -rf ${NAME}

re:		fclean
		make

.PHONY	=	all clean fclean re
