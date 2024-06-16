CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -rf
# add_philosofers.c
SRC = philosofers.c 
OSRC = $(SRC:.c=.o)
NAME = philo
libft = ./libft/libft.a
ft_printf = ./ft_printf/libftprintf.a
FSANITIZE = -fsanitize=address

all: $(NAME)

$(NAME) : $(OSRC) $(libft) $(ft_printf)
	$(CC) $(CFLAGS) $(FSANITIZE) $(libft) $(ft_printf) $(OSRC) -o $(NAME)

$(libft) :
	$(MAKE) -C ./libft

$(ft_printf) : 
	$(MAKE) -C ./ft_Printf

%.o :%c philosofers.h
	$(CC) -c $(CFLAGS) $< -o $@
	
clean:
	$(RM) $(OSRC)
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./ft_Printf
fclean:
	$(RM) $(OSRC) $(NAKE)
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./ft_Printf
	