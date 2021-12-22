NAME = easyfind
FLAG = -std=c++98 -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : main.o
		c++ $(FLAG) -o $(NAME) main.o

%.o : %.cpp
		c++ $(FLAG) -c $< -o $@

clean :
		rm -rf main.o

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re