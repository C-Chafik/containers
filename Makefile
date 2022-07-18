FT		= main.cpp

STL		= main.cpp

RM 			= rm -f

FLAGS 		= -Wall -Wextra -Werror -g -std=c++98 -O0

NAME		= ft_vector

STL_NAME	= std_vector

CC 			= c++

all:		$(NAME)

$(NAME):
					${CC} ${FLAGS} ${FT} -o ${NAME} -D FT
					${CC} ${FLAGS} ${STL} -o ${STL_NAME} -D STL

clean:
					

fclean:		clean
					${RM} ${NAME}
					${RM} ${STL_NAME}

re:			fclean
			make all
					

.SILENT:

.PHONY: all clean fclean re bonus