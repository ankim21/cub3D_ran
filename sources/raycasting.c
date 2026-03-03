/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:58:50 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 18:58:52 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dda_algorithm(t_game *game)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map.array[game->ray.map_y][game->ray.map_x] == '1')
			hit = 1;
	}
}

int	raycasting(t_game *game)
{
	int	x;

	x = -1;
	game->assets.ceiling_color = get_int_color(game->assets.ceiling[0], \
		game->assets.ceiling[1], game->assets.ceiling[2]);
	game->assets.floor_color = get_int_color(game->assets.floor[0], \
		game->assets.floor[1], game->assets.floor[2]);
	set_floor_and_ceiling(game);
	while (++x < WINDOW_WIDTH)
	{
		init_raycasting(game, x);
		init_dda(game);
		dda_algorithm(game);
		init_value_to_draw(game);
		get_img_ready(game, x);
	}
	create_mini_map(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.mlx_img, 0, 0);
	return (0);
}

void	start_rendering(t_game *game)
{
	init_dir(game);
	init_plane(game);
	mlx_loop_hook(game->mlx, raycasting, game);
}
