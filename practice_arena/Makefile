# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 16:08:58 by mrojas-e          #+#    #+#              #
#    Updated: 2022/06/26 17:14:57 by mrojas-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	test1
CC			=	c++ -Wall -Werror -Wextra -std=c++98
RM			=	rm -rf
SRC			=	test1.cpp

all:			$(NAME)

$(NAME):		
				@tput setaf 05 && printf "*********************************\n"
				@tput setaf 05 && printf "* Sources Succesfully Compiled! *\n"
				@$(CC) $(SRC) -o $(NAME)
				@tput setaf 013 && printf "* $(NAME) created.               *\n"
				@tput setaf 05 && printf "*********************************\n"

clean:
				@$(RM)
				@tput setaf 117 && printf "\nObject files DELETED.\n"
				
fclean:			clean
				@$(RM) $(NAME)
				@tput setaf 117 && printf "FULL CLEAN COMPLETED.\n"

re:				fclean all

.PHONY:			all clean fclean re norm
