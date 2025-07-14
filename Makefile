NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

HEADER = philo.h

SRC =	philo.c\
		ft_isalpha.c\
		ft_isdigit.c\
		init_philo.c\
		ft_atoi.c\
		routine_philo.c\
		ft_timeing.c\

OSRC = $(SRC:%.c=%.o)

all : $(NAME)

%.o : %.c $(HEADER)
	@$(CC) -c $< $(CFLAGS) -c -o $@
	@echo "Compiling" $< "to" $@

$(NAME) : $(OSRC)
	@$(CC) $(CFLAGS) $(OSRC) -o $(NAME)

clean:
	@rm -f $(OSRC)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean