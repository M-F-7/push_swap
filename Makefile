NAME = push_swap

OPTIONS = -I -c $(MY_INCLUDES)

SRC = swap.c \
		push.c \
		rotate.c \
		rrotate.c \
		utils.c \
		../libft/printf/ft_printf.c \
		../libft/printf/ft_putchar.c \
		../libft/printf/ft_putstr.c \
		../libft/printf/ft_putnbr.c \
		../libft/printf/ft_putnbr_base.c \
		../libft/printf/ft_putptr.c \
		../libft/printf/ft_putnbr_us.c \
		#../libft/gnl/get_next_line.c

OBJ = $(SRC:.c=.o)

INC = push_swap.h \
 	../libft/libft.h \
	../libft/printf/ft_printf.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME) 

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS)  -c $< -o $@

clean :  
	@rm -f $(OBJ) 

fclean : clean 
	@rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all