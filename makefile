NAME := miniRT

NAME_BONUS := miniRT_bonus

# ---------------------------------------------------------#
#                       DIRECTORIES                        #
# ---------------------------------------------------------#

SRC_DIR     := srcs/
SCENE_DIR   := manage_scene/
PARSING_DIR := parsing/
BONUS_DIR   := bonus/

CANVA_DIR   := canva/
FLOAT_DIR   := float/
TUPLE_DIR   := tuple/
MATRICE_DIR := matrice/
RGB_DIR     := rgb/
TRANS_DIR   := transformation/
RAY_DIR     := ray/
WORLD_DIR   := world/
LIGHT_DIR   := light/
SHADOW_DIR  := shadow/
OBJECTS_DIR := object/

# ---------------------------------------------------------#
#                       SOURCE FILES                       #
# ---------------------------------------------------------#

PARSING_SRC := 	file_manage.c \
				parsing.c \
				parse_objs.c \
				parse_sphere.c \
               	parse_camera.c \
				parse_light.c \
				parse_plane.c \
				parse_cylindre.c \
               	parse_ambient.c \
			   	get_parsing.c \
			   	error_manage.c\

CANVA_SRCS  := 	manage_canva.c \
				camera.c \
				keyhook.c \
				render.c \
				clean.c  \

FLOAT_SRCS  := 	manage_float.c \
				random_double.c \

TUPLE_SRCS  := 	manage_tuple.c \
				set_tuple.c \
				comp_tuple.c \
				operations_tuple.c \

MATRICE_SRCS := operations_matrix.c \
				matrix_is_equal.c \
				transposition_matrix.c \
				cofactor_matrix.c \
				minor_matrix.c \
				inversing_matrix.c \
				submatrice_matrix.c \
				determining_matrix.c \
				set_identity_matrix.c \
				matrix_utils.c \

RGB_SRCS    := 	manage_rgb.c \
				rgb_operations.c \

TRANS_SRCS  := 	scaling.c \
				translation.c \
				rotation.c \

RAY_SRCS    := 	ray.c \
				set_ray.c \
				vector.c \

WORLD_SRCS  := 	world.c

LIGHT_SRCS  :=	cal_light.c \
				light.c \

SHADOW_SRCS := 	shadow.c
OBJECTS_SRCS:= 	object.c \
				cylinder.c \
				intersect.c \
				quicksort.c \

# ---------------------------------------------------------#
#                BUILD SOURCE (MANDATORY)                  #
# ---------------------------------------------------------#

SRCS +=	$(addprefix $(PARSING_DIR), $(PARSING_SRC)) \
		$(addprefix $(SCENE_DIR), $(addprefix $(CANVA_DIR), $(CANVA_SRCS))) \
		$(addprefix $(SCENE_DIR), $(addprefix $(FLOAT_DIR), $(FLOAT_SRCS))) \
		$(addprefix $(SCENE_DIR), $(addprefix $(TUPLE_DIR), $(TUPLE_SRCS))) \
		$(addprefix $(SCENE_DIR), $(addprefix $(MATRICE_DIR), $(MATRICE_SRCS))) \
		$(addprefix $(SCENE_DIR), $(addprefix $(RGB_DIR), $(RGB_SRCS))) \
		$(addprefix $(SCENE_DIR), $(addprefix $(TRANS_DIR), $(TRANS_SRCS))) \
		$(addprefix $(SCENE_DIR), $(addprefix $(RAY_DIR), $(RAY_SRCS))) \
		$(addprefix $(SCENE_DIR), $(addprefix $(WORLD_DIR), $(WORLD_SRCS))) \
		$(addprefix $(SCENE_DIR), $(addprefix $(LIGHT_DIR), $(LIGHT_SRCS))) \
		$(addprefix $(SCENE_DIR), $(addprefix $(SHADOW_DIR), $(SHADOW_SRCS))) \
		$(addprefix $(SCENE_DIR), $(addprefix $(OBJECTS_DIR), $(OBJECTS_SRCS))) \
		$(addprefix $(SCENE_DIR), $(addprefix $(LIGHT_DIR), $(LIGHT_SRCS))) \
		minirt.c \


# ---------------------------------------------------------#
#                BUILD SOURCE (BONUS)                      #
# ---------------------------------------------------------#

CANVA_DIR_BONUS := canva/
CANVA_SRCS_BONUS := manage_canva.c \
						camera.c 	\
						keyhook.c    \
						clean.c	\

BONUS_DIR := bonus/
BONUS_SRCS := bonus.c

