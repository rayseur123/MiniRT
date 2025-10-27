NAME := miniRT

# --- SRC/DIR --- #

SRC_DIR := srcs/


LIBSTEST_DIR := libs_test/
LIBSTEST_SRCS := u_init.c \
             u_launch.c \
             u_manage.c \
             u_print.c \
             u_libs.c \

TEST_DIR := test/
TEST_SRCS := tuples.c \
				matrix.c \
				rgb.c \
				transformation.c \
				rays.c \
				light.c \
				world.c \
				camera.c \
				object.c \
				shadow.c \

SHADOW_DIR := shadow/
SHADOW_SRCS := shadow.c \

RAY_DIR := ray/
RAY_SRCS := ray.c \
			set_ray.c \
			vector.c \

LIGHT_DIR := light/
LIGHT_SRCS := light.c \
			 cal_light.c \

MSCENE_DIR := scene/
MSCENE_SRCS := scene.c\

WORLD_DIR := world/
WORLD_SRCS := world.c \
				default_world.c \

SPHERE_DIR := sphere/
SPHERE_SRCS := sphere.c \
				draw_sphere.c \

SCENE_DIR := manage_scene/

CANVA_DIR := canva/
CANVA_SRCS := manage_canva.c \
				camera.c 	\

FLOAT_DIR := float/
FLOAT_SRCS := manage_float.c \

MATRICE_DIR := matrice/
MATRICE_SRCS := operations_matrix.c \
				matrix_is_equal.c \
				transposition_matrix.c \
				cofactor_matrix.c \
				minor_matrix.c \
				inversing_matrix.c \
				submatrice_matrix.c \
				determining_matrix.c \
				set_identity_matrix.c \

RGB_DIR := rgb/
RGB_SRCS := manage_rgb.c \
			rgb_operations.c \

TUPLE_DIR := tuple/
TUPLE_SRCS := manage_tuple.c \
			set_tuple.c   \
			comp_tuple.c   \
			operations_tuple.c \

TRANS_DIR := transformation/
TRANS_SRCS := scaling.c \
			translation.c   \
			rotation.c \

SCENE_SRCS += $(addprefix $(CANVA_DIR), $(CANVA_SRCS))
SCENE_SRCS += $(addprefix $(FLOAT_DIR), $(FLOAT_SRCS))
SCENE_SRCS += $(addprefix $(TUPLE_DIR), $(TUPLE_SRCS))
SCENE_SRCS += $(addprefix $(MATRICE_DIR), $(MATRICE_SRCS))
SCENE_SRCS += $(addprefix $(RGB_DIR), $(RGB_SRCS))
SCENE_SRCS += $(addprefix $(TRANS_DIR), $(TRANS_SRCS))
SCENE_SRCS += $(addprefix $(SPHERE_DIR), $(SPHERE_SRCS))
SCENE_SRCS += $(addprefix $(RAY_DIR), $(RAY_SRCS))
SCENE_SRCS += $(addprefix $(WORLD_DIR), $(WORLD_SRCS))
SCENE_SRCS += $(addprefix $(LIGHT_DIR), $(LIGHT_SRCS))
SCENE_SRCS += $(addprefix $(SHADOW_DIR), $(SHADOW_SRCS))

SRCS += $(addprefix $(TEST_DIR), $(TEST_SRCS))
SRCS += $(addprefix $(SCENE_DIR), $(addprefix $(CANVA_DIR), $(CANVA_SRCS)))
SRCS += $(addprefix $(SCENE_DIR), $(addprefix $(FLOAT_DIR), $(FLOAT_SRCS)))
SRCS += $(addprefix $(SCENE_DIR), $(addprefix $(TUPLE_DIR), $(TUPLE_SRCS)))
SRCS += $(addprefix $(SCENE_DIR), $(addprefix $(MATRICE_DIR), $(MATRICE_SRCS)))
SRCS += $(addprefix $(SCENE_DIR), $(addprefix $(RGB_DIR), $(RGB_SRCS)))
SRCS += $(addprefix $(SCENE_DIR), $(addprefix $(TRANS_DIR), $(TRANS_SRCS)))
SRCS += $(addprefix $(SCENE_DIR), $(addprefix $(SPHERE_DIR), $(SPHERE_SRCS)))
SRCS += $(addprefix $(SCENE_DIR), $(addprefix $(RAY_DIR), $(RAY_SRCS)))
SRCS += $(addprefix $(SCENE_DIR), $(addprefix $(WORLD_DIR), $(WORLD_SRCS)))
SRCS += $(addprefix $(SCENE_DIR), $(addprefix $(MSCENE_DIR), $(MSCENE_SRCS)))
SRCS += $(addprefix $(SCENE_DIR), $(addprefix $(LIGHT_DIR), $(LIGHT_SRCS)))
SRCS += $(addprefix $(SCENE_DIR), $(addprefix $(SHADOW_DIR), $(SHADOW_SRCS)))
SRCS += $(addprefix $(LIBSTEST_DIR), $(LIBSTEST_SRCS))
SRCS += minirt.c

# --- CHECK NORME --- #

SRCS_NORME += $(addprefix $(SCENE_DIR), $(SCENE_SRCS))
SRCS_NORME += minirt.c

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

LDFLAGS += 	$(addprefix -L,$(dir $(LIBS_TARGET))) \
			$(addprefix -l,$(LIBS)) \
			-lreadline \



# --- COMPILATER --- #

CC = cc

# --- EXEC --- #

all : $(NAME)

$(NAME) : $(LIBS_TARGET) $(OBJS)
	$(CC) $^ $(LDFLAGS) -o $@ $(SYS_LIBS)

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
