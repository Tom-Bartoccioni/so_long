/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:57:26 by tbartocc          #+#    #+#             */
/*   Updated: 2024/10/11 15:25:13 by tbartocc         ###   ########.fr       */
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
# define UP_KEY 65362
# define RIGHT_KEY 65363
# define DOWN_KEY 65364
# define LEFT_KEY 65361

typedef struct s_image
{
	void	*p;
	void	*c;
	void	*e;
	void	*f;
	void	*w;
	void	*b;
	void	*e_b;
	void	*e_c;
	void	*s;
	int		width;
	int		height;
}	t_image;

typedef struct s_game
{
	void	*m;
	void	*win;
	char	**map;
	int		collected_c;
	int		enemy_dir;
	int		frame;
	int		total_c;
	int		total_p;
	int		total_e;
	int		on_exit;
	int		total_move;
	int		victory;
	int		x;
	int		y;
	int		e_x;
	int		e_y;
	t_image	i;
}	t_game;

void	create_texture(t_game *g);
void	destroy_images(t_game *g);
void	display_map(t_game *g);
void	draw_counter(t_game *g);
void	end_game(t_game *g, int victory);
void	flood_fill(char **map_cpy, int x, int y);
void	ft_free_struct_and_exit(t_game *g);
void	ft_print_map(char **map);
char	*get_next_line(int fd);
char	**get_map(char *filename);
void	get_p_and_e_pos(t_game *g);
int		is_all_entity(t_game *g);
int		is_only_entity(t_game *g);
int		is_map_closed(char **map);
int		is_map_valid(t_game *g);
int		key_press(int key_code, t_game *g);
int		loop(t_game *g);
void	move_up(t_game *g);
void	move_down(t_game *g);
void	move_left(t_game *g);
void	move_right(t_game *g);
char	**parsing(char *filename, t_game *game);

#endif
