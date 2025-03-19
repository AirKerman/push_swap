SRCS		=	main.c algorithm/push_swap.c algorithm/min_len_sort.c algorithm/sorter.c \
				algorithm/calculator.c algorithm/shotcount_calcul.c 

OBJS		=	$(SRCS:.c=.o)

PARSINGS	=	parsing/parsor.c parsing/parsor_bis.c

PARSING		=	$(PARSINGS:/parsing.c=/parsing.o)

UTILS		=	utils/std_utils_a.c utils/parsor_utils.c \
				utils/std_utils_b.c utils/ft_calloc.c utils/ft_split.c \
				utils/lst_utils.c

UTIL		=	$(UTILS:/utils.c=/utils.o)

INS			=	instructions/ins_swap.c instructions/ins_rotate.c \
				instructions/ins_rrotate.c instructions/ins_push.c

IN			= 	$(INS:/instructions.c=/instruction.o)

SRCS_BNS	=	checker/checker.c

OBJS_BNS	=	$(SRCS_BNS:checker/.c=checker/.o)

CC			=	cc
NAME		=	push_swap

CFLAGS		=	-Wall -Werror -Wextra -g -I includes
RM			=	rm -f


.PHONY:		all
all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(PARSING) $(UTIL) $(IN) -o $(NAME)

.PHONY:		fclean
fclean:
			$(RM) $(OBJS) $(PARSING) $(UTIL) $(IN)

.PHONY:		clean
clean:
			$(RM) $(OBJS) $(NAME)
.PHONY:		bonus
bonus:
			$(CC) $(CFLAGS) $(PARSING) $(UTIL) $(IN) $(OBJS_BNS)
