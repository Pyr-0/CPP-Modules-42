# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 16:08:58 by mrojas-e          #+#    #+#              #
#    Updated: 2022/09/08 18:49:06 by mrojas-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	animal
CC_FLAGS	=	-Wall -Werror -Wextra -std=c++98

CC_FLAGS += -g
RM			=	rm -rf
DIR_OBJS	=	./obj/
SRC			=	main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
OBJS 		=	$(SRC:%.cpp=$(DIR_OBJS)%.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				@tput setaf 05 && printf "*********************************\n"
				@tput setaf 05 && printf "* Sources Succesfully Compiled! *\n"
				@$(CXX) $(CC_FLAGS) $(OBJS) -o $(NAME)
				@tput setaf 013 && printf "*   Executable \e[01m\e[04m$(NAME)\e[0m\e[33m created   *\e[0m\n"
				@tput setaf 05 && printf "*********************************\n"

$(OBJS):		$(DIR_OBJS)

$(DIR_OBJS)%.o: $(DIR_SRCS)%.cpp
#				@tput setaf 207 && printf "\nCompiling sources\n$<"
				@$(CXX) $(CC_FLAGS) -c $< -o $@
$(DIR_OBJS):
				@mkdir $@

clean:
				@$(RM) $(DIR_OBJS)
				@tput setaf 01 && printf "\n     object files  deleted.\n"
				
fclean:			clean
				@$(RM) $(NAME)
				@tput setaf 01 && printf "     FULL CLEAN COMPLETED.\n"

re:				fclean all

.PHONY:			all clean fclean re norm
