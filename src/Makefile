SRCS		=	main.c algorithm/push_swap.c algorithm/min_len_sort.c algorithm/sorter.c \
				algorithm/calculator.c algorithm/shotcount_calcul.c 

SRC		=	parsing/parsor.c parsing/parsor_bis.c utils/std_utils_a.c utils/parsor_utils.c \
			utils/std_utils_b.c utils/ft_calloc.c utils/ft_split.c instructions/ins_swap.c \
			instructions/ins_rotate.c instructions/ins_rrotate.c instructions/ins_push.c \
			utils/lst_utils.c


OBJS		=	$(SRCS:.c=.o)

OBJ		=	$(SRC:/parsing.c=/parsing.o)

SRCS_BNS	=	checker/checker.c

OBJS_BNS	=	$(SRCS_BNS:checker/.c=checker/.o)

CC			=	cc
NAME		=	push_swap

CFLAGS		=	-Wall -Werror -Wextra -g -I includes
RM			=	rm -f


.PHONY:		all
all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(OBJ) -o $(NAME)

.PHONY:		fclean
fclean:
			$(RM) $(OBJS) $(OBJ)

.PHONY:		clean
clean:
			$(RM) $(OBJS) $(NAME)
.PHONY:		bonus
bonus:
			$(CC) $(CFLAGS) $(OBJ) $(OBJS_BNS)
