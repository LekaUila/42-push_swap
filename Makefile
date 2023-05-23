# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 11:10:23 by lflandri          #+#    #+#              #
#    Updated: 2022/11/22 11:06:04 by lflandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		= push_swap
NAMEL		= ./LIBFT/libft.a

MAKEFLAGS	= --no-print-directory

SRC 		=	main.c\
				parser.c\
				list_interaction_rotate.c\
				list_interaction_push_swap.c\
				list_pivot.c\
				list_pivot_untils.c\
				list_addon.c\
				list_addon_bis.c\
				main_untils.c\
				ft_len_split.c\
				free_and_cie.c\
				less300.c\
				ft_atoiwo.c

#couleur
BLACK		=\\e[0;30m
GREY		=\\e[1;30m
BLACKRED	=\\e[0;31m
PINK		=\\e[1;31m
BLACKGREEN	=\\e[0;32m
WHITEGREEN	=\\e[1;32m
ORANGE		=\\e[0;33m
YELLOW		=\\e[1;33m
BLACKBLUE	=\\e[0;34m
WHITEBLUE	=\\e[1;34m
BLACKPURPLE	=\\e[0;35m
WHITEPURPLE	=\\e[;1;35m
BLACKCYAN	=\\e[0;36m
WHITECYAN	=\\e[1;36m
WHITEGREY	=\\e[0;37m
WHITE		=\\e[1;37m

NEUTRE		= \\e[0;m

all :		
			@echo -n "${BLACKCYAN}"
			@echo " .########..##.....##..######..##.....##...........######..##......##....###....########. "
			@echo " .##.....##.##.....##.##....##.##.....##..........##....##.##..##..##...##.##...##.....## "
			@echo " .##.....##.##.....##.##.......##.....##..........##.......##..##..##..##...##..##.....## "
			@echo " .########..##.....##..######..#########...........######..##..##..##.##.....##.########. "
			@echo " .##........##.....##.......##.##.....##................##.##..##..##.#########.##....... "
			@echo " .##........##.....##.##....##.##.....##..........##....##.##..##..##.##.....##.##....... "
			@echo " .##.........#######...######..##.....##...........######...###..###..##.....##.##....... "
			@echo "${NEUTRE}"
			@make ${NAME}
			@echo "${WHITEGREEN}PROGRAMME \"${NAME}\" PRET POUR EXECUTION !${NEUTRE}"

${NAMEL}:
			@cd LIBFT && make

${NAME}: ${NAMEL} ${SRC}
			@echo "${BLACKPURPLE}============== CRÉATION PUSH SWAP ============${WHITE}" 
			gcc  -Wall -Wextra -Werror  -o ${NAME} ${SRC} ${NAMEL}
			@echo "${BLACKPURPLE}============ FIN CRÉATION PUSH SWAP ==========${NEUTRE}" 

clean :
			@echo -n "${BLACKRED}"
			rm -f ${PO}
			@echo -n "${NEUTRE}"
			@cd LIBFT && make clean

fclean :	clean
			@cd LIBFT && make fclean
			@echo -n "${BLACKRED}"
			rm -f ${NAME}
			@echo -n "${NEUTRE}"

bonus :
			@make BONUS=42

re :		fclean all

rebonus : fclean bonus

.PHONY : all clean fclean re bonus