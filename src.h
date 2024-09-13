/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:57:26 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/13 17:45:20 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include "./Printf/printf.h"
# include "./minilibx/mlx.h"
# include "./minilibx/mlx_int.h"

# define A_KEY 113
# define Q_KEY 97
# define S_KEY 115
# define D_KEY 100
# define Z_KEY 119
# define W_KEY 122
# define ESC_KEY 65307
# define LEFT_ARROW_KEY 123
# define RIGHT_ARROW_KEY 124
# define DOWN_ARROW_KEY 125
# define UP_ARROW_KEY 126

typedef struct s_image
{
	void	*p;
	void	*c;
	void	*e;
	void	*f;
	void	*w;
	void	*b;
	int		width;
	int		height;
}	t_image;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		collected_c;
	int		total_c;
	int		total_p;
	int		total_e;
	int		on_exit;
	int		total_move;
	int		x;
	int		y;
	t_image	i;
}	t_game;

void	create_texture(t_game *g);
void	destroy_images(t_game *g);
void	display_map(t_game *g);
void	end_game(t_game *g, int victory);
void	flood_fill(char **map_cpy, int x, int y);
void	ft_print_map(char **map);
char	*get_next_line(int fd);
char	**get_map(char *filename);
int		is_all_entity(t_game *g);
int		is_entity_and_p_pos(t_game *g);
int		is_map_closed(char **map);
int		is_map_valid(t_game *g);
int		key_press(int key_code, t_game *g);
void	move_up(t_game *g);
void	move_down(t_game *g);
void	move_left(t_game *g);
void	move_right(t_game *g);
char	**parsing(char *filename, t_game *game);

#endif
