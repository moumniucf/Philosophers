NAME = philo_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g3

HEADER = philo_bonus.h

SRC =	ft_initphilo_bonus.c\
		ft_atoi_bonus.c\
		ft_isdigit_bonus.c\
		ft_isalpha_bonus.c\
		main_bonus.c\
		
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