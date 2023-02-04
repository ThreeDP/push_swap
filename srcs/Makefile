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
SRCS			=			push_swap.c stack_utils.c
OBJS			=			$(SRCS:.c=.o)
################ FLAGS		##################
FLAGS			=			-Wall -Werror -Wextra
################ RULES		##################

all: libft $(NAME)

$(NAME):
	$(CC) $(SRCS) $(FLAGS) $(FLAGS_LIBFT) -o $(NAME)

#%.o: %.c $(HEADER)
#	$(CC) $(FLAGS) $(FLAGS_LIBFT) $< -o $@

libft:
	@$(MAKE) -C $(PATH_LIBFT) --no-print-directory

clean:
	@$(MAKE) $@ -C $(PATH_LIBFT) --no-print-directory
	@rm	-f $(OBJS)

fclean: clean
	@$(MAKE) $@ -C $(PATH_LIBFT) --no-print-directory
	@rm	-f $(NAME)

re: fclean all

.PHONY: libft