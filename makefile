NAME := miniRT

# --- SRC/DIR --- #


SRC_DIR := srcs/

TEST_DIR := test/

TEST_SRCS := tuples.c \
				matrix.c \

SRCS += $(addprefix $(TEST_DIR), $(TEST_SRCS))

SCENE_DIR := manage_scene/

SCENE_SRCS := manage_tuple.c \
				set_tuple.c   \
				comp_tuple.c   \
				operations_tuple.c \
				manage_float.c \
				manage_canva.c \
				manage_matrix.c \

SRCS_NORME += $(addprefix $(SCENE_DIR), $(SCENE_SRCS))

SRCS += $(addprefix $(SCENE_DIR), $(SCENE_SRCS))

SRCS_NORME += minirt.c

SRCS += minirt.c

# --- LIBS TARGET --- #

LIBS_TARGET :=			\
	libs/libft/libft.a 	\
	libs/minilibx/libmlx.a \

LIBS_INCLUDES := \
	libs/libft/includes/ \
	libs/minilibx/ \

LIBS := $(patsubst lib%.a, %, $(notdir $(LIBS_TARGET)))

SYS_LIBS	=	m X11 Xext
SYS_LIBS	:=	$(addprefix -l, $(SYS_LIBS))

# --- INCLUDES --- #

INCLUDES := includes/

# --- OBJS/DEPS --- #

OBJS_DIR := .build/objs/

OBJS := $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))


DEPS := $(OBJS:.o=.d)

# --- FLAGS --- #

CPPFLAGS += -MMD -MP $(addprefix -I,$(INCLUDES)) \
					 $(addprefix -I, $(LIBS_INCLUDES))

CFLAGS += -g3 -Wall -Wextra -Werror

LFLAGS += 	$(addprefix -L,$(dir $(LIBS_TARGET))) \
			$(addprefix -l,$(LIBS)) \
			-lreadline

# --- COMPILATER --- #

CC = cc

# --- EXEC --- #

all : $(NAME)

$(NAME) : $(LIBS_TARGET) $(OBJS)
	$(CC) $^ $(LFLAGS) -o $@ $(SYS_LIBS)

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
	norminette $(addprefix $(SRC_DIR), $(SRCS_NORME))
	

print-%:
	@echo $(patsubst print-%,%,$@)=
	@echo $($(patsubst print-%,%,$@))

-include $(DEPS)
