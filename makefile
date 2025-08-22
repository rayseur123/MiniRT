NAME := minirt

# --- SRC/DIR --- #

SRC_DIR := srcs/

SRCS += minirt.c

# --- LIBS TARGET --- #

LIBS_TARGET :=			\
	libs/libft/libft.a 	\

LIBS := $(patsubst lib%.a, %, $(notdir $(LIBS_TARGET)))

# --- INCLUDES --- #

INCLUDES := includes/

# --- OBJS/DEPS --- #

OBJS_DIR := .build/objs/

OBJS := $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))


DEPS := $(OBJS:.o=.d)

# --- FLAGS --- #

CPPFLAGS += -MMD -MP $(addprefix -I,$(INCLUDES)) \
					 $(addprefix -I,$(addsuffix $(INCLUDES),$(dir $(LIBS_TARGET))))

CFLAGS += -g3 -Wall -Wextra -Werror

LFLAGS += 	$(addprefix -L,$(dir $(LIBS_TARGET))) \
			$(addprefix -l,$(LIBS)) \
			-lreadline

# --- COMPILATER --- #

CC = cc

# --- EXEC --- #

all : $(NAME)

$(NAME) : $(LIBS_TARGET) $(OBJS)
	$(CC) $^ $(LFLAGS) -o $@

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(LIBS_TARGET) : force
	$(MAKE) -C $(dir $@)

force:

.PHONY : clean fclean all re print-% debug force

clean:
	rm -rf .build
	$(MAKE) clean -C $(dir $(LIBS_TARGET))

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(dir $(LIBS_TARGET))

re:
	$(MAKE) fclean
	$(MAKE) all

debug: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=valgrind_readline.supp ./$(NAME)

norme:
	norminette $(SRC_DIR)$(SRCS)

print-%:
	@echo $(patsubst print-%,%,$@)=
	@echo $($(patsubst print-%,%,$@))

-include $(DEPS)
