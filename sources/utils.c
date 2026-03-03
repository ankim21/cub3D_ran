/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankim <ankim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:59:08 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/03/03 14:08:30 by ankim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	open_fd(char *s, t_game *game)
{
	game->fd = open(s, O_RDONLY);
	if (game->fd <= 0) // nice check ! 
	{
		print_error(MAP_OPEN);
		clean_exit(game);
	}
}

char	*get_right_copy(t_game *game, int index, int start_map_cpy)
{
	char	*cpy;

	cpy = get_next_line(game->fd);
	// gets the first line of the doc
	if (start_map_cpy == 1 && (ft_strlen(cpy) == 1)) 
	{
		if (cpy)
			free(cpy);
		print_error(EMPTY_LINE);
		game->map.array[index + 1] = NULL;
		close(game->fd);
		clean_exit(game);
	}
	while (cpy && is_only_space(cpy)) // while copy is and is only whitespace 
	{
		free(cpy); // wouldn't this cause a free if the first line is empty ? 
		cpy = get_next_line(game->fd);
		game->map.start++; // why start? shouldn't it be pos ? 
	}
	return (cpy);
}

bool	on_color_line(char *s)
{
	if (ft_strcmp(s, "C") && ft_strcmp(s, "F"))
		return (FALSE);
	return (TRUE);
}

void	print_error(char *s)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}

int	get_int_color(int r, int g, int b)
{
	return ((r << 16 | g << 8 | b));
}
