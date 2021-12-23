NAME    =  base

SRC     = main.cpp

OBJ     = $(SRC:.cpp=.o)

CC      = clang++
CFLAGS  = -Wall -Wextra -Werror -std=c++98

RM      = rm
RFLAGS  = -rf

all: $(NAME)
	@echo "./$(NAME) created "

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

.cpp.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(RFLAGS) $(OBJ)

fclean: clean
	@$(RM) $(RFLAGS) $(NAME)

re: fclean all

.PHONY: all clean fclean re