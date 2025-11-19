NAME := libft.a

# --- SRC/DIR ---#

INCLUDE_DIR = includes/

GNL_DIR := gnl/

GNL_SRCS := get_next_line_utils.c \
			get_next_line.c

SRCS += $(addprefix $(GNL_DIR), $(GNL_SRCS))

PRINT_DIR := printf/

PRINT_SRCS :=   ft_print.c \
				ft_upwritex.c \
				ft_writec.c \
				ft_writenb.c \
				ft_writep.c \
				ft_writes.c \
				ft_writeunb.c \
				ft_writex.c

SRCS += $(addprefix $(PRINT_DIR), $(PRINT_SRCS))

LST_DIR := lst/

LST_SRCS := ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

SRCS += $(addprefix $(LST_DIR), $(LST_SRCS))

MEM_DIR := mem/

MEM_SRCS := ft_memcpy.c \
			ft_memset.c \
			ft_memcmp.c \
			ft_memchr.c \
			ft_memmove.c \
			ft_realloc.c \

SRCS += $(addprefix $(MEM_DIR), $(MEM_SRCS))

STR_DIR := str/

STR_SRCS := ft_strchr.c \
			ft_strrchr.c \
			ft_strlcat.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strlcpy.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_split.c \
			ft_atoi.c \
			ft_itoa.c \
			ft_strlen.c \
			ft_strstr.c \
			ft_atod.c 	\
			ft_atof.c 	\
			ft_free_split.c \
			ft_size_of_split.c\
			
SRCS += $(addprefix $(STR_DIR), $(STR_SRCS))

VECTOR_DIR := vector/

VECTOR_SRCS := vector.c \
		vector_add.c \
		vector_memory_manage.c\
		vector_geter.c \
		vector_del.c \


SRCS += $(addprefix $(VECTOR_DIR), $(VECTOR_SRCS))

OTHER_DIR := other/

OTHER_SRCS := ft_calloc.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_bzero.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_tolower.c \
				ft_toupper.c \

SRCS += $(addprefix $(OTHER_DIR), $(OTHER_SRCS)) 

UTILS := utils

OBJS := $(addprefix $(UTILS)/,$(SRCS:.c=.o))
DEPS := $(addprefix $(UTILS)/,$(SRCS:.c=.d))

AR = ar
ARFLAGS = -rcs
CC = cc
CPPFLAGS += -MMD -MP $(addprefix -I, $(INCLUDE_DIR))
CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(UTILS)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(UTILS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
