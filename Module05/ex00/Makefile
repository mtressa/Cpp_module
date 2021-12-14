NAME = bureaucrat
SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
DFILE = $(patsubst %.cpp, %.d, $(SRC))
FLAG = -std=c++98 -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
		c++ $(FLAG) -o $(NAME) $(OBJ)

%.o : %.cpp
		c++ $(FLAG) -c $< -o $@ -MMD

include $(wildcard $(DFILE))

clean :
		rm -rf $(OBJ)
		rm -rf $(DFILE)

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re