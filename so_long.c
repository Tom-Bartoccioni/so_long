/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:09:27 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/13 18:11:09 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	ft_free_struct_and_exit(t_game *g)
{
	ft_free_tab(g->map);
	if (g->mlx)
		free(g->mlx);
	free(g);
	exit(0);
}

void	end_game(t_game *g, int victory)
{
	if (victory == 1)
	{
		ft_putstr("You WON !!!\n");
		mlx_loop_end(g->mlx);
	}
	else
	{
		ft_putstr("ESC pressed\nExiting\n");
		mlx_loop_end(g->mlx);
	}
}

void	start_game(t_game *g)
{
	g->i.width = 64;
	g->i.height = 64;
	g->collected_c = 0;
	g->on_exit = 0;
	g->total_move = 0;
	g->mlx = mlx_init();
	create_texture(g);
	g->win = mlx_new_window(g->mlx, 1920, 1080, "so_long tbartocc");
	mlx_put_image_to_window(g->mlx, g->win, g->i.b, 0, 0);
	display_map(g);
	mlx_hook(g->win, 2, 1L << 0, key_press, g);
	mlx_hook(g->win, 33, 1L << 17, mlx_loop_end, g->mlx);
	mlx_loop(g->mlx);
	destroy_images(g);
	mlx_destroy_window(g->mlx, g->win);
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
