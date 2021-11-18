NAME			=		so_long
LIBFT			=		libft/libft.a
MLX				=		mlx/libmlx.a
MLX_PATH		=		mlx/
LIBFT_PATH		=		libft/
SRC_PATH		=		src/
SRC 		= 			ft_so_long.c              ft_print_msg.c           ft_check_file_validity.c   \
						ft_get_next_line.c        ft_initialize.c          ft_parse_map.c             \
						ft_check_map_validity.c   ft_display_program.c     ft_put_texture.c           \
						ft_draw.c                 ft_handle_moves.c        ft_free_memory.c           \
						ft_actions.c              ft_move_enemy.c			
OBJ 			=		$(patsubst %.c,%.o,$(addprefix $(SRC_PATH),$(SRC)))
D_FILES 		=		$(patsubst %.c,%.d,$(addprefix $(SRC_PATH), $(SRC)))
OPTFLAGS 		=		-O2
CFLAGS 			= 		-Wall -Wextra -Werror

all 			: 		$(LIBFT) $(MLX) $(NAME)

$(LIBFT)		:		
						@echo "Compiling libft..."
						@make -s -C $(LIBFT_PATH)
						@echo "libft is compliled"

$(MLX)			:		
						@echo "Compiling libmlx..."
						@make -s -C $(MLX_PATH)
						@echo "libmlx is compliled"

$(NAME)		 	:		$(OBJ)
						gcc $(CFLAGS) $(OPTFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
						@echo "Project is ready to use"

%.o 			: 		%.c
						gcc $(CFLAGS) $(OPTFLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean 			: 
						@make -C $(LIBFT_PATH) clean
						@make -C $(MLX_PATH) clean
						@rm -f $(OBJ) $(D_FILES)

fclean 			: 		clean
						@make -C $(LIBFT_PATH) fclean
						@rm -f $(NAME)

re 				: 		fclean all

.PHONY			: 		all clean fclean re