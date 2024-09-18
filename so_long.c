/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:09:27 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/17 18:06:19 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	ft_free_struct_and_exit(t_game *g)
{
	ft_free_tab(g->map);
	if (g->m)
		free(g->m);
	free(g);
	exit(0);
}

void	end_game(t_game *g, int victory)
{
	if (victory == 1)
	{
		ft_printf("You won in %d moves !!!\n", g->total_move);
		mlx_loop_end(g->m);
	}
	else if (victory == 2)
	{
		ft_printf("You died :(\n", g->total_move);
		mlx_loop_end(g->m);
	}
	else
	{
		ft_putstr("ESC pressed\nExiting\n");
		mlx_loop_end(g->m);
	}
}

int	key_press(int key_code, t_game *g)
{
	if (key_code == ESC_KEY)
		end_game(g, 0);
	else if (key_code == W_KEY || key_code == Z_KEY || key_code == UP_KEY)
		move_up(g);
	else if (key_code == S_KEY || key_code == DOWN_KEY)
		move_down(g);
	else if (key_code == A_KEY || key_code == Q_KEY || key_code == LEFT_KEY)
		move_left(g);
	else if (key_code == D_KEY || key_code == RIGHT_KEY)
		move_right(g);
	return (0);
}

void	start_game(t_game *g)
{
	g->m = mlx_init();
	g->win = mlx_new_window(g->m, 1920, 1080, "so_long tbartocc");
	create_texture(g);
	mlx_put_image_to_window(g->m, g->win, g->i.b, 0, 0);
	display_map(g);
	mlx_hook(g->win, 2, 1L << 0, key_press, g);
	mlx_hook(g->win, 33, 1L << 17, mlx_loop_end, g->m);
	mlx_loop_hook(g->m, loop, g);
	mlx_loop(g->m);
	destroy_images(g);
	mlx_destroy_window(g->m, g->win);
	mlx_destroy_display(g->m);
	ft_free_struct_and_exit(g);
}

int	main(int ac, char **av)
{
	t_game	*g;

	if (ac != 2)
		return (ft_printf("Error: Invalid number of arguments\n"), -1);
	g = ft_calloc(1, sizeof(t_game));
	g->map = parsing(av[1], g);
	if (!g->map)
		ft_free_struct_and_exit(g);
	start_game(g);
	free(g);
	return (0);
}
