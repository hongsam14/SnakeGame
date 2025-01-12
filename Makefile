#Makefile

NAME = SnakeGame

CC = g++
CFLAGS = -std=c++11

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	NCURSES = ncursesw
endif
ifeq ($(UNAME_S), Darwin)
	NCURSES = ncurses
endif

all : $(NAME)


$(NAME) : $(OBJS) Makefile
		$(CC) $(CFLAGS) -o $@ $(OBJS) -l$(NCURSES) -lpthread

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
