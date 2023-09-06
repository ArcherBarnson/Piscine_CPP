# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 10:53:17 by bgrulois          #+#    #+#              #
#    Updated: 2023/09/06 14:56:26 by bgrulois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	diamondtrap	

SRCS	=	ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp \
		main.cpp

OBJS	=	$(SRCS:.cpp=.o)

CC	=	c++

CPPFLAGS=	-Wall -Werror -Wextra -Wshadow -std=c++98


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
