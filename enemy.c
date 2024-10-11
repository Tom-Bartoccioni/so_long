/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:05:54 by tbartocc          #+#    #+#             */
/*   Updated: 2024/10/11 15:04:26 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	enemy_right(t_game *g)
{
	if (g->map[g->e_x][g->e_y + 1] == '1' || g->map[g->e_x][g->e_y + 1] == 'E')
	{
		g->enemy_dir = 1;
		return ;
	}
	if (g->map[g->e_x][g->e_y + 1] == 'P')
		end_game(g, 2);
	if (g->map[g->e_x][g->e_y + 1] == 'C')
		g->collected_c++;
	g->map[g->e_x][g->e_y] = '0';
	mlx_put_image_to_window(g->m, g->win,
		g->i.f, g->e_y * 64, g->e_x * 64);
	g->map[g->e_x][++g->e_y] = 'S';
	if (g->e_y % 2 == 1)
		mlx_put_image_to_window(g->m, g->win,
			g->i.e_b, g->e_y * 64, g->e_x * 64);
	else
		mlx_put_image_to_window(g->m, g->win,
			g->i.e_c, g->e_y * 64, g->e_x * 64);
}

void	enemy_left(t_game *g)
{
	if (g->map[g->e_x][g->e_y - 1] == '1' || g->map[g->e_x][g->e_y - 1] == 'E')
	{
		g->enemy_dir = 0;
		return ;
	}
	if (g->map[g->e_x][g->e_y - 1] == 'P')
		end_game(g, 2);
	if (g->map[g->e_x][g->e_y - 1] == 'C')
		g->collected_c++;
	g->map[g->e_x][g->e_y] = '0';
	mlx_put_image_to_window(g->m, g->win,
		g->i.f, g->e_y * 64, g->e_x * 64);
	g->map[g->e_x][--g->e_y] = 'S';
	if (g->e_y % 2 == 1)
		mlx_put_image_to_window(g->m, g->win,
			g->i.e_b, g->e_y * 64, g->e_x * 64);
	else
		mlx_put_image_to_window(g->m, g->win,
			g->i.e_c, g->e_y * 64, g->e_x * 64);
}

int	loop(t_game *g)
{
	if (g->e_x)
	{
		if (g->frame == 50000)
		{
			if (g->enemy_dir == 0)
				enemy_right(g);
			else
				enemy_left(g);
		}
		g->frame++;
		if (g->frame > 50000)
			g->frame = 0;
	}
	draw_counter(g);
	return (0);
}
