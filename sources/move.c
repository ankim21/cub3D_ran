/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:58:46 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 18:58:47 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->ray.pos_x + game->ray.dir_x * MOVESPEED;
	new_y = game->ray.pos_y + game->ray.dir_y * MOVESPEED;
	if (!game->map.array[(int)new_y][(int)new_x] || \
		ft_is_whitespace(game->map.array[(int)new_y][(int)new_x]))
		return ;
	if (game->map.array[(int)new_y][(int)new_x] == '1')
		return ;
	game->map.array[(int)game->ray.pos_y][(int)game->ray.pos_x] = '0';
	game->ray.pos_x = new_x;
	game->ray.pos_y = new_y;
	game->map.array[(int)game->ray.pos_y][(int)game->ray.pos_x] = \
		game->player.orientation;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->ray.pos_x - game->ray.dir_x * MOVESPEED;
	new_y = game->ray.pos_y - game->ray.dir_y * MOVESPEED;
	if (!game->map.array[(int)new_y][(int)new_x] || \
		ft_is_whitespace(game->map.array[(int)new_y][(int)new_x]))
		return ;
	if (game->map.array[(int)new_y][(int)new_x] == '1')
		return ;
	game->map.array[(int)game->ray.pos_y][(int)game->ray.pos_x] = '0';
	game->ray.pos_x = new_x;
	game->ray.pos_y = new_y;
	game->map.array[(int)game->ray.pos_y][(int)game->ray.pos_x] = \
		game->player.orientation;
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->ray.pos_x + game->ray.dir_y * MOVESPEED;
	new_y = game->ray.pos_y - game->ray.dir_x * MOVESPEED;
	if (!game->map.array[(int)new_y][(int)new_x] || \
		ft_is_whitespace(game->map.array[(int)new_y][(int)new_x]))
		return ;
	if (game->map.array[(int)new_y][(int)new_x] == '1')
		return ;
	game->map.array[(int)game->ray.pos_y][(int)game->ray.pos_x] = '0';
	game->ray.pos_x = new_x;
	game->ray.pos_y = new_y;
	game->map.array[(int)game->ray.pos_y][(int)game->ray.pos_x] = \
		game->player.orientation;
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->ray.pos_x - game->ray.dir_y * MOVESPEED;
	new_y = game->ray.pos_y + game->ray.dir_x * MOVESPEED;
	if (!game->map.array[(int)new_y][(int)new_x] || \
		ft_is_whitespace(game->map.array[(int)new_y][(int)new_x]))
		return ;
	if (game->map.array[(int)new_y][(int)new_x] == '1')
		return ;
	game->map.array[(int)game->ray.pos_y][(int)game->ray.pos_x] = '0';
	game->ray.pos_x = new_x;
	game->ray.pos_y = new_y;
	game->map.array[(int)game->ray.pos_y][(int)game->ray.pos_x] = \
		game->player.orientation;
}
