# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/24 10:47:34 by flfinet      #+#   ##    ##    #+#        #
#    Updated: 2018/10/24 11:12:45 by flfinet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -Iincludes/

SRC	= ft_isalnum.c\
          ft_lstadd.c\
          ft_memcpy.c\
          ft_putendl.c\
          ft_strcapitalize.c\
          ft_strdel.c\
          ft_strlcat.c\
          ft_strncpy.c\
          ft_strstr.c\
          ft_div_mod.c\
          ft_swap.c\
          ft_is_negative.c\
          ft_strrev.c\
          ft_isalpha.c\
          ft_memdel.c\
          ft_putendl_fd.c\
          ft_strcat.c\
          ft_strdup.c\
          ft_strlen.c\
          ft_strnequ.c\
          ft_strsub.c\
          ft_isascii.c\
          ft_memalloc.c\
          ft_memmove.c\
          ft_putnbr.c\
          ft_strchr.c\
          ft_strequ.c\
          ft_strmap.c\
          ft_strnew.c\
          ft_strtrim.c\
          ft_isdigit.c\
          ft_memccpy.c\
          ft_memset.c\
          ft_putnbr_fd.c\
          ft_strclr.c\
          ft_striter.c\
          ft_strmapi.c\
          ft_strnstr.c\
          ft_tolower.c\
          ft_atoi.c\
          ft_isprint.c\
          ft_memchr.c\
          ft_putchar.c\
          ft_putstr.c\
          ft_strcmp.c\
          ft_lstdelone.c\
          ft_lstiter.c\
          ft_lstdel.c\
          ft_striteri.c\
          ft_strncat.c\
          ft_strrchr.c\
          ft_toupper.c\
          ft_bzero.c\
          ft_itoa.c\
          ft_memcmp.c\
          ft_putchar_fd.c\
          ft_putstr_fd.c\
          ft_strcpy.c\
          ft_strjoin.c\
          ft_strncmp.c\
          ft_strsplit.c

OBJS = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) -rcs $(NAME) $?

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
