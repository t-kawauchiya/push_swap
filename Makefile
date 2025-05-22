NAME = push_swap

INCDIR = include/
LIB = lib

SRC_DIR =
SRC_FILES = main.c operation.c t_node_util.c t_stack_util.c compress.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(SRC:.c=.o)

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
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< to $@"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
