SRCS	= main.c ./parsing/parsor.c ./parsing/parsor_bis.c ./utils/ft_calloc.c \\
			./utils/ft_split.c ./utils/parsor_utils.c ./utils/std_utils.c
CC		= cc
INCLUDES	= -I ./includes
NAME	= push_swap

CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

all:		$(NAME)

$(NAME):	$(SRCS)
			$(CC) $(CFLAGS) $(INCLUDES) $(SRCS)

.PHONY:		all
