NAME = libftprintf.a

CC = cc
CC_FLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

SRC_FILES = 
OBJS = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re