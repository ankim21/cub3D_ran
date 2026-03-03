/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:58:41 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/03/03 13:37:32 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_textures_data(t_game *game)
{
	game->textures.n_wall.addr = mlx_get_data_addr(game->textures.\
		n_wall.mlx_img, &game->textures.n_wall.bits_per_pixel,
			&game->textures.n_wall.line_len, &game->textures.n_wall.endian);
	game->textures.s_wall.addr = mlx_get_data_addr(game->textures.\
		s_wall.mlx_img, &game->textures.s_wall.bits_per_pixel,
			&game->textures.s_wall.line_len, &game->textures.s_wall.endian);
	game->textures.w_wall.addr = mlx_get_data_addr(game->textures.\
		w_wall.mlx_img, &game->textures.w_wall.bits_per_pixel,
			&game->textures.w_wall.line_len, &game->textures.w_wall.endian);
	game->textures.e_wall.addr = mlx_get_data_addr(game->textures.\
		e_wall.mlx_img, &game->textures.e_wall.bits_per_pixel,
			&game->textures.e_wall.line_len, &game->textures.e_wall.endian);
}

int	get_textures(t_game *game)
{
	int	height;
	int	width;

	game->textures.n_wall.mlx_img = \
		mlx_xpm_file_to_image(game->mlx, game->assets.north, &width, &height);
	if (!game->textures.n_wall.mlx_img)
		return (print_error(ERR_IMG_LOAD), 0);
	game->textures.s_wall.mlx_img = \
		mlx_xpm_file_to_image(game->mlx, game->assets.south, &width, &height);
	if (!game->textures.s_wall.mlx_img)
		return (print_error(ERR_IMG_LOAD), 0);
	game->textures.w_wall.mlx_img = \
		mlx_xpm_file_to_image(game->mlx, game->assets.west, &width, &height);
	if (!game->textures.w_wall.mlx_img)
		return (print_error(ERR_IMG_LOAD), 0);
	game->textures.e_wall.mlx_img = \
		mlx_xpm_file_to_image(game->mlx, game->assets.east, &width, &height);
	if (!game->textures.e_wall.mlx_img)
		return (print_error(ERR_IMG_LOAD), 0);
	init_textures_data(game);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;
	//create the game and initialize it all to 0
	// then parsing 1 for valid arguments
	// then parsing 2 for the file 
	// then launch mlx
	// if at any point it goes wrong, we clean the exit
	ft_memset(&game, 0, sizeof(game)); 
	if (!check_validity_args(ac, av[1]) || !check_validity_file(av[1], &game))
		clean_exit(&game);
	launch_mlx(&game);
	clean_exit(&game);
}
