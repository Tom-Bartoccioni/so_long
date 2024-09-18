/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:23:24 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/17 16:45:24 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	display_floor(t_game *g)
{
	g->map[g->x][g->y] = '0';
	mlx_put_image_to_window(g->m, g->win, g->i.f, g->y * 64, g->x * 64);
}

void	move_up(t_game *g)
{
	if (g->map[g->x - 1][g->y] == '1')
		return ;
	g->total_move++;
	if (g->map[g->x - 1][g->y] == 'S')
		end_game(g, 2);
	if (g->on_exit == 1)
	{
		g->map[g->x][g->y] = 'E';
		mlx_put_image_to_window(g->m, g->win, g->i.e, g->y * 64, g->x * 64);
		g->on_exit = 0;
	}
	else if (g->map[g->x - 1][g->y] == 'E')
	{
		if (g->collected_c == g->total_c)
			end_game(g, 1);
		g->on_exit = 1;
		display_floor(g);
	}
	else if (g->on_exit == 0)
		display_floor(g);
	if (g->map[g->x - 1][g->y] == 'C')
		g->collected_c++;
	g->map[--g->x][g->y] = 'P';
	mlx_put_image_to_window(g->m, g->win, g->i.p, g->y * 64, g->x * 64);
}

void	move_down(t_game *g)
{
	if (g->map[g->x + 1][g->y] == '1')
		return ;
	g->total_move++;
	if (g->map[g->x + 1][g->y] == 'S')
		end_game(g, 2);
	if (g->on_exit == 1)
	{
		g->map[g->x][g->y] = 'E';
		mlx_put_image_to_window(g->m, g->win, g->i.e, g->y * 64, g->x * 64);
		g->on_exit = 0;
	}
	else if (g->map[g->x + 1][g->y] == 'E')
	{
		if (g->collected_c == g->total_c)
			end_game(g, 1);
		g->on_exit = 1;
		display_floor(g);
	}
	else if (g->on_exit == 0)
		display_floor(g);
	if (g->map[g->x + 1][g->y] == 'C')
		g->collected_c++;
	g->map[++g->x][g->y] = 'P';
	mlx_put_image_to_window(g->m, g->win, g->i.p, g->y * 64, g->x * 64);
}

void	move_left(t_game *g)
{
	if (g->map[g->x][g->y - 1] == '1')
		return ;
	g->total_move++;
	if (g->map[g->x][g->y - 1] == 'S')
		end_game(g, 2);
	if (g->on_exit == 1)
	{
		g->map[g->x][g->y] = 'E';
		mlx_put_image_to_window(g->m, g->win, g->i.e, g->y * 64, g->x * 64);
		g->on_exit = 0;
	}
	else if (g->map[g->x][g->y - 1] == 'E')
	{
		if (g->collected_c == g->total_c)
			end_game(g, 1);
		g->on_exit = 1;
		display_floor(g);
	}
	else if (g->on_exit == 0)
		display_floor(g);
	if (g->map[g->x][g->y - 1] == 'C')
		g->collected_c++;
	g->map[g->x][--g->y] = 'P';
	mlx_put_image_to_window(g->m, g->win, g->i.p, g->y * 64, g->x * 64);
}

void	move_right(t_game *g)
{
	if (g->map[g->x][g->y + 1] == '1')
		return ;
	g->total_move++;
	if (g->map[g->x][g->y + 1] == 'S')
		end_game(g, 2);
	if (g->on_exit == 1)
	{
		g->map[g->x][g->y] = 'E';
		mlx_put_image_to_window(g->m, g->win, g->i.e, g->y * 64, g->x * 64);
		g->on_exit = 0;
	}
	else if (g->map[g->x][g->y + 1] == 'E')
	{
		if (g->collected_c == g->total_c)
			end_game(g, 1);
		g->on_exit = 1;
		display_floor(g);
	}
	else if (g->on_exit == 0)
		display_floor(g);
	if (g->map[g->x][g->y + 1] == 'C')
		g->collected_c++;
	g->map[g->x][++g->y] = 'P';
	mlx_put_image_to_window(g->m, g->win, g->i.p, g->y * 64, g->x * 64);
}
