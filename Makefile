CC = gcc

NAME = minishell

LIBFT = Libft/libft.a

SRC =	main.c \
	history.c \
	variables.c

PTH = source/

FLAGS = -Wall -Werror -Wextra

SRC := $(addprefix $(PTH),$(SRC))

OBJ_S = $(SRC:.c=.o)

all: $(NAME)

libcomp:
		@make -C Libft

$(NAME): libcomp $(OBJ_S)
	$(CC) $(FLAGS) $(OBJ_S) $(LIBFT) -o $(NAME) -lreadline 
	@echo "\033[94m$(NAME) ready\033[0m"

libclean:
		@make clean -C Libft

clean:		libclean
		rm -rf $(OBJ_S)

libfclean:
		@make fclean -C Libft

fclean:   	libfclean clean
		rm -rf $(NAME)
		rm -rf $(NAME2)
		@echo "\033[95m$(NAME) removed\033[0m"
		
re: clean all

.PHONY: all re clean fclean bonus

.SILENT:
