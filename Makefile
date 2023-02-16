NAME=push_swap
BNAME=checker
CC=cc
CFLAGS=-g -ggdb3 -Wall -Wextra -Werror
LIBDIR=./libft
BONUS_DIR=./bonus
SRCDIR=./srcs
HDIR=./header
BONUS_SRCDIR=$(BONUS_DIR)/srcs_bonus
BONUS_HDIR=$(BONUS_DIR)/header_bonus
LIBHDIR=$(LIBDIR)/header
SRCS=	$(SRCDIR)/main.c\
		$(SRCDIR)/list.c\
		$(SRCDIR)/check_args.c\
		$(SRCDIR)/mooves.c\
		$(SRCDIR)/parse.c\
		$(SRCDIR)/sort_rank.c\
		$(SRCDIR)/sort.c\
		$(SRCDIR)/cleanup.c\
		$(SRCDIR)/cmd.c\
		$(SRCDIR)/sort_utils.c\
		$(SRCDIR)/quick_sort.c\
		$(SRCDIR)/insert_sort.c\
		$(SRCDIR)/store.c\
		$(SRCDIR)/min_mooves.c
BONUS_SRCS=	$(BONUS_SRCDIR)/main_bonus.c\
			$(BONUS_SRCDIR)/check_args_bonus.c\
			$(BONUS_SRCDIR)/mooves_bonus.c\
			$(BONUS_SRCDIR)/list_bonus.c\
			$(BONUS_SRCDIR)/execute_bonus.c\
			$(BONUS_SRCDIR)/parse_bonus.c
HD=$(HDIR)/push_swap.h
BONUS_HD=$(BONUS_HDIR)/push_swap_bonus.h
LIB=$(LIBDIR)/libft.a
OBJS=$(SRCS:.c=.o)
BONUS_OBJS=$(BONUS_SRCS:.c=.o)

all: $(NAME) bonus

bonus: $(BNAME)

$(NAME): $(LIB) $(OBJS) $(HD)
	$(CC) $(CFLAGS) -I $(HDIR) $(OBJS) $(LIB) -o $@

$(BNAME): $(LIB) $(BONUS_OBJS) $(BONUS_HD)
	$(CC) $(CFLAGS) -I $(BONUS_HDIR) $(BONUS_OBJS) $(LIB) -o $(BNAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(HDIR) -I $(LIBHDIR) -I $(BONUS_HDIR) -c $< -o $@

$(LIB):
	make -C $(LIBDIR)/

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	make clean -C $(LIBDIR)/

fclean: clean
	rm -f $(NAME)
	rm -f $(BNAME)
	rm -f $(LIB)

re: fclean all

.PHONY: all bonus clean fclean re