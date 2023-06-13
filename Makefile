CC = gcc

NAME = minishell

LIBFT = Libft/libft.a

SRC =	main.c \
	history.c \
	variables.c \
	built_ins.c \
	exp_set.c \
	env_managing.c \
	signals.c \
	cd.c \
	variable_utils.c \
	printer.c \
	tomfoolery.c \

SRCC = 	parseutils.c \
	parseutils2.c \
	parsing_1.c \
	parsing_2.c \
	print_cmd_nodes.c \
#	parsing_3.c \

PTH = source/

PTHC = source_cringe/

FLAGS = -Wall -Werror -Wextra

SRC := $(addprefix $(PTH),$(SRC))

SRCC := $(addprefix $(PTHC),$(SRCC))

OBJ_S = $(SRC:.c=.o)

OBJ_C = $(SRCC:.c=.o)

all: $(NAME)

libcomp:
		@make -C Libft

$(NAME): libcomp $(OBJ_S) $(OBJ_C)
	$(CC) $(FLAGS) $(OBJ_S) $(OBJ_C) $(LIBFT) -o $(NAME) -lreadline 
	@echo "\033[94m$(NAME) ready\033[0m"

libclean:
		@make clean -C Libft

clean:		libclean
		rm -rf $(OBJ_S)
		rm -rf $(OBJ_C)

libfclean:
		@make fclean -C Libft

fclean:   	libfclean clean
		rm -rf $(NAME)
		rm -rf $(NAME2)
		@echo "\033[95m$(NAME) removed\033[0m"
		
re: clean all

.PHONY: all re clean fclean bonus

.SILENT:
