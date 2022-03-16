NAME	= cub3d
HEADER	= cub3d.h

CC		= cc
FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -I. -Imlx -Ilibft
OPTFLAGS = -O2

SRC		= main.c \
			parsing/init_data.c \
			parsing/read_parse_file.c \
			parsing/parser_map.c \
			parsing/color.c \
			parsing/texture.c \
			parsing/errors_parsing.c \
			parsing/check_map.c \

OBJ = $(patsubst %.c, %.o, $(SRC))

.PHONY:	all clean fclean re libft mlx

.o: .c $(HEADER)
	@ $(CC) $(CFLAGS) $(OPTFLAGS) -c $< -o $@

LIBFT_A		=   libft/libft.a

all:	mlx libft ${NAME}

$(NAME): $(OBJ) $(HEADER)
		@$(CC) $(OBJ) $(LIBFT_A) -Llibft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

mlx:
		@make -C mlx/

libft:
		@make -C libft/

clean:
		@rm -f $(OBJ)
		@make -C libft clean
		@make -C mlx clean
		
fclean:	clean
		@rm -f ${NAME}
		@rm -f libft/libft.a
		@rm -f mlx/libmlx.a
		@rm -rf a.out*
		@rm -rf */a.out*
		@rm -rf *.gch
		@rm -rf */*.gch
		
re:		fclean all
