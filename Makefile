CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -rf
SRC = philosofers.c  ft_atoi.c ft_usleep.c add_philosofers.c routine_utils.c
OSRC = $(SRC:.c=.o)
NAME = philo
FSANITIZE = -fsanitize=address

all: $(NAME)

$(NAME) : $(OSRC) $(libft) 
	$(CC) $(CFLAGS) $(libft) $(OSRC) -o $(NAME)

%.o :%c philosofers.h
	$(CC) -c $(CFLAGS) $< -o $@
	
clean:
	$(RM) $(OSRC)
fclean:
	$(RM) $(OSRC) $(NAKE)
re: fclean all
	