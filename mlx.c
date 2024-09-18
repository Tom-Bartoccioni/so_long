/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:38:37 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/17 17:21:47 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	create_texture(t_game *g)
{
	g->i.b = mlx_xpm_file_to_image(g->m,
			"./img/background.xpm", &g->i.width, &g->i.height);
	g->i.c = mlx_xpm_file_to_image(g->m,
			"./img/coin.xpm", &g->i.width, &g->i.height);
	g->i.e = mlx_xpm_file_to_image(g->m,
			"./img/exit.xpm", &g->i.width, &g->i.height);
	g->i.f = mlx_xpm_file_to_image(g->m,
			"./img/floor.xpm", &g->i.width, &g->i.height);
	g->i.p = mlx_xpm_file_to_image(g->m,
			"./img/player.xpm", &g->i.width, &g->i.height);
	g->i.e_b = mlx_xpm_file_to_image(g->m,
			"./img/enemy_blank.xpm", &g->i.width, &g->i.height);
	g->i.e_c = mlx_xpm_file_to_image(g->m,
			"./img/enemy_color.xpm", &g->i.width, &g->i.height);
	g->i.w = mlx_xpm_file_to_image(g->m,
			"./img/wall.xpm", &g->i.width, &g->i.height);
	g->i.s = mlx_xpm_file_to_image(g->m,
			"./img/score_bg.xpm", &g->i.width, &g->i.height);
	if (!g->i.b || !g->i.c || !g->i.e || !g->i.f || !g->i.p
		|| !g->i.e_b || !g->i.e_c || !g->i.w || !g->i.s)
		ft_free_struct_and_exit(g);
}

void	destroy_images(t_game *g)
{
	mlx_destroy_image(g->m, g->i.b);
	mlx_destroy_image(g->m, g->i.p);
	mlx_destroy_image(g->m, g->i.e);
	mlx_destroy_image(g->m, g->i.c);
	mlx_destroy_image(g->m, g->i.e_b);
	mlx_destroy_image(g->m, g->i.e_c);
	mlx_destroy_image(g->m, g->i.s);
	mlx_destroy_image(g->m, g->i.w);
	mlx_destroy_image(g->m, g->i.f);
}

void	draw_counter(t_game *g)
{
	char	*count_move;

	count_move = ft_itoa(g->total_move);
	if (!count_move)
		return ;
	mlx_put_image_to_window(g->m, g->win, g->i.s, 1750, 85);
	mlx_string_put(g->m, g->win, 1750, 100, 0x000000, "MOVES : ");
	mlx_string_put(g->m, g->win, 1800, 100, 0x000000, count_move);
	free(count_move);
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
				mlx_put_image_to_window(g->m, g->win, g->i.p, i * 64, j * 64);
			if (g->map[j][i] == 'E')
				mlx_put_image_to_window(g->m, g->win, g->i.e, i * 64, j * 64);
			if (g->map[j][i] == 'C')
				mlx_put_image_to_window(g->m, g->win, g->i.c, i * 64, j * 64);
			if (g->map[j][i] == 'S')
				mlx_put_image_to_window(g->m, g->win, g->i.e_b, i * 64, j * 64);
			if (g->map[j][i] == '1')
				mlx_put_image_to_window(g->m, g->win, g->i.w, i * 64, j * 64);
			if (g->map[j][i] == '0')
				mlx_put_image_to_window(g->m, g->win, g->i.f, i * 64, j * 64);
		}
	}
}
