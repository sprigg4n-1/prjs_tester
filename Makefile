NAME		= test
CC			= cc

CFLAGS		= -Wall -Wextra -Werror

LIBFT_DIR	= ../libft

FT_SRCS		= $(wildcard $(LIBFT_DIR)/ft_*.c)
TEST_SRCS	= main.c $(wildcard libft/test_*.c)

$(NAME): $(FT_SRCS) $(TEST_SRCS) $(LIBFT_DIR)/libft.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) $(FT_SRCS) $(TEST_SRCS) -o $(NAME)

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all run clean re

