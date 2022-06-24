SRCS = main.cpp

OBJS = ${SRCS:.cpp=.o}

RM = rm -rf

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Vector

.cpp.o:
		${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

all: $(NAME)

$(NAME): $(OBJS)
		${CC} ${FLAGS} $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re