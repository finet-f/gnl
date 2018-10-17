##
## Makefile for bsq in /home/finet_f/rendu/Prog_elem/BSQ/CPE_2015_BSQ
##
## Made by Florian Finet
## Login   <finet_f@epitech.net>
##
## Started on  Wed Dec 16 17:51:58 2015 Florian Finet
## Last update Wed Oct 17 15:09:05 2018 Florian Finet
##

NAME = test_gnl

CFLAGS = -Wall -Wextra -Werror -Iinclude/

SRC	= get_next_line.c\
	  main.c

OBJS = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	 clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	 clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	 clang -o $(NAME) main.o get_next_line.o -I libft/includes -L libft/ -lft

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
