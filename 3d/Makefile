######################### source files ###############################

MANDA_GAME		= manda_game

MANDA_PARSER	= manda_parser

BONUS_GAME		= bonus_game

BONUS_PARSER	= bonus_parser

MANDA_PARSER_SRCS	=	$(MANDA_PARSER)/ft_parsing.c \
						$(MANDA_PARSER)/ft_check_walls.c \
						$(MANDA_PARSER)/ft_check_around.c \
						$(MANDA_PARSER)/ft_parse_map.c \
						$(MANDA_PARSER)/ft_parse_player.c \
						$(MANDA_PARSER)/ft_set_elements.c \
						$(MANDA_PARSER)/ft_add_element.c \
						$(MANDA_PARSER)/ft_add_color.c \
						$(MANDA_PARSER)/ft_split_ky_vl.c

MANDA_GAME_SRCS		=	$(MANDA_GAME)/main.c \
						$(MANDA_GAME)/ft_intersection.c \
						$(MANDA_GAME)/ft_face_list.c \
						$(MANDA_GAME)/ft_clean_up.c \
						$(MANDA_GAME)/ft_texture.c \
						$(MANDA_GAME)/ft_rendering.c  \
						$(MANDA_GAME)/ft_cast_rays.c \
						$(MANDA_GAME)/ft_move_plr.c \
						$(MANDA_GAME)/cube_utils.c \
						$(MANDA_GAME)/ft_check_next.c

BONUS_PARSER_SRCS	=	$(BONUS_PARSER)/ft_parsing_bonus.c \
						$(BONUS_PARSER)/ft_check_walls_bonus.c \
						$(BONUS_PARSER)/ft_check_around_bonus.c \
						$(BONUS_PARSER)/ft_parse_map_bonus.c \
						$(BONUS_PARSER)/ft_parse_player_bonus.c \
						$(BONUS_PARSER)/ft_set_elements_bonus.c \
						$(BONUS_PARSER)/ft_add_element_bonus.c \
						$(BONUS_PARSER)/ft_add_color_bonus.c \
						$(BONUS_PARSER)/ft_split_ky_vl_bonus.c

BONUS_GAME_SRCS		=	$(BONUS_GAME)/main_bonus.c \
						$(BONUS_GAME)/ft_intersection_bonus.c \
						$(BONUS_GAME)/ft_face_list_bonus.c \
						$(BONUS_GAME)/ft_clean_up_bonus.c \
						$(BONUS_GAME)/ft_texture_bonus.c \
						$(BONUS_GAME)/ft_rendering_bonus.c  \
						$(BONUS_GAME)/ft_cast_rays_bonus.c \
						$(BONUS_GAME)/ft_move_plr_bonus.c \
						$(BONUS_GAME)/cube_utils_bonus.c \
						$(BONUS_GAME)/ft_mouse_bonus.c \
						$(BONUS_GAME)/ft_door_ctl_bonus.c \
						$(BONUS_GAME)/ft_mini_map_bonus.c \
						$(BONUS_GAME)/ft_gun_sprite_bonus.c \
						$(BONUS_GAME)/ft_check_next_bonus.c

######################### object files ###############################

MANDA_GAME_OBJS		=	$(MANDA_GAME_SRCS:%c=%o)
MANDA_PARSER_OBJS	=	$(MANDA_PARSER_SRCS:%c=%o)

BONUS_GAME_OBJS		=	$(BONUS_GAME_SRCS:%c=%o)
BONUS_PARSER_OBJS	=	$(BONUS_PARSER_SRCS:%c=%o)

########################### variables #################################

NAME			= cub3D

NAME_BONUS		= cub3D_bonus

LIBFT			= libs/.libft/libft.a

FLAGS			= -Wall -Wextra -Werror

MLX42			= ./libs/.MLX42/build/libmlx42.a -lglfw3

LINK			= -framework Cocoa -framework OpenGL -framework IOKit

############################# rules ###################################

all					: mlx42 libft $(NAME)

libft			:
	make -C ./libs/.libft

mlx42			:
	cmake ./libs/.MLX42 -B ./libs/.MLX42/build && cmake --build ./libs/.MLX42/build --parallel

$(BONUS_GAME)/%.o	: $(BONUS_GAME)/%.c ./include/bonus.h
	cc -c  $(FLAGS) $< -o $@
	
$(BONUS_PARSER)/%.o	: $(BONUS_PARSER)/%.c ./include/bonus_parser.h
	cc -c  $(FLAGS) $< -o $@

$(MANDA_GAME)/%.o	: $(MANDA_GAME)/%.c ./include/manda.h
	cc -c   $(FLAGS) $< -o $@

$(MANDA_PARSER)/%.o	: $(MANDA_PARSER)/%.c ./include/manda_parser.h
	cc -c   $(FLAGS) $< -o $@

$(NAME)				: $(LIBFT) $(MANDA_GAME_OBJS) $(MANDA_PARSER_OBJS)
	cc  $(FLAGS) $(MANDA_GAME_OBJS) $(MANDA_PARSER_OBJS)  $(LINK) \
		$(LIBFT) $(MLX42) -O3 -ffast-math -o $(NAME)

$(NAME_BONUS)		:  $(LIBFT) $(BONUS_GAME_OBJS) $(BONUS_PARSER_OBJS)
	cc  $(FLAGS) $(BONUS_GAME_OBJS) $(BONUS_PARSER_OBJS)  $(LINK) $(LIBS) \
		$(LIBFT) $(MLX42) -O3 -ffast-math -o $(NAME_BONUS)
	
bonus				: libft mlx42 $(NAME_BONUS)
	
clean				:
	rm -rf ./libs/.MLX42/build
	make -C ./libs/.libft clean
	rm -rf $(MANDA_PARSER_OBJS)
	rm -rf $(MANDA_GAME_OBJS)
	rm -rf $(BONUS_PARSER_OBJS)
	rm -rf $(BONUS_GAME_OBJS)

fclean				: clean
	make -C ./libs/.libft fclean
	rm -rf $(NAME_BONUS)
	rm -rf $(NAME)

re					: fclean all
