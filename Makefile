FT		= mains/s_main.cpp

STL		= mains/s_main.cpp

# FT		= ite_n0b.cpp

# STL		= ite_n0b.cpp

RM 			= rm -rf

FLAGS 		= -Wall -Wextra -Werror -g -std=c++98 -O0 #-fsanitize=address

NAME		= ft

STL_NAME	= std

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