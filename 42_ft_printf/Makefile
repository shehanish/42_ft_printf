
NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

SRCS		= ft_printf.c\
							 ft_specifier1.c\
							  ft_specifier2.c\

OBJS		= $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
						cc $(CFLAGS) -c $(SRCS)
						ar rcs $(NAME) $(OBJS)

clean:
						$(RM) $(OBJS)

fclean:			clean
						$(RM) $(NAME)

re:						fclean all


.PHONY:			all clean fclean re