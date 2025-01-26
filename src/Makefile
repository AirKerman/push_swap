SRCS		= main.c parsing/parsor.c parsing/parsor_bis.c utils/ft_calloc.c \
			utils/ft_split.c utils/parsor_utils.c utils/std_utils.c utils/lst_utils.c \
			utils/parsor_utils algorithm/push_swap.c algorithm/min_len_sort.c \
			instructions/ins_swap.c instructions/ins_rotate.c instructions/ins_rrotate.c \
OBJS		= $(SRCS:.c=.o)

CC			= cc
INCLUDES	= -I includes -o
NAME		= push_swap

CFLAGS		= -Wall -Werror -Wextra -I includes -o
RM			= rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(NAME) $(OBJS)

.PHONY:		all
