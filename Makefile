SRCS 	= pipex.c pipex_utils.c ft_split.c pipex_utils1.c ft_calloc.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= srcs/pipex.c

HEADER	= -Iincludes

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror -g
NAME			= pipex

CC				= cc

CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f

OBJS			= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
