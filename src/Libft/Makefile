NAME= libft.a

SRCS= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c\
		ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c\
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c\
		ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c\
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c get_next_line_utils.c

BSRCS= ft_lstnew.c ft_lstsize.c ft_lstadd_front.c ft_lstlast.c ft_lstdelone.c\
		ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstadd_back.c

COMP_LIB = ar rcs
RM= rm -f
CC= cc
CC_FLAGS= -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)
BOBJS= $(BSRCS:.c=.o)
ADD = $(SRCS)

all:$(NAME)

bonus: $(BOBJS) $(BSRCS)
	$(COMP_LIB) $(NAME) $(BOBJS)
	touch bonus

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(BOBJS)
	$(RM) bonus

re: fclean all

$(OBJS):
	$(CC) $(CC_FLAGS) $(ADD)

$(NAME): $(OBJS)
	$(COMP_LIB) $(NAME) $(OBJS)