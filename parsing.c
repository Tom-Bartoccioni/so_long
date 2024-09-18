/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:09:55 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/17 14:23:00 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

int	is_all_entity(t_game *g)
{
	int	i;
	int	j;

	j = -1;
	g->total_c = 0;
	g->total_p = 0;
	g->total_e = 0;
	while (g->map[++j])
	{
		i = -1;
		while (g->map[j][++i])
		{
			if (g->map[j][i] == 'P')
				g->total_p++;
			else if (g->map[j][i] == 'E')
				g->total_e++;
			else if (g->map[j][i] == 'C')
				g->total_c++;
		}
	}
	if (g->total_p != 1 || g->total_e != 1 || g->total_c < 1)
		return (0);
	return (1);
}

int	is_only_entity(t_game *g)
{
	int	i;
	int	j;

	j = -1;
	while (g->map[++j])
	{
		i = -1;
		while (g->map[j][++i])
		{
			if (g->map[j][i] != 'P' && g->map[j][i] != 'E'
				&& g->map[j][i] != 'C' && g->map[j][i] != 'S'
				&& g->map[j][i] != '0' && g->map[j][i] != '1')
				return (0);
		}
	}
	return (1);
}

void	get_p_and_e_pos(t_game *g)
{
	int	i;
	int	j;

	j = -1;
	while (g->map[++j])
	{
		i = -1;
		while (g->map[j][++i])
		{
			if (g->map[j][i] == 'P')
			{
				g->x = j;
				g->y = i;
			}
			else if (g->map[j][i] == 'S')
			{
				g->e_x = j;
				g->e_y = i;
			}
		}
	}
}

void	flood_fill(char **map_cpy, int x, int y)
{
	if (!map_cpy || map_cpy[x][y] == '1' || map_cpy[x][y] == 'F')
		return ;
	map_cpy[x][y] = 'F';
	flood_fill(map_cpy, x + 1, y);
	flood_fill(map_cpy, x - 1, y);
	flood_fill(map_cpy, x, y + 1);
	flood_fill(map_cpy, x, y - 1);
}

char	**parsing(char *filename, t_game *g)
{
	g->map = get_map(filename);
	if (!g->map)
		return (NULL);
	g->x = 0;
	g->y = 0;
	if (!is_map_valid(g))
	{
		ft_free_tab(g->map);
		return (NULL);
	}
	return (g->map);
}
