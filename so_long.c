/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:09:27 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/10 15:19:01 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	ft_free_struct_and_exit(t_game *g)
{
	int	i;

	i = -1;
	while (g->map && g->map[++i])
		free(g->map[i]);
	free(g->map);
	if (g->mlx)
		free(g->mlx);
	if (g->mlx_win)
		free(g->mlx_win);
	free(g);
	exit(-1);
}

int	close_game(t_game *g)
{
	ft_printf("%p\n", g);
	mlx_destroy_image(g->mlx, g->i.p);
	mlx_destroy_window(g->mlx, g->mlx_win);
	ft_free_struct_and_exit(g);
	return (0);
}

void	create_texture(t_game *g)
{
	g->i.p = mlx_xpm_file_to_image(g->mlx,
			"./img/player.xpm", &g->i.width, &g->i.height);
	g->i.b = mlx_xpm_file_to_image(g->mlx,
			"./img/background.xpm", &g->i.width, &g->i.height);
}

void	start_game(t_game *g)
{
	g->mlx = mlx_init();
	create_texture(g);
	g->mlx_win = mlx_new_window(g->mlx, 1920, 1080, "so_long tbartocc");
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->i.b, 0, 0);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->i.p, 0, 0);
	mlx_hook(g->mlx_win, 2, 1L<<0, &close_game, &g);
	mlx_loop(g->mlx);
}

int	main(int ac, char **av)
{
	t_game	*g;

	if (ac != 2)
		return (ft_printf("Error: Invalid number of arguments\n"), -1);
	g = (t_game *)malloc(sizeof(t_game));
	g->map = parsing(av[1], g);
	if (!g->map)
		ft_free_struct_and_exit(g);
	start_game(g);
	free(g);
	return (0);
}
