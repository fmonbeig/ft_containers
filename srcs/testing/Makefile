SHELL = /bin/sh

CXX = c++
CXXFLAGS = -Wall -Wextra

NAME = gtests

INCLUDE = -I../../incs/ -Igtest_incs/ -pthread
LIBGTEST = gtest_incs/libgtest.a

CXXFLAGS += $(INCLUDE)

MAIN = gtest_main.cpp

FILES = vector_test #requests_gtests

CONTAINERS_OBJS_PATH = ../../objs/

CONTAINERS_DIR = configParsing configParsing/AST requests cgi responses socket

CONTAINERS_PATH = $(addprefix $(CONTAINERS_OBJS_PATH), $(CONTAINERS_DIR))
# CONTAINERS_OBJS = $(wildcard $(foreach $(CONTAINERS_PATH)/*.o) #taking all the objects without the main
CONTAINERS_OBJS = $(foreach dir, $(CONTAINERS_PATH) ,$(wildcard $(dir)/*.o))

SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

CONTAINERS_GOOD = $(filter-out $(CONTAINERS_PATH), $(CONTAINERS_OBJS))
all: $(NAME)
	./$(NAME)

$(NAME): $(OBJS)
	@# echo $(CONTAINERS_OBJS)
	@# echo $(CONTAINERS_GOOD)
	@echo "Linking $(NAME)"
	@$(CXX) $(CXXFLAGS) $(MAIN) $(CONTAINERS_GOOD) $(OBJS) $(LIBGTEST) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
