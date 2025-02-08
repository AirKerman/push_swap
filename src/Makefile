SRCS		=	main.c parsing/parsor.c parsing/parsor_bis.c utils/ft_calloc.c \
				utils/ft_split.c utils/parsor_utils.c utils/std_utils.c utils/lst_utils.c \
				algorithm/push_swap.c algorithm/min_len_sort.c algorithm/sorter.c instructions/ins_swap.c \
				instructions/ins_rotate.c instructions/ins_rrotate.c instructions/ins_push.c
OBJS		=	$(SRCS:.c=.o)

CC			=	cc
NAME		=	push_swap

CFLAGS		=	-Wall -Werror -Wextra -g -I includes
RM			=	rm -f


.PHONY:		all
all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.PHONY:		fclean
fclean:		$(OBJS)
			$(RM) $(OBJS)

.PHONY:		clean
clean:		$(OBJS)
			$(RM) $(OBJS) $(NAME)

