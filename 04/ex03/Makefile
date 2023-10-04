# **************************************************************************** #
#	                                                                          #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 16:06:09 by bgrulois          #+#    #+#              #
#    Updated: 2023/10/04 16:06:45 by bgrulois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =    recap

SRCS_FILES    =    main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp \
                MateriaSource.cpp 

INC_FILES    =    AMateria.hpp ICharacter.hpp Character.hpp Ice.hpp Cure.hpp \
                IMateriaSource.hpp MateriaSource.hpp

SRCS    =    $(addprefix srcs/, $(SRCS_FILES))

INCS    =    $(addprefix includes/, $(INC_FILES))

CXX    =    c++

CPPFLAGS    =    -Wall -Wextra -Werror -std=c++98 -I./includes -g3

OBJS_FILES    =    $(SRCS_FILES:%.cpp=%.o)

OBJS    =    $(addprefix objs/, $(OBJS_FILES))

DEP        =    $(OBJS:%.o=%.d)

all    :    $(NAME)

$(NAME)	:	$(OBJS)
	$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean	:
	rm -rf $(OBJS) $(DEP)
	rm -rf objs/

fclean	:	clean
	rm -rf $(NAME)

re	:	fclean all

objs/%.o	: srcs/%.cpp $(INCS)
	mkdir -p objs
	$(CXX) $(CPPFLAGS) -MMD -o $@ -c $<

.PHONY: all clean fclean re