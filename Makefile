stack			= mains/stack_main.cpp

b_stack			= mains/stack_benchmark.cpp

set				= mains/set_main.cpp

b_set			= mains/set_benchmark.cpp

vector			= mains/vector_main.cpp

b_vector		= mains/vector_benchmark.cpp

map				= mains/map_main.cpp

b_map			= mains/map_benchmark.cpp


RM 			= rm -rf

FLAGS 		= -Wall -Wextra -Werror -g -std=c++98 -O0 #-fsanitize=address

NAME		= ft

STL_NAME	= std

B_NAME = b_ft

B_STL = b_std

CC 			= c++

all:		$(NAME)

$(NAME):
					${CC} ${FLAGS} ${vector} -o ${NAME} -D FT
					${CC} ${FLAGS} ${vector} -o ${STL_NAME} -D STL
					${CC} ${FLAGS} ${b_vector} -o ${B_NAME} -D FT
					${CC} ${FLAGS} ${b_vector} -o ${B_STL} -D STL

vector:
					${CC} ${FLAGS} ${vector} -o ${NAME} -D FT
					${CC} ${FLAGS} ${vector} -o ${STL_NAME} -D STL
					${CC} ${FLAGS} ${b_vector} -o ${B_NAME} -D FT
					${CC} ${FLAGS} ${b_vector} -o ${B_STL} -D STL

stack:
					${CC} ${FLAGS} ${stack} -o ${NAME} -D FT
					${CC} ${FLAGS} ${stack} -o ${STL_NAME} -D STL
					${CC} ${FLAGS} ${b_stack} -o ${B_NAME} -D FT
					${CC} ${FLAGS} ${b_stack} -o ${B_STL} -D STL

map:
					${CC} ${FLAGS} ${map} -o ${NAME} -D FT
					${CC} ${FLAGS} ${map} -o ${STL_NAME} -D STL
					${CC} ${FLAGS} ${b_map} -o ${B_NAME} -D FT
					${CC} ${FLAGS} ${b_map} -o ${B_STL} -D STL

set:
					${CC} ${FLAGS} ${set} -o ${NAME} -D FT
					${CC} ${FLAGS} ${set} -o ${STL_NAME} -D STL
					${CC} ${FLAGS} ${b_set} -o ${B_NAME} -D FT
					${CC} ${FLAGS} ${b_set} -o ${B_STL} -D STL


clean:
					

fclean:		clean
					${RM} ${NAME}
					${RM} ${STL_NAME}
					${RM} ${B_NAME}
					${RM} ${B_STL}

re:			fclean
			make all
					

.SILENT:

.PHONY: all clean fclean re bonus