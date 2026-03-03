/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:58:23 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 18:58:25 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dump(char **str, int words)
{
	while (words > 0)
	{
		words--;
		free(str[words]);
	}
	free(str);
}

static void	free_textures(t_game *game)
{
	if (game->assets.east)
		free(game->assets.east);
	if (game->assets.west)
		free(game->assets.west);
	if (game->assets.north)
		free(game->assets.north);
	if (game->assets.south)
		free(game->assets.south);
	if (game->textures.e_wall.mlx_img)
		mlx_destroy_image(game->mlx, game->textures.e_wall.mlx_img);
	if (game->textures.n_wall.mlx_img)
		mlx_destroy_image(game->mlx, game->textures.n_wall.mlx_img);
	if (game->textures.s_wall.mlx_img)
		mlx_destroy_image(game->mlx, game->textures.s_wall.mlx_img);
	if (game->textures.w_wall.mlx_img)
		mlx_destroy_image(game->mlx, game->textures.w_wall.mlx_img);
}

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array && array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
		array = NULL;
	}
}

int	clean_exit(t_game *game)
{
	if (game)
	{
		free_textures(game);
		free_2d_array(game->map.array);
	}
	if (game->img.mlx_img)
	{
		mlx_destroy_image(game->mlx, game->img.mlx_img);
	}
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	exit(0);
	return (0);
}
