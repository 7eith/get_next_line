# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/03 16:40:54 by amonteli     #+#   ##    ##    #+#        #
#    Updated: 2019/11/08 22:09:23 by amonteli    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

flags		:
	@gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c
	@echo "\033[91mCompiling GET_NEXT_LINE...\033[0m"

gcc		:
	@gcc -c -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
	@echo "\033[91mCompiling GET_NEXT_LINE [without flags!]\033[0m"

fclean	:
	rm *.o
