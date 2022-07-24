# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 16:08:58 by mrojas-e          #+#    #+#              #
#    Updated: 2022/06/25 18:14:33 by mrojas-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	cypher
CC			=	c++ -Wall -Werror -Wextra -std=c++98
RM			=	rm -rf
SRC			=	cypher.cpp

all:			$(NAME)

$(NAME):		$(OBJS)
				@tput setaf 05 && printf "*********************************\n"
				@tput setaf 013 && printf "* Sources Succesfully Compiled! \n"
				@$(CC) $(SRC) -o $(NAME)
				@tput setaf 013 && printf "* $(NAME) created               \n"
				@tput setaf 05 && printf "*********************************\n"

clean:
				@$(RM) $(DIR_OBJS)
				@tput setaf 117 && printf "\nObject files DELETED.\n"
				
fclean:			clean
				@$(RM) $(NAME)
				@tput setaf 117 && printf "FULL CLEAN COMPLETED.\n"

re:				fclean all

.PHONY:			all clean fclean re norm
