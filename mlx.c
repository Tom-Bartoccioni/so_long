/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:38:37 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/13 17:38:57 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	create_texture(t_game *g)
{
	g->i.b = mlx_xpm_file_to_image(g->mlx,
			"./img/background.xpm", &g->i.width, &g->i.height);
	g->i.c = mlx_xpm_file_to_image(g->mlx,
			"./img/coin.xpm", &g->i.width, &g->i.height);
	g->i.e = mlx_xpm_file_to_image(g->mlx,
			"./img/exit.xpm", &g->i.width, &g->i.height);
	g->i.f = mlx_xpm_file_to_image(g->mlx,
			"./img/floor.xpm", &g->i.width, &g->i.height);
	g->i.p = mlx_xpm_file_to_image(g->mlx,
			"./img/player.xpm", &g->i.width, &g->i.height);
	g->i.w = mlx_xpm_file_to_image(g->mlx,
			"./img/wall.xpm", &g->i.width, &g->i.height);
}

void	destroy_images(t_game *g)
{
	mlx_destroy_image(g->mlx, g->i.b);
	mlx_destroy_image(g->mlx, g->i.p);
	mlx_destroy_image(g->mlx, g->i.e);
	mlx_destroy_image(g->mlx, g->i.c);
	mlx_destroy_image(g->mlx, g->i.w);
	mlx_destroy_image(g->mlx, g->i.f);
}

void	display_map(t_game *g)
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
				mlx_put_image_to_window(g->mlx, g->win, g->i.p, i * 64, j * 64);
			if (g->map[j][i] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->i.e, i * 64, j * 64);
			if (g->map[j][i] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->i.c, i * 64, j * 64);
			if (g->map[j][i] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->i.w, i * 64, j * 64);
			if (g->map[j][i] == '0')
				mlx_put_image_to_window(g->mlx, g->win, g->i.f, i * 64, j * 64);
		}
	}
}
