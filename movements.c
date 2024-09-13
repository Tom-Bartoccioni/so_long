/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:23:24 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/13 18:25:01 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

int	key_press(int key_code, t_game *g)
{
	if (key_code == ESC_KEY)
		end_game(g, 0);
	else if (key_code == W_KEY || key_code == Z_KEY || key_code == UP_ARROW_KEY)
		move_up(g);
	else if (key_code == S_KEY || key_code == DOWN_ARROW_KEY)
		move_down(g);
	else if (key_code == A_KEY || key_code == Q_KEY || key_code == LEFT_ARROW_KEY)
		move_left(g);
	else if (key_code == D_KEY || key_code == RIGHT_ARROW_KEY)
		move_right(g);
	return (0);
}

void	move_up(t_game *g)
{
	if (g->map[g->x - 1][g->y] == '1')
		return ;
	if (g->on_exit == 1)
	{
		g->map[g->x][g->y] = 'E';
		mlx_put_image_to_window(g->mlx, g->win, g->i.e, g->y * 64, g->x * 64);
		g->on_exit = 0;
	}
	else if (g->map[g->x - 1][g->y] == 'E')
	{
		if (g->collected_c == g->total_c)
			end_game(g, 1);
		g->on_exit = 1;
		g->map[g->x][g->y] = '0';
		mlx_put_image_to_window(g->mlx, g->win, g->i.f, g->y * 64, g->x * 64);
	}
	else if (g->on_exit == 0)
	{
		g->map[g->x][g->y] = '0';
		mlx_put_image_to_window(g->mlx, g->win, g->i.f, g->y * 64, g->x * 64);
	}
	if (g->map[g->x - 1][g->y] == 'C')
		g->collected_c++;
	g->map[--g->x][g->y] = 'P';
	mlx_put_image_to_window(g->mlx, g->win, g->i.p, g->y * 64, g->x * 64);
	g->total_move++;
}

void	move_down(t_game *g)
{
	if (g->map[g->x + 1][g->y] == '1')
		return ;
	if (g->on_exit == 1)
	{
		g->map[g->x][g->y] = 'E';
		mlx_put_image_to_window(g->mlx, g->win, g->i.e, g->y * 64, g->x * 64);
		g->on_exit = 0;
	}
	else if (g->map[g->x + 1][g->y] == 'E')
	{
		if (g->collected_c == g->total_c)
			end_game(g, 1);
		g->on_exit = 1;
		g->map[g->x][g->y] = '0';
		mlx_put_image_to_window(g->mlx, g->win, g->i.f, g->y * 64, g->x * 64);
	}
	else if (g->on_exit == 0)
	{
		g->map[g->x][g->y] = '0';
		mlx_put_image_to_window(g->mlx, g->win, g->i.f, g->y * 64, g->x * 64);
	}
	if (g->map[g->x + 1][g->y] == 'C')
		g->collected_c++;
	g->map[++g->x][g->y] = 'P';
	mlx_put_image_to_window(g->mlx, g->win, g->i.p, g->y * 64, g->x * 64);
	g->total_move++;
}

void	move_left(t_game *g)
{
	if (g->map[g->x][g->y - 1] == '1')
		return ;
	if (g->on_exit == 1)
	{
		g->map[g->x][g->y] = 'E';
		mlx_put_image_to_window(g->mlx, g->win, g->i.e, g->y * 64, g->x * 64);
		g->on_exit = 0;
	}
	else if (g->map[g->x][g->y - 1] == 'E')
	{
		if (g->collected_c == g->total_c)
			end_game(g, 1);
		g->on_exit = 1;
		g->map[g->x][g->y] = '0';
		mlx_put_image_to_window(g->mlx, g->win, g->i.f, g->y * 64, g->x * 64);
	}
	else if (g->on_exit == 0)
	{
		g->map[g->x][g->y] = '0';
		mlx_put_image_to_window(g->mlx, g->win, g->i.f, g->y * 64, g->x * 64);
	}
	if (g->map[g->x][g->y - 1] == 'C')
		g->collected_c++;
	g->map[g->x][--g->y] = 'P';
	mlx_put_image_to_window(g->mlx, g->win, g->i.p, g->y * 64, g->x * 64);
	g->total_move++;
}

void	move_right(t_game *g)
{
	if (g->map[g->x][g->y + 1] == '1')
		return ;
	if (g->on_exit == 1)
	{
		g->map[g->x][g->y] = 'E';
		mlx_put_image_to_window(g->mlx, g->win, g->i.e, g->y * 64, g->x * 64);
		g->on_exit = 0;
	}
	else if (g->map[g->x][g->y + 1] == 'E')
	{
		if (g->collected_c == g->total_c)
			end_game(g, 1);
		g->on_exit = 1;
		g->map[g->x][g->y] = '0';
		mlx_put_image_to_window(g->mlx, g->win, g->i.f, g->y * 64, g->x * 64);
	}
	else if (g->on_exit == 0)
	{
		g->map[g->x][g->y] = '0';
		mlx_put_image_to_window(g->mlx, g->win, g->i.f, g->y * 64, g->x * 64);
	}
	if (g->map[g->x][g->y + 1] == 'C')
		g->collected_c++;
	g->map[g->x][++g->y] = 'P';
	mlx_put_image_to_window(g->mlx, g->win, g->i.p, g->y * 64, g->x * 64);
	g->total_move++;
}