SRCS_BONUS +=	$(addprefix $(PARSING_DIR), $(PARSING_SRC)) \
				$(addprefix $(SCENE_DIR), $(addprefix $(CANVA_DIR_BONUS), $(CANVA_SRCS_BONUS))) \
				$(addprefix $(SCENE_DIR), $(addprefix $(FLOAT_DIR), $(FLOAT_SRCS))) \
				$(addprefix $(SCENE_DIR), $(addprefix $(TUPLE_DIR), $(TUPLE_SRCS))) \
				$(addprefix $(SCENE_DIR), $(addprefix $(MATRICE_DIR), $(MATRICE_SRCS))) \
				$(addprefix $(SCENE_DIR), $(addprefix $(RGB_DIR), $(RGB_SRCS))) \
				$(addprefix $(SCENE_DIR), $(addprefix $(TRANS_DIR), $(TRANS_SRCS))) \
				$(addprefix $(SCENE_DIR), $(addprefix $(RAY_DIR), $(RAY_SRCS))) \
				$(addprefix $(SCENE_DIR), $(addprefix $(WORLD_DIR), $(WORLD_SRCS))) \
				$(addprefix $(SCENE_DIR), $(addprefix $(LIGHT_DIR), $(LIGHT_SRCS))) \
				$(addprefix $(SCENE_DIR), $(addprefix $(SHADOW_DIR), $(SHADOW_SRCS))) \
				$(addprefix $(SCENE_DIR), $(addprefix $(OBJECTS_DIR), $(OBJECTS_SRCS))) \
				$(addprefix $(SCENE_DIR), $(addprefix $(LIGHT_DIR), $(LIGHT_SRCS))) \
				$(addprefix $(BONUS_DIR), $(BONUS_SRCS)) \
				minirt.c \

# ---------------------------------------------------------#
#                       LIBRARIES                          #
# ---------------------------------------------------------#

LIBS_TARGET :=	libs/libft/libft.a 	\
				libs/minilibx/libmlx.a \

LIBS := $(patsubst lib%.a, %, $(notdir $(LIBS_TARGET)))

LIBS_INCLUDES := \
	libs/libft/includes/ \
	libs/minilibx/ \

SYS_LIBS	=	m X11 Xext
SYS_LIBS	:=	$(addprefix -l, $(SYS_LIBS))

OBJS_DIR := .build/objs/
OBJS_DIR_BONUS := .build/objs_bonus/

OBJS := $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS_BONUS := $(addprefix $(OBJS_DIR_BONUS), $(SRCS_BONUS:.c=.o))

DEPS := $(OBJS:.o=.d)
DEPS := $(OBJS_BONUS:.o=.d)
# ---------------------------------------------------------#
#                        FLAGS                             #
# ---------------------------------------------------------#


CPPFLAGS += -MMD -MP $(addprefix -I, includes/) \
					 $(addprefix -I, $(LIBS_INCLUDES))

CFLAGS +=  -g3 -Ofast -Wall -Wextra -Werror

LDFLAGS += 	$(addprefix -L,$(dir $(LIBS_TARGET))) \
			$(addprefix -l,$(LIBS)) \
			-lreadline \

CC = cc

# ---------------------------------------------------------#
#                       RULES                              #
# ---------------------------------------------------------#

all : $(NAME)

$(NAME) : $(LIBS_TARGET) $(OBJS)
	$(CC) $^ $(LDFLAGS) -o $@ $(SYS_LIBS)

bonus: fclean $(NAME_BONUS)

$(NAME_BONUS) : $(LIBS_TARGET) $(OBJS_BONUS)
	$(CC) $^ $(LDFLAGS) -o $(NAME) $(SYS_LIBS)

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJS_DIR_BONUS)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(LIBS_TARGET) : force
	$(MAKE) -C $(dir $@)

force:

# ---------------------------------------------------------#
#                       CLEAN                              #
# ---------------------------------------------------------#

clean:
	rm -rf .build
	$(MAKE) clean -C libs/libft/
	$(MAKE) clean -C libs/minilibx/

fclean: clean
	rm -rf $(NAME)
	rm -rf miniRT_bonus
	$(MAKE) fclean -C libs/libft/
	$(MAKE) fclean -C libs/minilibx/

re:
	$(MAKE) fclean
	$(MAKE) all

# ---------------------------------------------------------#
#                      TOOLS                               #
# ---------------------------------------------------------#

debug: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes

norme:
	norminette $(SRC_DIR)

print-%:
	@echo $(patsubst print-%,%,$@)=
	@echo $($(patsubst print-%,%,$@))

.PHONY : clean fclean all re print-% debug force bonus
-include $(DEPS)
