CC = cc

NAME = minishell

LIBFT = Libft/libft.a

SRC =	main.c \
	free_struct.c \
	history.c \
	variables.c \
	built_ins.c \
	exp_set.c \
	env_managing.c \
	signals.c \
	cd.c \
	cd_2.c \
	variable_utils.c \
	variable_utils_2.c \
	printer.c \
	exit.c \
	tomfoolery.c \
	cmd_err_check.c \
	cmd_err_check_2.c

SRCC = 	parseutils.c \
	parseutils2.c \
	print_cmd_nodes.c \
	parsing_1.c \
	parsing_2.c \
	parsing_3.c \
	parsing_4.c \
	parsing_5.c

SRCE =	exec_1_pipes.c \
	exec_2_redirection.c \
	exec_3_file_redir.c \
	exec_4_commands.c \
	exec_5_trypath.c \
	heredoc.c

PTH = source/

PTHC = source_parse/

PTHE = source_processes/

FLAGS = -Wall -Werror -Wextra

SRC := $(addprefix $(PTH),$(SRC))

SRCC := $(addprefix $(PTHC),$(SRCC))

SRCE:= $(addprefix $(PTHE),$(SRCE))

OBJ_S = $(SRC:.c=.o)

OBJ_C = $(SRCC:.c=.o)

OBJ_E = $(SRCE:.c=.o)

all: $(NAME)

libcomp:
		@make -C Libft

$(NAME): libcomp $(OBJ_S) $(OBJ_C) $(OBJ_E)
	$(CC) $(FLAGS) $(OBJ_S) $(OBJ_C) $(OBJ_E) $(LIBFT) -o $(NAME) -lreadline 
	@echo "\033[94m$(NAME) ready\033[0m"

libclean:
		@make clean -C Libft

clean:		libclean
		rm -rf $(OBJ_S)
		rm -rf $(OBJ_C)
		rm -rf $(OBJ_E)

libfclean:
		@make fclean -C Libft

fclean:   	libfclean clean
		rm -rf $(NAME)
		rm -rf ./.heredoc
		@echo "\033[95m$(NAME) removed\033[0m"
		
re: clean all

.PHONY: all re clean fclean bonus

.SILENT:
