/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:42:46 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/17 14:24:21 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	ft_print_map(char **map)
{
	int	i;

	i = -1;
	while (map && map[++i])
		ft_printf("%s\n", map[i]);
}

int	is_ber_file(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i] && str[i] != '.' && str[i] != '\0')
		;
	if (ft_strlen(str) == i)
		return (0);
	if (ft_strcmp(str + i, ".ber"))
		return (0);
	return (1);
}

char	**get_map(char *filename)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	**map;

	if (!is_ber_file(filename))
		return (ft_printf("Error: Invalid map name\n"), NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	tmp = "";
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		line = ft_strjoin(line, tmp);
		free(tmp);
	}
	map = ft_split(line, '\n');
	free(line);
	close(fd);
	return (map);
}

int	is_map_closed(char **map)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (map[0][++i])
		if (map[0][i] != '1')
			return (0);
	len = ft_strlen(map[0]);
	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
	}
	j = i - 1;
	i = 1;
	while (map[j][++i])
		if (map[j][i] != '1')
			return (0);
	return (1);
}

int	is_map_valid(t_game *g)
{
	int		i;
	int		j;
	char	**map_cpy;

	if (!is_map_closed(g->map) || !is_all_entity(g) || !is_only_entity(g))
		return (ft_printf("Error: Invalid map\n"), 0);
	get_p_and_e_pos(g);
	map_cpy = ft_tabdup(g->map);
	flood_fill(map_cpy, g->x, g->y);
	j = -1;
	while (map_cpy[++j])
	{
		i = -1;
		while (map_cpy[j][++i])
		{
			if (map_cpy[j][i] == 'C')
				return (ft_printf("Invalid Coin\n"), ft_free_tab(map_cpy), 0);
			if (map_cpy[j][i] == 'E')
				return (ft_printf("Invalid Exit\n"), ft_free_tab(map_cpy), 0);
		}
	}
	ft_free_tab(map_cpy);
	return (1);
}
