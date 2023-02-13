################  COLORS	##################
L_RED			=			\033[0;31m
L_REDB			=			\033[1;31m
L_WHITE			=			\033[0;37m
L_WHITEB		=			\033[1;37m
L_YELLOW		=			\033[0;33m
L_YELLOWB		=			\033[1;33m
L_GREEN			=			\033[0;32m
L_GREENB		=			\033[1;32m
################ LIBFT		##################
PATH_LIBFT		=			./libft/srcs/
FLAGS_LIBFT		=			-L$(PATH_LIBFT) -lft
################ SOURCES	##################
NAME			=			push_swap
HEADER			=			push_swap.h $(addprefix $(PATH_LIBFT), libft.h)
SRCS			=			stack_utils.c actions.c actions_two.c actions_three.c \
							err.c minimum_sort.c radix_sort.c utils.c
OBJS			=			$(SRCS:.c=.o)
################ FLAGS		##################
FLAGS			=			-Wall -Werror -Wextra
################ RULES		##################

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) push_swap.c -L$(PATH_LIBFT) -I$(PATH_LIBFT) -lft $(OBJS) $(FLAGS) $(FLAGS_LIBFT) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -L$(PATH_LIBFT) -I$(PATH_LIBFT) -lft $(FLAGS_LIBFT) $< -o $@

libft:
	@$(MAKE) -C $(PATH_LIBFT) --no-print-directory

clean:
	@$(MAKE) $@ -C $(PATH_LIBFT) --no-print-directory
	@rm	-f $(OBJS)

n:
	norminette $(SRCS) $(HEADER)

fclean: clean
	@$(MAKE) $@ -C $(PATH_LIBFT) --no-print-directory
	@rm	-f $(NAME)

re: fclean all

.PHONY: libft