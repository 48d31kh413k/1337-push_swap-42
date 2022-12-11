
NAME = push_swap
BONUS_NAME = checker
LIBFT = libft.a
PRINTF = libftprintf.a

SRC_FILES =	push_swap.c sort.c Utils_functions.c \
		quicksort.c Instructions_1.c Instructions_2.c \
		Instructions_3.c  Instructions_4.c 
BONUS_FILES = checker.c
SRC_DIR = src/
BONUS_DIR = bonus/
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
BONUS = $(addprefix $(BONUS_DIR), $(BONUS_FILES))
OBJ = ${SRC:.c=.o}
OBJB = ${BONUS:.c=.o}
OBJBB = ${filter-out src/push_swap.o ,${OBJ}}
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
FSANITIZE	= -fsanitize=address -g3
LDFLAGS = -L $(SRC_DIR) 
INCLUDE = -I include
RM = rm -rf

all:		$(NAME)

$(NAME) : $(OBJ)
		@make -C libft
		@cp libft/libft.a .
		@make -C printf
		@cp printf/libftprintf.a .
		$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(LIBFT) $(PRINTF) -o $(NAME)

bonus : $(NAME) $(OBJB)
		$(CC) $(CFLAGS) $(OBJBB) $(OBJB) $(INCLUDE) $(LIBFT) $(PRINTF) -o $(BONUS_NAME)

clean :
		make clean -C libft
		make clean -C printf
		${RM} ${OBJ}
		${RM} ${OBJB}

fclean : clean
		@make fclean -C libft
		@make fclean -C printf
		${RM} $(NAME)
		${RM} $(BONUS_NAME)
		${RM} $(LIBFT)
		${RM} libft/$(PRINTF)
		${RM} $(PRINTF)
		${RM} printf/$(PRINTF)

re : fclean all

.PHONY:		all clean fclean re