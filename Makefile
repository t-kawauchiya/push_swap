NAME = push_swap

INCDIR = include/
LIB = lib

SRC_DIR = src/
SRC_FILES = main.c operation.c compress.c parse.c resolve.c \
t_node_util.c t_stack_util.c 
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(SRC:.c=.o)
TEST_DIR = test/
TEST = test.sh

HEADER=./include/push_swap.h

FT_PRINTF_DIR = ftprintf/
FT_PRINTF = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(SRC) -L$(LIB) -lftprintf -g -o $(NAME)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)
	@cp $(FT_PRINTF_DIR)$(FT_PRINTF) $(LIB)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@ -g
	@echo "Compiled $< to $@"

test: all clean
	@-norminette $(SRC)
	@sh $(TEST_DIR)$(TEST)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -rf *.dSYM

re: fclean all

.PHONY: all clean fclean re
