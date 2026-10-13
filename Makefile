NAME		= test
CC			= cc

CFLAGS		= -Wall -Wextra -Werror

LIBFT_DIR	= ./libft_prj
# LIBFT_DIR	= ../libft

FT_SRCS		= $(wildcard $(LIBFT_DIR)/ft_*.c)
TEST_SRCS	= main.c $(wildcard libft/test_*.c)

ifeq ($(shell uname), Linux)
	LDLIBS = -lbsd
endif

$(NAME): $(FT_SRCS) $(TEST_SRCS) $(LIBFT_DIR)/libft.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) $(FT_SRCS) $(TEST_SRCS) -o $(NAME) $(LDLIBS)

all: $(NAME)

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all run clean re

