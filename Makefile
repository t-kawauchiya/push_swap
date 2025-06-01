NAME = push_swap

INCDIR = include/
LIB = lib/

SRC_DIR = src/
SRC_FILES = main.c operation.c compress.c parse.c solve.c  \
						expand_args.c split_with_spaces.c t_node_util.c t_stack_util.c \
						radix_sort.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(SRC:.c=.o)
TEST_DIR = tests/
TEST = test.sh

HEADER=./include/push_swap.h

FT_PRINTF_DIR = ftprintf/
FT_PRINTF = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIB)$(FT_PRINTF) $(FT_PRINTF_DIR)$(FT_PRINTF) 
	$(CC) $(CFLAGS) $(SRC) -L$(LIB) -lftprintf -g -o $(NAME)

$(LIB)$(FT_PRINTF): $(FT_PRINTF_DIR)$(FT_PRINTF)
	@cp $(FT_PRINTF_DIR)$(FT_PRINTF) $(LIB)

$(FT_PRINTF_DIR)$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@ -g
	@echo "Compiled $< to $@"

test: all clean
	@-norminette $(SRC)
	@sh $(TEST_DIR)$(TEST)

clean:
	@rm -f $(OBJ)
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(lib)
	@rm -rf *.dSYM
	@make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
