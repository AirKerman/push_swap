SRCS		=	main.c algorithm/push_swap.c algorithm/min_len_sort.c algorithm/sorter.c \
				algorithm/calculator.c algorithm/shotcount_calcul.c 

OBJS		=	$(SRCS:.c=.o)

CONTENTS	=	parsing/parsor.c parsing/parsor_bis.c utils/std_utils_a.c \
			utils/parsor_utils.c utils/std_utils_b.c utils/ft_calloc.c \
			utils/ft_split.c utils/lst_utils.c instructions/ins_swap.c \
			instructions/ins_rotate.c instructions/ins_rrotate.c instructions/ins_push.c

CONTENT		=	$(CONTENTS:.c=.o)


SRCS_BNS	=	checker/checker.c

OBJS_BNS	=	$(SRCS_BNS:.c=.o)

CC			=	cc
NAME		=	push_swap
NAME_CHK	=	push_checker

CFLAGS		=	-Wall -Werror -Wextra -g -I includes
RM			=	rm -f


.PHONY:		all
all:		$(NAME)

$(NAME):	$(OBJS) $(CONTENT)
			$(CC) $(CFLAGS) $(OBJS) $(CONTENT) -o $(NAME)

.PHONY:		clean
clean:
			$(RM) $(OBJS) $(CONTENT) $(OBJS_BNS)

.PHONY:		fclean
fclean:		clean
			$(RM) $(NAME) $(NAME_CHK)

.PHONY:		re
re:			fclean $(NAME)

.PHONY:		bonus
bonus:		$(CONTENT) $(OBJS_BNS)
			$(CC) $(CFLAGS) $(OBJS_BNS) $(CONTENT) -o $(NAME_CHK)
