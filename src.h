/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:57:26 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/09 19:11:56 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include "./Printf/printf.h"
# include "./minilibx/mlx.h"
# include "./minilibx/mlx_int.h"

typedef struct s_image
{
	void	*p;
	void	*c;
	void	*e;
	void	*f;
	void	*w;
	int		width;
	int		height;
}	t_image;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		collected_c;
	int		total_c;
	int		total_p;
	int		total_e;
	int		p_x;
	int		p_y;
	t_image	i;
}	t_game;

void	flood_fill(char **map_cpy, int x, int y);
void	ft_print_map(char **map);
char	*get_next_line(int fd);
char	**get_map(char *filename);
int		is_all_entity(t_game *g);
int		is_entity_and_p_pos(t_game *g);
int		is_map_closed(char **map);
int		is_map_valid(t_game *g);
char	**parsing(char *filename, t_game *game);

#endif
