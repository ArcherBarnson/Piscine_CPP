# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 10:53:17 by bgrulois          #+#    #+#              #
#    Updated: 2023/09/06 12:37:32 by bgrulois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fragtrap

SRCS	=	ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp \
		main.cpp

OBJS	=	$(SRCS:.cpp=.o)

CC	=	c++

CPPFLAGS=	-Wall -Werror -Wextra -std=c++98


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
