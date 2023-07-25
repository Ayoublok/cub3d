# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 19:02:08 by ayylaaba          #+#    #+#              #
#    Updated: 2023/07/22 11:27:38 by ayylaaba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CFLAGS = -Wall -Wextra -Werror

SRCS = 	main.c \
		get_next_line.c	\
		get_next_line_utils.c \
		ft_strdup.c \
		ft_split.c \
		ft_substr.c \
		ft_strcmp.c \
		ft_strtrim.c \
		ft_isdigit.c \
		parcing_char_extention.c \
		parcing_color.c \
		parcing_player_texture.c \

OBJ = ${SRCS:.c=.o}

#OBJBONUS = ${BONUS:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

#bonus : ${OBJBONUS} $(CC) $(OBJBONUS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	rm -f ${OBJ} ${OBJBONUS}

fclean : clean
	rm -f ${NAME}

re : fclean all
