/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nanicku <nanicku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:57:01 by mshad             #+#    #+#             */
/*   Updated: 2022/03/16 19:37:56 by nanicku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define W_WIDTH 	800
# define W_HEIGHT	600

// colors
# define RED		"\033[31;1m"
# define YELLOW		"\033[33;1m"
# define RESET		"\033[0m"
# define GREEN		"\033[32;1m"

// keys
# define W			13
# define A			0
# define S			1
# define D			2
# define LEFT		123
# define RIGHT		124
# define ESC		53

typedef struct s_win
{
	void	*mlx;
	void	*win;
}	t_win;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}	t_player;

typedef struct s_map
{
	char	**map_arr;
	int		f_color;
	int		c_color;
	char	*no_tex;
	char	*so_tex;
	char	*ea_tex;
	char	*we_tex ;
}	t_map;

typedef struct s_data
{
	t_win		win;
	t_player	player;
	t_map		map;
}	t_data;

int		main(int argc, char **argv);
t_data	*init_data(void);
void	free_data(t_data *data);
void	read_and_parse_file(t_data *data, const char *map_file);
void	error_exit(char *str);
void	parser_line(t_data *data, char *line);
void	parse_map(t_data *data, char *line);
void	check_file_format(const char *map_path, int fd);
int		check_tex_and_color(t_data *data, char *line);
int		parse_textures(t_data *data, char *str);
void	parsing_tex(t_data *data, char *str);
void	check_tex(char *str);
int		parse_colors(t_data *data, char *str);
int		ft_natoi(const char *str, int len);
int		color_converting(char *str);
void	free_str_arr(char **str_arr);
void	check_map(t_data *data);
void	check_sympols(char **map);
void	check_player(t_data *data);
void	check_borders(char **map, int i);
int		get_height_arr(char **arr);
int		valid_symbol(char **arr, int i, int j, char s);
void	check_plr_lock(t_data *data);
void	check_uncorrect_postion(t_data *data, char s);

#endif