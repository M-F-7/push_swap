NAME = push_swap

OPTIONS = -I -c $(MY_INCLUDES)

SRC = src/main.c \
		src/little_sort_utils.c \
		src/little_sort.c \
		src/utils_sort.c \
		src/debug.c \
		src/swap.c \
		src/push.c \
		src/rotate.c \
		src/rev_rotate.c \
		src/stack_utils.c \
		src/errors.c \
		src/sort_stack.c \
		src/stack_init.c \
		libft/printf/ft_printf.c \
		libft/printf/ft_putchar.c \
		libft/printf/ft_putstr.c \
		libft/printf/ft_putnbr.c \
		libft/printf/ft_putnbr_base.c \
		libft/printf/ft_putptr.c \
		libft/printf/ft_putnbr_us.c \
		libft/ft_split.c \
		libft/ft_strlen.c \
		libft/ft_atoi.c \
		libft/ft_isdigit.c \
		libft/ft_putstr_fd.c \
		libft/ft_putchar_fd.c 



OBJ = $(SRC:.c=.o)

INC = push_swap.h \
 	libft/libft.h \
	libft/printf/ft_printf.h

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

all : $(NAME) 

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

clean :  
	rm -f $(OBJ) 

fclean : clean 
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all

