NAME := miniRT

CC := cc

CFLAGS := -Wall -Wextra -Werror

OBJS_DIR := objs/
SRCS_DIR := srcs/
SRCS := main.c

SRCS := $(addprefix $(SRCS_DIR), $(SRCS))

OBJS = $(SRCS:.c=.o)

all : $(NAME)

fclean : clean
	rm $(NAME)

clean:
	rm -fr $(OBJS_DIR)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR) 
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_D):
	mkdir -p $(OBJ_D)
